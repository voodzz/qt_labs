#ifndef FRACTAL_H
#define FRACTAL_H

#include <QGraphicsScene>

class Fractal : public QGraphicsScene {
public:
    Fractal(QObject* parent = nullptr) : QGraphicsScene(parent) {};
    ~Fractal() = default;

    Fractal(const Fractal& other) = delete;
    Fractal& operator =(const Fractal& other) = delete;
    Fractal(Fractal&& other) = delete;
    Fractal& operator =(Fractal&& other) = delete;

    void drawFractal(QGraphicsScene& scene);

private:
    int steps = 10000;
    qreal x = 0;
    qreal y = 0;
};

#endif // FRACTAL_H
