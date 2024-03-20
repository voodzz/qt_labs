#include <QStyleOption>
#include "widget.h"
#include "ui_widget.h"
#include "stylehelper.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    setInterfaceStyle();
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
    ui->startButton->setStyleSheet(StyleHelper::getStartButtonsStyle());
    ui->leftButton->setStyleSheet(StyleHelper::getLeftButtonActiveStyle());
    ui->rightButton->setStyleSheet(StyleHelper::getRightButtonStyle());
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

void Widget::on_leftButton_clicked() {
    changeButtonStatus(1);
}


void Widget::on_rightButton_clicked() {
    changeButtonStatus(2);
}

