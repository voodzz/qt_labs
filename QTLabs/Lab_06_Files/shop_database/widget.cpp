#include "widget.h"
#include "ui_widget.h"
#include "item.h"
#include <QJsonObject>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    setFixedSize(1280, 720);
}

Widget::~Widget()
{
    delete ui;
    for (auto& item : items_) {
        delete item;
    }
}

void Widget::on_addButton_clicked() {
    int index = -1;
    for (auto& item : items_) {
        ++index;
        if (item->getName() == ui->nameLineEdit->text() && item->getModel() == ui->modelLineEdit->text()) {
                int quantity = item->getQuantity();
                quantity += ui->quantityLineEdit->text().toInt();
                item->setQuantity(quantity);
                auto JSONobject = itemsJSON_[index].toObject();
                JSONobject["Количество"] = quantity;
                itemsJSON_[index] = JSONobject;
                return;
        }
    }
    QJsonObject newItemJSON;
    Item* newItem = new Item;

    newItem->setGroup(ui->groupLineEdit->text());
    newItemJSON["Группа"] = ui->groupLineEdit->text();

    newItem->setName(ui->nameLineEdit->text());
    newItemJSON["Наименование продукции"] = ui->nameLineEdit->text();

    newItem->setModel(ui->modelLineEdit->text());
    newItemJSON["Модель продукции"] = ui->modelLineEdit->text();

    newItem->setCode(ui->codeLineEdit->text().toInt());
    newItemJSON["Код продукции"] = ui->codeLineEdit->text().toInt();

    newItem->setPrice(ui->priceLineEdit->text().toDouble());
    newItemJSON["Цена"] = ui->priceLineEdit->text().toDouble();

    newItem->setQuantity(ui->quantityLineEdit->text().toInt());
    newItemJSON["Количество"] = ui->quantityLineEdit->text().toInt();

    newItem->setInStock(1);
    newItemJSON["В наличии"] = true;

    items_.push_back(newItem);
    itemsJSON_.push_back(newItemJSON);
}

