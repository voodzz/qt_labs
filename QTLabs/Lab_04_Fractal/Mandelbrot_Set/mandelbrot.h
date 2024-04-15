#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

class Mandelbrot : public QGraphicsScene {
public:
    Mandelbrot(QObject *parent = nullptr) : QGraphicsScene(parent) {};
    ~Mandelbrot() = default;

    Mandelbrot(const Mandelbrot& other) = delete;
    Mandelbrot& operator =(const Mandelbrot& other) = delete;
    Mandelbrot(Mandelbrot&& other) = delete;
    Mandelbrot& operator =(Mandelbrot&& other) = delete;

    void drawMandelbrotSet(QGraphicsScene& scene);
    int getWidth();
    int getHeight();

private:
    const int WIDTH = 800;
    const int HEIGHT = 800;
    const int MAX_ITERATIONS = 200;
    const double ESCAPE_RADIUS = 2.0;
    const double MIN_X = -2.0;
    const double MAX_X = 1.0;
    const double MIN_Y = -1.5;
    const double MAX_Y = 1.5;

    int mandelbrot(double cx, double cy);
};

#endif // MANDELBROT_H
