#include <QRandomGenerator>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle("Убегающая кнопка");

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(changeColor()));
    ui->pushButton->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hovered()
{
    int newX = QRandomGenerator::global()->bounded(0, width() - ui->pushButton->width());
    int newY = QRandomGenerator::global()->bounded(0, height() - ui->pushButton->height());
    ui->pushButton->move(newX, newY);
}

void MainWindow::changeColor()
{
    QColor color = QColor::fromRgb(QRandomGenerator::global()->bounded(256),
                                   QRandomGenerator::global()->bounded(256),
                                   QRandomGenerator::global()->bounded(256));
    QString style = QString("background-color: %1").arg(color.name());
    ui->pushButton->setStyleSheet(style);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->pushButton && event->type() == QEvent::Enter) {
        hovered();
    }
    return QMainWindow::eventFilter(obj, event);
}
