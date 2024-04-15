#include "mandelbrot.h"

int Mandelbrot::getWidth() {
    return WIDTH;
}

int Mandelbrot::getHeight() {
    return HEIGHT;
}

int Mandelbrot::mandelbrot(double cx, double cy) {
    double x = 0.0;
    double y = 0.0;
    int iteration = 0;
    while (x * x + y * y < ESCAPE_RADIUS * ESCAPE_RADIUS && iteration < MAX_ITERATIONS) {
        double xTemp = x * x - y * y + cx;
        y = 2 * x * y + cy;
        x = xTemp;
        iteration++;
    }

    if (iteration == MAX_ITERATIONS) {
        return 0; // Inside the set
    }

    return iteration; // Outside the set
}

void Mandelbrot::drawMandelbrotSet(QGraphicsScene &scene) {
    double dx = (MAX_X - MIN_X) / WIDTH;
    double dy = (MAX_Y - MIN_Y) / HEIGHT;

    for (int x = 0; x < WIDTH; ++x) {
        for (int y = 0; y < HEIGHT; ++y) {
            double cx = MIN_X + x * dx;
            double cy = MIN_Y + y * dy;
            int color = mandelbrot(cx, cy);
            if (color == 0) {
                scene.addRect(x, y, 1, 1, QPen(Qt::black), QBrush(Qt::black));
            } else {
                double hue = (360.0 * color) / MAX_ITERATIONS;
                if (hue < 240.0) {
                    hue = 240.0 - hue; // Shift hue to make blue hues for points outside the set
                } else {
                    hue = 360.0 - hue + 240.0; // Adjust hue for points inside the set
                }
                QColor colorValue = QColor::fromHsvF(hue / 360.0, 1.0, 1.0);
                scene.addRect(x, y, 1, 1, QPen(colorValue), QBrush(colorValue));
            }
        }
    }
}

