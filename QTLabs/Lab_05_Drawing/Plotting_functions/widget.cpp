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
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    drawCoordNetAndAxes();
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

void Widget::on_lineEdit_4_textChanged(const QString &arg1) {
    x_max = arg1.toDouble();
}

void Widget::on_lineEdit_3_textChanged(const QString &arg1) {
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

void Widget::on_lineEdit_17_textChanged(const QString &arg1) {
    r_ = arg1.toDouble();
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

void Widget::drawCoordNetAndAxes() {
    qreal fieldWidth = ui->graphicsView->width();
    qreal fieldHeight = ui->graphicsView->height();

    pen_.setColor(Qt::lightGray);
    pen_.setWidth(1);

    // рисуем вертикальные линии сетки
    for (qreal x = fieldWidth/2.0 + 10; x <= fieldWidth; x += 10) {
        scene_->addLine(x, 0, x, fieldHeight, pen_);
    }
    for (qreal x = fieldWidth/2.0 - 10; x >= 0; x -= 10) {
        scene_->addLine(x, 0, x, fieldHeight, pen_);
    }

    scene_->addLine(fieldWidth/2, 0, fieldWidth/2, fieldHeight, pen_);
    scene_->addLine(0, fieldHeight/2, fieldWidth, fieldHeight/2, pen_);

    // рисуем горизонтальные линии сетки
    for (qreal y = fieldHeight/2 + 10; y <= fieldHeight; y += 10) {
        scene_->addLine(0, y, fieldWidth, y, pen_);
    }
    for (int y = fieldHeight/2 - 10; y >= 0; y -= 10) {
        scene_->addLine(0, y, fieldWidth, y, pen_);
    }

    pen_.setColor(Qt::black);
    // рисуем оси
    scene_->addLine(0, fieldHeight/2.0, fieldWidth, fieldHeight/2.0, pen_); // x axis
    scene_->addLine(fieldWidth/2.0, 0, fieldWidth/2.0, fieldHeight, pen_); // y axis

    // рисуем стрелочки на ось x
    scene_->addLine(fieldWidth - 7, fieldHeight/2 + 5, fieldWidth, fieldHeight/2.0, pen_);
    scene_->addLine(fieldWidth - 7, fieldHeight/2 - 5, fieldWidth, fieldHeight/2.0, pen_);

    // рисуем стрелочки на ось y
    scene_->addLine(fieldWidth/2 - 5,  7, fieldWidth/2.0, 0, pen_);
    scene_->addLine(fieldWidth/2 + 5, 7, fieldWidth/2.0, 0, pen_);

}

void Widget::drawGraph() {
    int index = ui->comboBox->currentIndex();
    int colorIndex = ui->comboBox_2->currentIndex();

    switch (colorIndex) {
    case 0:
        pen_.setColor(Qt::red);
        break;
    case 1:
        pen_.setColor(Qt::green);
        break;
    case 2:
        pen_.setColor(Qt::blue);
        break;
    case 3:
        pen_.setColor(Qt::cyan);
        break;
    case 4:
        pen_.setColor(Qt::magenta);
        break;
    case 5:
        pen_.setColor(Qt::yellow);
        break;
    default:
        break;
    }

    qreal fieldWidth = ui->graphicsView->width();
    qreal fieldHeight = ui->graphicsView->height();

    QTransform transform;
    transform.translate(fieldWidth/2.0, fieldHeight/2.0); // перемещаем начало координат в середину
    transform.scale(10, -10); // "переворачиваем" ось y и умнажем на выбранный парамметр

    switch (index) {
    case 0: {
        qreal x1 = x_min;
        qreal y1 = a_ * x1 + b_;

        qreal x2 = x_max;
        qreal y2 = a_ * x2 + b_;

        if (y1 < y_min) {
            y1 = y_min;
            x1 = (y1 - b_)/a_;
        }
        if (y1 >y_max) {
            y1 = y_max;
            x1 = (y1 - b_)/a_;
        }
        if (y2< y_min) {
            y2 = y_min;
            x2 = (y2 - b_)/a_;
        }
        if (y2 > y_max) {
            y2 = y_max;
            x2 = (y2 - b_)/a_;
        }

        QPointF p1 = transform.map(QPointF(x1, y1));
        QPointF p2 = transform.map(QPointF(x2, y2));

        scene_->addLine(p1.x(), p1.y(), p2.x(), p2.y(), pen_);
        break;
    }
    case 3: {
        QPointF topLeft = transform.map(QPointF(-r_, r_));
        QPointF topRight = transform.map(QPointF(r_, -r_));

        scene_->addEllipse(QRectF(topLeft, topRight), pen_, Qt::NoBrush);
        break;
    }
    case 4: {
        QPointF topLeft = transform.map(QPointF(-a_, b_));
        QPointF topRight = transform.map(QPointF(a_, -b_));

        scene_->addEllipse(QRectF(topLeft, topRight), pen_, Qt::NoBrush);
        break;
    }
    }
}


void Widget::on_pushButton_clicked() {
    scene_->clear();
    drawCoordNetAndAxes();
    drawGraph();
}



