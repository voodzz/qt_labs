#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>

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

protected:
    void paintEvent(QPaintEvent* event);

private:
    Ui::Widget *ui;
    void setInterfaceStyle();
    void changeButtonStatus(int num);

private slots:
    void on_leftButton_clicked();
    void on_rightButton_clicked();
};
#endif // WIDGET_H
