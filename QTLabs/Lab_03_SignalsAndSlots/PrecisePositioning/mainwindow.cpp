#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->move(ui->horizontalSlider->value(),ui->verticalSlider->value());
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &MainWindow::updateButtonPosition);
    connect(ui->verticalSlider, &QSlider::valueChanged, this, &MainWindow::updateButtonPosition);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateButtonPosition() {
    int x = ui->horizontalSlider->value();
    int y = ui->verticalSlider->value();
    ui->pushButton->move(x*6.8, y*4.8);

}
