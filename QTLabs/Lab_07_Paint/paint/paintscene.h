#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>

class PaintScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit PaintScene(QObject *parent = nullptr);
};

#endif // PAINTSCENE_H
