#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QColor>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_colorsButton_clicked() {
    QColor color=QColorDialog::getColor(Qt::gray,this);

}

