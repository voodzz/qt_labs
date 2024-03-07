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
    connect(ui->comboBox, SIGNAL(activated(int)), this, SLOT(slotConvertTextEdit_2()));
    connect(ui->comboBox_2, SIGNAL(activated(int)), this, SLOT(slotConvertTextEdit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotConvertTextEdit() {
    ui->textEdit_2->blockSignals(true);
    QString input = ui->comboBox->currentText();
    QString output = ui->comboBox_2->currentText();
    int inputNumeralSystem = 0;
    int outputNumeralSystem = 0;

    if (input == "Binary") {
        inputNumeralSystem = 2;
    } else if (input == "Octal") {
        inputNumeralSystem = 8;
    } else if (input == "Decimal") {
        inputNumeralSystem = 10;
    } else if (input == "Hexadecimal") {
        inputNumeralSystem = 16;
    }

    if (output == "Binary") {
        outputNumeralSystem = 2;
    } else if (output == "Octal") {
        outputNumeralSystem = 8;
    } else if (output == "Decimal") {
        outputNumeralSystem = 10;
    } else if (output == "Hexadecimal") {
        outputNumeralSystem = 16;
    }

    bool ok;
    qint64 number = (ui->textEdit->toPlainText()).toLongLong(&ok, inputNumeralSystem);
    QString result = QString::number(number, outputNumeralSystem);
    ui->textEdit_2->setText(result);
    ui->textEdit_2->blockSignals(false);
}

void MainWindow::slotConvertTextEdit_2() {
    ui->textEdit->blockSignals(true);

    QString input = ui->comboBox_2->currentText();
    QString output = ui->comboBox->currentText();
    int inputNumeralSystem = 0;
    int outputNumeralSystem = 0;

    if (input == "Binary") {
        inputNumeralSystem = 2;
    } else if (input == "Octal") {
        inputNumeralSystem = 8;
    } else if (input == "Decimal") {
        inputNumeralSystem = 10;
    } else if (input == "Hexadecimal") {
        inputNumeralSystem = 16;
    }

    if (output == "Binary") {
        outputNumeralSystem = 2;
    } else if (output == "Octal") {
        outputNumeralSystem = 8;
    } else if (output == "Decimal") {
        outputNumeralSystem = 10;
    } else if (output == "Hexadecimal") {
        outputNumeralSystem = 16;
    }

    bool ok;
    qint64 number = (ui->textEdit_2->toPlainText()).toLongLong(&ok, inputNumeralSystem);
    QString result = QString::number(number, outputNumeralSystem);
    ui->textEdit->setText(result);
    ui->textEdit->blockSignals(false);
}
