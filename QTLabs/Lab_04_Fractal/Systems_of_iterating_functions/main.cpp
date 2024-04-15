#include <QGraphicsView>
#include <QApplication>
#include <fractal.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Fractal fractal;
    QGraphicsView w(&fractal);
    w.setGeometry(QRect(540,100, 850, 850));
    fractal.drawFractal(fractal);
    w.show();
    return a.exec();
}
