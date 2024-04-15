#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Stocastic Fractal \"plasma\"");
    w.setGeometry(QRect(540,100, 850, 850));
    w.dotsColorInitialization();
    w.show();
    return a.exec();
}
