#include "mainwindow.h"

#include <QApplication>
#include <QColor>
#include <QBrush>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Приложение-переводчик с/с");
    w.setWindowIcon(QIcon(":/icon/icon/pngwing.com(12).png"));

    QPalette pal = w.palette();
    pal.setBrush(QPalette::Normal, QPalette::Window, QBrush(QColor(240, 240, 240), Qt::SolidPattern));
    w.setPalette(pal);
    w.show();
    return a.exec();
}
