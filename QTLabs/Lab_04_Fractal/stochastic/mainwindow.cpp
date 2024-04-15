#include <QtMath>
#include <QRandomGenerator>
#include <QPainter>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    int w = this->width();
    int h = this->height();
    int n_ = qCeil(std::log2(qMax(w ,h) - 1));
    dots_ = qPow(2, n_) + 1;
    plazma_.resize(dots_);
    for (auto& i : plazma_) {
        i.resize(dots_);
        for (auto& item : i) {
            /* Initialize all the dots with light gray/white/gray (but the first one is better) because if you
             * are kind of like The Rolling Stones and you think
             * "I wanna see it painted, painted black" (by that I mean nullptr, which is equal to black)
             * it simply won't work the way it's supposed to (by the way, I don't know why ¯\_(ツ)_/¯). The same is with other colors*/
            item = QColor(Qt::lightGray);
        }
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::dotsColorInitialization() {
    plazma_[0][0] = QColor(Qt::red);
    plazma_[dots_ - 1][0] = QColor(Qt::green);
    plazma_[0][dots_ - 1] = QColor(Qt::blue);
    plazma_[dots_ - 1][dots_ - 1] = QColor(Qt::yellow);

    // Call fillPlazma() to generate the plasma pattern
    fillPlazma(0, 0, dots_ - 1, dots_ - 1);
}

void MainWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);

    dotsColorInitialization();

    // Draw points
    for (int x = 0; x != plazma_.size(); ++x) {
        for (int y = 0; y != plazma_[x].size(); ++y) {
            painter.setPen(QPen(plazma_[x][y], 1));
            painter.drawPoint(x, y);
        }
    }
}

void MainWindow::fillPlazma(int x1, int y1, int x2, int y2) {
    // Apparently, the program crashes if you make the inequalities strict
    if (x2 - x1 <= 1 && y2 - y1 <= 1) {
        return;
    }

    int midX = (x1 + x2) / 2;
    int midY = (y1 + y2) / 2;

    int midR = (plazma_[x1][y1].red() + plazma_[x1][y2].red() + plazma_[x2][y1].red() + plazma_[x2][y2].red()) / 4;
    int midG = (plazma_[x1][y1].green() + plazma_[x1][y2].green() + plazma_[x2][y1].green() + plazma_[x2][y2].green()) / 4;
    int midB = (plazma_[x1][y1].blue() + plazma_[x1][y2].blue() + plazma_[x2][y1].blue() + plazma_[x2][y2].blue()) / 4;

    // We've chosen the boundaries (-30, 30) but with (-70, 70) it's a little... sharper?..
    midR = (QRandomGenerator::global()->bounded(-70, 70) + midR) % 256;
    midG = (QRandomGenerator::global()->bounded(-70, 70) + midG) % 256;
    midB = (QRandomGenerator::global()->bounded(-70, 70) + midB) % 256;

    plazma_[midX][midY] = QColor(midR, midG, midB);

    fillPlazma(x1, y1, midX, midY);
    fillPlazma(midX, y1, x2, midY);
    fillPlazma(x1, midY, midX, y2);
    fillPlazma(midX, midY, x2, y2);
}
