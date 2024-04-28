#include <QString>
#include <QPainter>
#include <QPainterPath>
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget), scene_(new QGraphicsScene(this)) {
    this->setFixedSize(1706, 960);
    ui->setupUi(this);
    ui->graphicsView->setScene(scene_);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->lineEdit_7->setDisabled(true);
    ui->lineEdit_8->setDisabled(true);
    ui->lineEdit_17->setDisabled(true);

    drawAxes();
}

//void Widget::paintEvent(QPaintEvent *event) {}

Widget::~Widget() {
    delete ui;
}

void Widget::on_lineEdit_textChanged(const QString &arg1) {
    y_min = arg1.toDouble();
}

void Widget::on_lineEdit_2_textChanged(const QString &arg1) {
    y_max = arg1.toDouble();
}

void Widget::on_lineEdit_3_textChanged(const QString &arg1) {
    x_max = arg1.toDouble();
}

void Widget::on_lineEdit_4_textChanged(const QString &arg1) {
    x_min = arg1.toDouble();
}

void Widget::on_lineEdit_5_textChanged(const QString &arg1) {
    a_ = arg1.toDouble();
}

void Widget::on_lineEdit_6_textChanged(const QString &arg1) {
    b_ = arg1.toDouble();
}

void Widget::on_lineEdit_7_textChanged(const QString &arg1) {
    c_ = arg1.toDouble();
}

void Widget::on_lineEdit_8_textChanged(const QString &arg1) {
    d_ = arg1.toDouble();
}


void Widget::on_comboBox_currentIndexChanged(int index) {
    switch (index) {
    case 0:
        ui->lineEdit_5->setDisabled(false);
        ui->lineEdit_6->setDisabled(false);
        ui->lineEdit_7->setDisabled(true);
        ui->lineEdit_8->setDisabled(true);
        ui->lineEdit_17->setDisabled(true);
        break;
    case 1:
        ui->lineEdit_5->setDisabled(false);
        ui->lineEdit_6->setDisabled(false);
        ui->lineEdit_7->setDisabled(false);
        ui->lineEdit_8->setDisabled(true);
        ui->lineEdit_17->setDisabled(true);
        break;
    case 2:
        ui->lineEdit_5->setDisabled(false);
        ui->lineEdit_6->setDisabled(false);
        ui->lineEdit_7->setDisabled(false);
        ui->lineEdit_8->setDisabled(false);
        ui->lineEdit_17->setDisabled(true);
        break;
    case 3:
        ui->lineEdit_5->setDisabled(true);
        ui->lineEdit_6->setDisabled(true);
        ui->lineEdit_7->setDisabled(true);
        ui->lineEdit_8->setDisabled(true);
        ui->lineEdit_17->setDisabled(false);
        break;
    case 4:
        ui->lineEdit_5->setDisabled(false);
        ui->lineEdit_6->setDisabled(false);
        ui->lineEdit_7->setDisabled(true);
        ui->lineEdit_8->setDisabled(true);
        ui->lineEdit_17->setDisabled(true);
        break;
    case 5:
        ui->lineEdit_5->setDisabled(true);
        ui->lineEdit_6->setDisabled(true);
        ui->lineEdit_7->setDisabled(true);
        ui->lineEdit_8->setDisabled(true);
        ui->lineEdit_17->setDisabled(true);
        break;
    case 6:
        ui->lineEdit_5->setDisabled(false);
        ui->lineEdit_6->setDisabled(false);
        ui->lineEdit_7->setDisabled(false);
        ui->lineEdit_8->setDisabled(true);
        ui->lineEdit_17->setDisabled(true);
        break;
    default:
        break;
    }
}

void Widget::drawAxes() {
    int upperLeftCornerX = ui->graphicsView->x();
    int upperLeftCornerY = ui->graphicsView->y();

    int fieldWidth = ui->graphicsView->width()-5;
    int fieldHeight = ui->graphicsView->height()-5;

    pen_.setColor(Qt::lightGray);
    pen_.setWidth(1);
    // рисуем вертикальные линии сетки
    for (int x = upperLeftCornerX + fieldWidth/2 + 10; x <= upperLeftCornerX + fieldWidth; x += 10) {
        scene_->addLine(x, upperLeftCornerY, x, upperLeftCornerY + fieldHeight, pen_);
    }
    for (int x = upperLeftCornerX + fieldWidth/2 - 10; x >= upperLeftCornerX; x -= 10) {
        scene_->addLine(x, upperLeftCornerY, x, upperLeftCornerY + fieldHeight, pen_);
    }

    scene_->addLine(upperLeftCornerX + fieldWidth/2, upperLeftCornerY, upperLeftCornerX + fieldWidth/2, upperLeftCornerY + fieldHeight, pen_);
    scene_->addLine(upperLeftCornerX, upperLeftCornerY + fieldHeight/2, upperLeftCornerX + fieldWidth, upperLeftCornerY + fieldHeight/2, pen_);

    // рисуем горизонтальные линии сетки
    for (int y = upperLeftCornerY + fieldHeight/2 + 10; y <= upperLeftCornerY + fieldHeight; y += 10) {
        scene_->addLine(upperLeftCornerX, y, upperLeftCornerX + fieldWidth, y, pen_);
    }
    for (int y = upperLeftCornerY + fieldHeight/2 - 10; y >= upperLeftCornerY; y -= 10) {
        scene_->addLine(upperLeftCornerX, y, upperLeftCornerX + fieldWidth, y, pen_);
    }

    pen_.setColor(Qt::black);
    // рисуем оси
    scene_->addLine(upperLeftCornerX, upperLeftCornerY + fieldHeight/2, upperLeftCornerX + fieldWidth, upperLeftCornerY + fieldHeight/2, pen_); // x axis
    scene_->addLine(upperLeftCornerX + fieldWidth/2, upperLeftCornerY, upperLeftCornerX + fieldWidth/2, upperLeftCornerY + fieldHeight, pen_); // y axis

    // рисуем стрелочки на ось x
    scene_->addLine(upperLeftCornerX + fieldWidth - 7, upperLeftCornerY + fieldHeight/2 + 5, upperLeftCornerX + fieldWidth, upperLeftCornerY + fieldHeight/2, pen_);
    scene_->addLine(upperLeftCornerX + fieldWidth - 7, upperLeftCornerY + fieldHeight/2 - 5, upperLeftCornerX + fieldWidth, upperLeftCornerY + fieldHeight/2, pen_);

    // рисуем стрелочки на ось y
    scene_->addLine(upperLeftCornerX + fieldWidth/2 - 5, upperLeftCornerY + 7, upperLeftCornerX + fieldWidth/2, upperLeftCornerY, pen_);
    scene_->addLine(upperLeftCornerX + fieldWidth/2 + 5, upperLeftCornerY + 7, upperLeftCornerX + fieldWidth/2, upperLeftCornerY, pen_);
}

