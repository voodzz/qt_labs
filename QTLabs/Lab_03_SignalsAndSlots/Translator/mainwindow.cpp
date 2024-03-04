#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(slotTranslate()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(slotSwitch()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotTranslate()
{
    bool ok;
    if (ui->label->text() == "Decimal") {
        qint64 number = (ui->textEdit->toPlainText()).toLongLong(&ok, 10);
        QString result = QString::number(number, 16);
        ui->textEdit_2->setText(result.toUpper());
    } else if (ui->label->text() == "Hexadecimal") {
        qint64 number = (ui->textEdit->toPlainText()).toLongLong(&ok, 16);
        QString result = QString::number(number, 10);
        ui->textEdit_2->setText(result);
    }
}

void MainWindow::slotSwitch()
{
    QString tmp = ui->label->text();
    ui->label->setText(ui->label_2->text());
    ui->label_2->setText(tmp);
}
