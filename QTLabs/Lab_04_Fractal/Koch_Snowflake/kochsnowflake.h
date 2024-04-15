#ifndef KOCHSNOWFLAKE_H
#define KOCHSNOWFLAKE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsLineItem>

class KochSnowflake : public QGraphicsScene {
public:
    KochSnowflake(QObject *parent = nullptr) : QGraphicsScene(parent) {};
    ~KochSnowflake() = default;

    KochSnowflake(const KochSnowflake& other) = delete;
    KochSnowflake& operator =(const KochSnowflake& other) = delete;
    KochSnowflake(KochSnowflake&& other) = delete;
    KochSnowflake& operator =(KochSnowflake&& other) = delete;

    void drawKochSnowflake(float x, float y, float size, int iterations);

private:
    void drawKochCurve(float x1, float y1, float x2, float y2, int iterations);
};

#endif // KOCHSNOWFLAKE_H
