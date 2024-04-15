#include "kochsnowflake.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QGraphicsView view;
    KochSnowflake snowflake;
    snowflake.drawKochSnowflake(-200, -150, 400, 5);
    view.setGeometry(QRect(540,100, 800, 800));
    view.setScene(&snowflake);
    view.setRenderHint(QPainter::Antialiasing);
    view.show();
    return a.exec();
}
