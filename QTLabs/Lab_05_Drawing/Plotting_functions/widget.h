#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    Widget(const Widget& other) = delete;
    Widget& operator =(const Widget& other) = delete;
    Widget(Widget&& other) = delete;
    Widget& operator =(Widget&& other) = delete;

private slots:
    void on_lineEdit_textChanged(const QString &arg1);
    void on_lineEdit_2_textChanged(const QString &arg1);
    void on_lineEdit_3_textChanged(const QString &arg1);
    void on_lineEdit_4_textChanged(const QString &arg1);
    void on_lineEdit_5_textChanged(const QString &arg1);
    void on_lineEdit_6_textChanged(const QString &arg1);
    void on_lineEdit_7_textChanged(const QString &arg1);
    void on_lineEdit_8_textChanged(const QString &arg1);
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_lineEdit_17_textChanged(const QString &arg1);

private:
    Ui::Widget *ui;
    QGraphicsScene* scene_;
    QPixmap field_;

    QPen pen_;

    qreal x_min = 0;
    qreal x_max = 0;
    qreal y_min = 0;
    qreal y_max = 0;
    qreal a_ = 0;
    qreal b_ = 0;
    qreal c_ = 0;
    qreal d_ = 0;
    qreal r_ = 0;

    void drawCoordNetAndAxes();
    void drawGraph();
    void drawLinear(QTransform& transform);
    void drawQuadratic(QTransform& transform);
    void drawCubic(QTransform& transform);
    void drawCircle(QTransform& transform);
    void drawEllipse(QTransform& transform);
    void drawExp(QTransform& transform);
    void drawArbitrary(QTransform& transform);

    qreal quadraticEquation(qreal x);
    qreal cubicEquation(qreal x);
    qreal arbitraryFunction(qreal x);
};

#endif // WIDGET_H
