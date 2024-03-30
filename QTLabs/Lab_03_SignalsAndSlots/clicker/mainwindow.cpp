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

void MainWindow::on_pushButton_clicked() {
    static bool firstClick = true;
    ui->progressBar->setMaximum(ui->spinBox->value());
    ui->progressBar->setValue(ui->progressBar->value()+1);
    if (firstClick) {
        firstClick = false;
        ui->spinBox->setReadOnly(true);
    }
}

