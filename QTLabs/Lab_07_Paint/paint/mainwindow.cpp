#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QColor>
#include <QFileDialog>
#include <QMessageBox>
#include <QImageWriter>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow), scene_(new QGraphicsScene) {
    ui->setupUi(this);
    ui->graphicsView->setScene(scene_);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_colorsButton_clicked() {
    QColor color = QColorDialog::getColor(Qt::gray,this);
    if (ui->firstColorButton->isChecked()) {
        ui->firstColorButton->setStyleSheet("QPushButton {"
                                            "background-color:" + color.name() + ";"
                                            "border: none;"
                                            "};");
    } else if (ui->secondColorButton->isChecked()) {
        ui->secondColorButton->setStyleSheet("QPushButton {"
                                             "background-color:" + color.name() + ";"
                                             "border: none;"
                                             "};");
    }
}

void MainWindow::on_openAction_triggered() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    if (!fileName.isEmpty()) {
        QImage image;
        if (image.load(fileName)) {
            scene_->clear();
            scene_->addPixmap(QPixmap::fromImage(image));
            currentFile_ = fileName;
        } else {
            QMessageBox::warning(this, tr("Open Image"), tr("Could not open file."));
        }
    }
}

void MainWindow::on_newAction_triggered() {
    scene_->clear();
    currentFile_.clear();
}

void MainWindow::on_firstColorButton_clicked() {
    ui->secondColorButton->setChecked(false);
    ui->label_4->setStyleSheet("QLabel {"
                               "background-color: #96c7e3;"
                               "};");
    ui->label_5->setStyleSheet("QLabel {"
                               "background-color: none;"
                               "};");
}

void MainWindow::on_secondColorButton_clicked() {
    ui->firstColorButton->setChecked(false);
    ui->label_5->setStyleSheet("QLabel {"
                               "background-color: #96c7e3;"
                               "};");
    ui->label_4->setStyleSheet("QLabel {"
                               "background-color: none;"
                               "};");
}

void MainWindow::on_blackButton_clicked() {
    if (ui->firstColorButton->isChecked()) {
        ui->firstColorButton->setStyleSheet("QPushButton {"
                                            "background-color: rgb(0, 0, 0);"
                                            "border: none;"
                                            "}");
    } else if (ui->secondColorButton->isChecked()) {
        ui->secondColorButton->setStyleSheet("QPushButton {"
                                             "background-color: rgb(0, 0, 0);"
                                             "border: none;"
                                             "}");
    }
}

void MainWindow::on_greyButton_clicked() {
    if (ui->firstColorButton->isChecked()) {
        ui->firstColorButton->setStyleSheet("QPushButton {"
                                            "background-color: rgb(120, 120, 120);"
                                            "border: none;"
                                            "}");
    } else if (ui->secondColorButton->isChecked()) {
        ui->secondColorButton->setStyleSheet("QPushButton {"
                                             "background-color: rgb(120, 120, 120);"
                                             "border: none;"
                                             "}");
    }
}

void MainWindow::on_darkRedButton_clicked() {
    if (ui->firstColorButton->isChecked()) {
        ui->firstColorButton->setStyleSheet("QPushButton {"
                                            "background-color: rgb(136, 0, 21);"
                                            "border: none;"
                                            "}");
    } else if (ui->secondColorButton->isChecked()) {
        ui->secondColorButton->setStyleSheet("QPushButton {"
                                             "background-color: rgb(136, 0, 21);"
                                             "border: none;"
                                             "}");
    }
}

void MainWindow::on_redButton_clicked() {
    if (ui->firstColorButton->isChecked()) {
        ui->firstColorButton->setStyleSheet("QPushButton {"
                                            "background-color: rgb(237, 28, 36);"
                                            "border: none;"
                                            "}");
    } else if (ui->secondColorButton->isChecked()) {
        ui->secondColorButton->setStyleSheet("QPushButton {"
                                             "background-color: rgb(237, 28, 36);"
                                             "border: none;"
                                             "}");
    }
}

void MainWindow::on_orangeButton_clicked() {
    if (ui->firstColorButton->isChecked()) {
        ui->firstColorButton->setStyleSheet("QPushButton {"
                                            "background-color: rgb(255, 127, 39);"
                                            "border: none;"
                                            "}");
    } else if (ui->secondColorButton->isChecked()) {
        ui->secondColorButton->setStyleSheet("QPushButton {"
                                             "background-color: rgb(255, 127, 39);"
                                             "border: none;"
                                             "}");
    }
}

void MainWindow::on_yellowButton_clicked() {
    if (ui->firstColorButton->isChecked()) {
        ui->firstColorButton->setStyleSheet("QPushButton {"
                                            "background-color: rgb(255, 242, 2);"
                                            "border: none;"
                                            "}");
    } else if (ui->secondColorButton->isChecked()) {
        ui->secondColorButton->setStyleSheet("QPushButton {"
                                             "background-color: rgb(255, 242, 2);"
                                             "border: none;"
                                             "}");
    }
}

void MainWindow::on_greenButton_clicked() {
    if (ui->firstColorButton->isChecked()) {
        ui->firstColorButton->setStyleSheet("QPushButton {"
                                            "background-color: rgb(34, 177, 76);"
                                            "border: none;"
                                            "}");
    } else if (ui->secondColorButton->isChecked()) {
        ui->secondColorButton->setStyleSheet("QPushButton {"
                                             "background-color: rgb(34, 177, 76);"
                                             "border: none;"
                                             "}");
    }
}

void MainWindow::on_blueButton_clicked() {
    if (ui->firstColorButton->isChecked()) {
        ui->firstColorButton->setStyleSheet("QPushButton {"
                                            "background-color: rgb(0, 162, 232);"
                                            "border: none;"
                                            "}");
    } else if (ui->secondColorButton->isChecked()) {
        ui->secondColorButton->setStyleSheet("QPushButton {"
                                             "background-color: rgb(0, 162, 232);"
                                             "border: none;"
                                             "}");
    }
}

void MainWindow::on_indigoButton_clicked() {
    if (ui->firstColorButton->isChecked()) {
        ui->firstColorButton->setStyleSheet("QPushButton {"
                                            "background-color: rgb(63, 72, 204);"
                                            "border: none;"
                                            "}");
    } else if (ui->secondColorButton->isChecked()) {
        ui->secondColorButton->setStyleSheet("QPushButton {"
                                             "background-color: rgb(63, 72, 204);"
                                             "border: none;"
                                             "}");
    }
}

void MainWindow::on_purpleButton_clicked() {
    if (ui->firstColorButton->isChecked()) {
        ui->firstColorButton->setStyleSheet("QPushButton {"
                                            "background-color: rgb(163, 73, 164);"
                                            "border: none;"
                                            "}");
    } else if (ui->secondColorButton->isChecked()) {
        ui->secondColorButton->setStyleSheet("QPushButton {"
                                             "background-color: rgb(163, 73, 164);"
                                             "border: none;"
                                             "}");
    }
}

void MainWindow::on_saveAsAction_triggered() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image As"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    if (!fileName.isEmpty()) {
        currentFile_ = fileName;
        on_saveAction_triggered();
    }
}

void MainWindow::on_saveAction_triggered() {
    if (currentFile_.isEmpty()) {
        on_saveAsAction_triggered();
    } else {
        QImage image(scene_->sceneRect().size().toSize(), QImage::Format_ARGB32);
        image.fill(Qt::transparent);
        QPainter painter(&image);
        scene_->render(&painter);
        if (!image.save(currentFile_)) {
            QMessageBox::warning(this, tr("Save Image"), tr("Could not save file."));
        }
    }
}


void MainWindow::on_actionUndo_triggered() {

}

