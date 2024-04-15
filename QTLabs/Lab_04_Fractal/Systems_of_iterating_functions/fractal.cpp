#include <QRandomGenerator>
#include <QGraphicsRectItem>
#include "fractal.h"

void Fractal::drawFractal(QGraphicsScene &scene) {
    QGraphicsRectItem* rect = scene.addRect(0,0,800,800);

    // Make the border invisible
    QPen pen = rect->pen();
    pen.setColor(Qt::transparent);
    rect->setPen(pen);

    scene.addRect(x, y, 1, 1, QPen(Qt::black), QBrush(Qt::black));
    qreal scale = 70.0; // Adjust the scale factor here for a bigger fractal
    for (int i = 0; i < steps; ++i) {
        qreal newX;
        qreal newY;
        if (QRandomGenerator::global()->bounded(100) < 1) {
            newX = 0 * x;
            newY = 0.16 * y;
        } else if (QRandomGenerator::global()->bounded(100) < 85) {
            newX = 0.85 * x + 0.04 * y;
            newY = -0.04 * x + 0.85 * y + 1.6;
        } else if (QRandomGenerator::global()->bounded(100) < 75) {
            newX = 0.2 * x - 0.26 * y;
            newY = 0.23 * x + 0.22 * y + 1.6;
        } else {
            newX = -0.15 * x + 0.28 * y;
            newY = 0.26 * x + 0.24 * y + 0.44;
        }
        x = newX;
        y= newY;
        qreal px = width() / 2 + scale * x;
        qreal py = height() - scale * y;
        scene.addRect(px, py, 1, 1, QPen(Qt::black), QBrush(Qt::black));
    }
}
