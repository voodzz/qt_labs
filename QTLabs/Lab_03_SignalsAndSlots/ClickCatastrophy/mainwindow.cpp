#include <QKeyEvent>
#include <QLabel>
#include <QRandomGenerator>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setWindowTitle("Катастрофа");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)    {
        if (event->key() == Qt::Key_Space) {
            for (auto& label : labels) {
                label->setText("ой!");
            }
        }
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    QLabel* label = new QLabel("щелчок", this);
    label->move(QPoint(QRandomGenerator::global()->bounded(width() - 50),
                       QRandomGenerator::global()->bounded(height() - 50)));
    label->show();
    labels.push_back(label);
}
