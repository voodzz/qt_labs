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
    void on_stockButton_clicked();
    void on_searchButton_clicked();
    void on_deleteButton_clicked();
    void on_searchAndDeleteRadioButton_toggled(bool checked);
    void on_sortButton_clicked();

    void on_lessThanButton_clicked();

private:
    Ui::Widget *ui;
    QList<Item*> items_;
    QJsonArray itemsJSON_;
    const QString FILE_PATH = "C:/Task_Bar/Two/Studying/Programming/qt_labs/QTLabs/Lab_06_Files/shop_database/data.json";
    void print();
    QString lastSlotInvoked;
    bool compareItems(const Item* a, const Item* b);
    void writeToFile();
};

#endif // WIDGET_H
