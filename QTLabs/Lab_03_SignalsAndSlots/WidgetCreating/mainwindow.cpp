#include <QRandomGenerator>
#include <QLabel>
#include <QTextEdit>
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
    if (ui->comboBox->currentText() == "button") {
        for (int i = 0;  i != ui->spinBox->value(); ++i) {
            QPushButton* buttn = new QPushButton("button", this);
            buttn->move(QPoint(QRandomGenerator::global()->bounded(ui->centralwidget->width() - 50),
                                QRandomGenerator::global()->bounded(ui->centralwidget->height()-200)));
            buttn->show();
        }
    } else if (ui->comboBox->currentText() == "label") {
        for (int i = 0;  i != ui->spinBox->value(); ++i) {
            QLabel* label = new QLabel("label -_-", this);
            label->move(QPoint(QRandomGenerator::global()->bounded(ui->centralwidget->width()-50),
                               QRandomGenerator::global()->bounded(ui->centralwidget->height()-200)));
            label->show();
        }
    } else if (ui->comboBox->currentText() == "textEdit") {
        for (int i = 0;  i != ui->spinBox->value(); ++i) {
            QTextEdit* textEdit = new QTextEdit("textEdit", this);
            textEdit->move(QPoint(QRandomGenerator::global()->bounded(ui->centralwidget->width()-50),
                                  QRandomGenerator::global()->bounded(ui->centralwidget->height()-200)));
            textEdit->show();
        }
    }
}

