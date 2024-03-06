#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(slotConvertTextEdit()));
    connect(ui->textEdit_2, SIGNAL(textChanged()), this, SLOT(slotConvertTextEdit_2()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotConvertTextEdit() {
    ui->textEdit_2->blockSignals(true);
    bool ok;
    qint64 number = (ui->textEdit->toPlainText()).toLongLong(&ok, 10);
    QString result = QString::number(number, 2);
    ui->textEdit_2->setText(result.toUpper());
    ui->textEdit_2->blockSignals(false);
}

void MainWindow::slotConvertTextEdit_2() {
    ui->textEdit->blockSignals(true);
    bool ok;
    qint64 number = (ui->textEdit_2->toPlainText()).toLongLong(&ok, 2);
    QString result = QString::number(number, 10);
    ui->textEdit->setText(result);
    ui->textEdit->blockSignals(false);
}
