#include "mandelbrot.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QGraphicsView view;
    Mandelbrot mandelbrot;
    mandelbrot.drawMandelbrotSet(mandelbrot);
    view.setGeometry(QRect(540,100, 850, 850));
    view.setScene(&mandelbrot);
    view.show();
    return a.exec();
}
