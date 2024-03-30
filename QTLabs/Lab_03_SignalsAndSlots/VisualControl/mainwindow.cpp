#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if (arg1 == 0) {
        ui->pushButton->show();
    } else if (arg1 == 2) {
        ui->pushButton->hide();
    }
}


void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    if (arg1 == 0) {
        ui->pushButton_2->show();
    } else if (arg1 == 2) {
        ui->pushButton_2->hide();
    }
}


void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    if (arg1 == 0) {
        ui->pushButton_3->show();
    } else if (arg1 == 2) {
        ui->pushButton_3->hide();
    }
}


void MainWindow::on_checkBox_4_stateChanged(int arg1)
{
    if (arg1 == 0) {
        ui->pushButton_4->show();
    } else if (arg1 == 2) {
        ui->pushButton_4->hide();
    }
}


void MainWindow::on_checkBox_5_stateChanged(int arg1)
{
    if (arg1 == 0) {
        ui->pushButton_5->show();
    } else if (arg1 == 2) {
        ui->pushButton_5->hide();
    }
}

