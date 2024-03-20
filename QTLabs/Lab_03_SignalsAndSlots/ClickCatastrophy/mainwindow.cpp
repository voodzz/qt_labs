#include <QKeyEvent>
#include <QLabel>
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
    labels.push_back(label);
}


// bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
//     if (obj == ui->centralwidget && event->type() == QEvent::KeyPress) {
//     } else if (obj == ui->centralwidget && event->type() == QEvent::MouseButtonPress) {
//         createLabel();
//     }
//     return QMainWindow::eventFilter(obj, event);
// }

// void MainWindow::changeText() {
//     for (auto& label : labels) {
//         label->setText("ой!");
//     }
// }

// void MainWindow::createLabel() {
//    QLabel* label = new QLabel("щелчок", this);
//     labels.push_back(label);
// }
