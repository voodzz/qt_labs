#include "kochsnowflake.h"
#include <cmath>

void KochSnowflake::drawKochCurve(float x1, float y1, float x2, float y2, int iterations) {
    if (iterations == 0) {
        QGraphicsLineItem *line = new QGraphicsLineItem(x1, y1, x2, y2);
        addItem(line);
    } else {
        float deltaX = x2 - x1;
        float deltaY = y2 - y1;

        float newX1 = x1 + deltaX / 3;
        float newY1 = y1 + deltaY / 3;

        float newX2 = x1 + deltaX * 2 / 3;
        float newY2 = y1 + deltaY * 2 / 3;

        float newX3 = (x1 + x2) / 2 + (y1 - y2) * sqrt(3) / 6;
        float newY3 = (y1 + y2) / 2 + (x2 - x1) * sqrt(3) / 6;

        drawKochCurve(x1, y1, newX1, newY1, iterations - 1);
        drawKochCurve(newX1, newY1, newX3, newY3, iterations - 1);
        drawKochCurve(newX3, newY3, newX2, newY2, iterations - 1);
        drawKochCurve(newX2, newY2, x2, y2, iterations - 1);
    }
}

void KochSnowflake::drawKochSnowflake(float x, float y, float size, int iterations) {
    float height = size * sqrt(3) / 2;
    float x1 = x - size / 2;
    float y1 = y + height / 3;
    float x2 = x1 + size;
    float y2 = y1;
    float x3 = x;
    float y3 = y - 2 * height / 3;

    drawKochCurve(x1, y1, x2, y2, iterations);
    drawKochCurve(x2, y2, x3, y3, iterations);
    drawKochCurve(x3, y3, x1, y1, iterations);
}
