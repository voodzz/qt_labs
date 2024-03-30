#include <QStyleOption>
#include <QGridLayout>
#include <QDebug>
#include "widget.h"
#include "ui_widget.h"
#include "stylehelper.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    setInterfaceStyle();
    configurateGameAreaButtons();
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::onComputerSlot);
}

Widget::~Widget() {
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event) {
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}

void Widget::setInterfaceStyle() {
    this->setStyleSheet(StyleHelper::getMainWidgetStyle());
    ui->groupBox->setStyleSheet(StyleHelper::getGroupBoxStyle());
    ui->startButton->setStyleSheet(StyleHelper::getStartButtonsStyle());
    ui->leftButton->setStyleSheet(StyleHelper::getLeftButtonActiveStyle());
    ui->rightButton->setStyleSheet(StyleHelper::getRightButtonStyle());

    setGameAreaButtonStyle();
    ui->messageLabel->setText("You're playing O");
    ui->messageLabel->setStyleSheet(StyleHelper::getNormalMessageStyle());
}

void Widget::changeButtonStatus(int num) {
    if (num == 1) {
        ui->leftButton->setStyleSheet(StyleHelper::getLeftButtonActiveStyle());
        ui->rightButton->setStyleSheet(StyleHelper::getRightButtonStyle());
    } else {
        ui->leftButton->setStyleSheet(StyleHelper::getLeftButtonStyle());
        ui->rightButton->setStyleSheet(StyleHelper::getRightButtonActiveStyle());
    }
}

void Widget::changeButtonStyle(int row, int column, QString style) {
    QGridLayout* grid = qobject_cast<QGridLayout*>(ui->groupBox->layout());
    QPushButton *btn = qobject_cast<QPushButton*>(grid->itemAtPosition(row, column)->widget());
    btn->setStyleSheet(style);
}

void Widget::configurateGameAreaButtons() {
    QGridLayout* grid = qobject_cast<QGridLayout*>(ui->groupBox->layout());
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            QPushButton *btn = qobject_cast<QPushButton*>(grid->itemAtPosition(row, column)->widget());
            btn->setProperty("row", row);
            btn->setProperty("column", column);
            connect(btn, &QPushButton::clicked, this, &Widget::onGameAreaButtonClicked);
        }
    }
}

void Widget::setGameAreaButtonStyle() {
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            changeButtonStyle(row, column, StyleHelper::getBlankButtonStyle());
        }
    }
}

void Widget::setWinLossSquareStyle(int row, int column, char symbol) {
    switch (symbol) {
    case 'X':
        if (winner == player) {
            changeButtonStyle(row, column, StyleHelper::getCrossVictoryStyle());
        } else {
            changeButtonStyle(row, column, StyleHelper::getCrossLossStyle());
        }
        break;
    case '0':
        if (winner == player) {
            changeButtonStyle(row, column, StyleHelper::getCircleVictoryStyle());
        } else {
            changeButtonStyle(row, column, StyleHelper::getCircleLossStyle());
        }
        break;
    default:
        break;
    }
}

void Widget::start() {
    setGameAreaButtonStyle();
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            gameArea[row][column] = '-';
        }
    }
    progress = 0;
    gameStarted = true;
    stop = false;
    if (player != 'X') {
        computerInGame();
    }
}

void Widget::lockPlayer() {
    if (player == 'X') {
        playerLocked = false;
    } else {
        playerLocked = true;
    }
}


void Widget::on_leftButton_clicked() {
    changeButtonStatus(1);
    ui->messageLabel->setStyleSheet(StyleHelper::getNormalMessageStyle());
    ui->messageLabel->setText("You're playing O");
    player = '0';
}


void Widget::on_rightButton_clicked() {
    changeButtonStatus(2);
    ui->messageLabel->setStyleSheet(StyleHelper::getNormalMessageStyle());
    ui->messageLabel->setText("You're playing X");
    player = 'X';
}


void Widget::on_startButton_clicked() {
    if (gameStarted) {
        playerLocked = true;
        ui->startButton->setText("Play");
        ui->startButton->setStyleSheet(StyleHelper::getStartButtonsStyle());
        ui->leftButton->setDisabled(false);
        ui->rightButton->setDisabled(false);
        gameStarted = false;
        ui->messageLabel->setText("Lost");
        ui->messageLabel->setStyleSheet(StyleHelper::getLossMessageStyle());
    } else {
        ui->messageLabel->setText("Game is going");
        ui->messageLabel->setStyleSheet(StyleHelper::getNormalMessageStyle());
        start();
        lockPlayer();
        ui->startButton->setText("Surrender");
        ui->startButton->setStyleSheet(StyleHelper::getStartButtonsStyle());
        ui->leftButton->setDisabled(true);
        ui->rightButton->setDisabled(true);
    }
}

void Widget::onGameAreaButtonClicked() {
    if (!playerLocked) {
        QPushButton *btn = qobject_cast<QPushButton*>(sender());
        int row = btn->property("row").toInt();
        int column = btn->property("column").toInt();
        if (gameArea[row][column] == '-') {
            QString style;
            if (player == 'X') {
                style = StyleHelper::getCrossNormalStyle();
                gameArea[row][column] = 'X';
            } else {
                style = StyleHelper::getCircleNormalStyle();
                gameArea[row][column] = '0';
            }
            changeButtonStyle(row, column, style);
            playerLocked = true;
            ++progress;
            checkGameStop();
            endGame();
            computerInGame();
        } else {
            return;
        }
    }
}

void Widget::computerInGame() {
    if (stop) {
        return;
    }
    ui->messageLabel->setText("Computer's thinking");
    timer->start(800);
}

void Widget::checkGameStop() {
    winner = '-';
    char symbols[2] = {'X', '0'};
    for (int i = 0; i < 2; ++i) {
        for (int row = 0; row < 3; ++row) {
            if ((gameArea[row][0] == symbols[i]) && (gameArea[row][1] == symbols[i]) && (gameArea[row][2] == symbols[i])) {
                stop = true;
                winner = symbols[i];
                char symbol = symbols[i];
                setWinLossSquareStyle(row, 0, symbol);
                setWinLossSquareStyle(row, 1, symbol);
                setWinLossSquareStyle(row, 2, symbol);
                return;
            }
        }
        for (int column = 0; column < 3; ++column) {
            if (gameArea[0][column] == symbols[i] && gameArea[1][column] == symbols[i] && gameArea[2][column] == symbols[i]) {
                stop = true;
                winner = symbols[i];
                char symbol = symbols[i];
                setWinLossSquareStyle(0, column, symbol);
                setWinLossSquareStyle(1, column, symbol);
                setWinLossSquareStyle(2, column, symbol);
                return;
            }
        }
        if (gameArea[0][0] == symbols[i] && gameArea[1][1] == symbols[i] && gameArea[2][2] == symbols[i]) {
            stop = true;
            winner = symbols[i];
            char symbol = symbols[i];
            setWinLossSquareStyle(0, 0, symbol);
            setWinLossSquareStyle(1, 1, symbol);
            setWinLossSquareStyle(2, 2, symbol);
            return;
        }
        if (gameArea[0][2] == symbols[i] && gameArea[1][1] == symbols[i] && gameArea[2][0] == symbols[i]) {
            stop = true;
            winner = symbols[i];
            char symbol = symbols[i];
            setWinLossSquareStyle(0, 2, symbol);
            setWinLossSquareStyle(1, 1, symbol);
            setWinLossSquareStyle(2, 0, symbol);
            return;
        }
    }
    if (progress == 9) {
        stop = true;

    }
}

void Widget::endGame() {
    if (stop) {
        if (winner == player) {
            ui->messageLabel->setText("Victory");
            ui->messageLabel->setStyleSheet(StyleHelper::getWinMessageStyle());
        } else if (winner == '-') {
            ui->messageLabel->setText("Draw");
            ui->messageLabel->setStyleSheet(StyleHelper::getDrawMessageStyle());
        } else {
            ui->messageLabel->setText("Loss");
            ui->messageLabel->setStyleSheet(StyleHelper::getLossMessageStyle());
        }
        playerLocked = true;
        gameStarted = false;
        ui->startButton->setText("Play");
        ui->startButton->setStyleSheet(StyleHelper::getStartButtonsStyle());
        ui->leftButton->setDisabled(false);
        ui->rightButton->setDisabled(false);
    }
}

void Widget::onComputerSlot() {
    char computer;
    QString style;
    if (player == 'X') {
        computer = '0';
        style = StyleHelper::getCircleNormalStyle();
        ++progress;
    } else {
        computer = 'X';
        style = StyleHelper::getCrossNormalStyle();
        ++progress;
    }
    timer->stop();
    while(true) {
        int row = rand()%3;
        int column = rand()%3;
        if (gameArea[row][column] == '-') {
                gameArea[row][column] = computer;
                changeButtonStyle(row, column, style);
                ui->messageLabel->setText("Your move");
                checkGameStop();
                endGame();
                playerLocked = false;
                break;
        }
    }
}
