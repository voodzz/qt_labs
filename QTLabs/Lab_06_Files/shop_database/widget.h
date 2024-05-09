#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "item.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_addButton_clicked();

    void on_clearButton_clicked();

    void on_openListButton_clicked();

private:
    Ui::Widget *ui;
    QVector<Item*> items_;
    QJsonArray itemsJSON_;
    const QString filePath_ = "C:/Task_Bar/Two/Studying/Programming/qt_labs/QTLabs/Lab_06_Files/shop_database/data.json";
};
#endif // WIDGET_H
