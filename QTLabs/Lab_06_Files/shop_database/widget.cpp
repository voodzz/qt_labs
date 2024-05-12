#include "widget.h"
#include "ui_widget.h"
#include "item.h"
#include <QFile>
#include <QTextCodec>
#include <QJsonObject>
#include <QButtonGroup>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    setFixedSize(1280, 720);
    ui->textEdit->setFontPointSize(10);
}

Widget::~Widget()
{
    delete ui;
    for (auto& item : items_) {
        delete item;
    }
}

void Widget::on_addButton_clicked() {
    lastSlotInvoked = "on_addButton_clicked";
    int index = -1;
    // Проверяем есть ли такой объект, чтобы, если что, добавлять количество
    for (auto& item : items_) {
        ++index;
        if (item->getName() == ui->nameLineEdit->text() && item->getModel() == ui->modelLineEdit->text()) {
            // Изменяем количество
            int quantity = item->getQuantity();
            quantity += ui->quantityLineEdit->text().toInt();
            item->setQuantity(quantity);
            auto JSONobject = itemsJSON_[index].toObject();
            JSONobject["Quantity"] = quantity;
            JSONobject["In stock"] = true;
            itemsJSON_[index] = JSONobject;

            // Записываем в .json файл
            writeToFile();
            print(); // Выводим на экран
            return;
        }
    }
    // Если объекта нет, то добавляем его
    QJsonObject newItemJSON;
    Item* newItem = new Item;

    newItem->setGroup(ui->groupLineEdit->text());
    newItemJSON["Group"] = ui->groupLineEdit->text();

    newItem->setName(ui->nameLineEdit->text());
    newItemJSON["Name"] = ui->nameLineEdit->text();

    newItem->setModel(ui->modelLineEdit->text());
    newItemJSON["Model"] = ui->modelLineEdit->text();

    newItem->setCode(ui->codeLineEdit->text().toInt());
    newItemJSON["Code"] = ui->codeLineEdit->text().toInt();

    newItem->setPrice(ui->priceLineEdit->text().toDouble());
    newItemJSON["Price"] = ui->priceLineEdit->text().toDouble();

    newItem->setQuantity(ui->quantityLineEdit->text().toInt());
    newItemJSON["Quantity"] = ui->quantityLineEdit->text().toInt();

    if (newItem->getQuantity() == 0) {
        newItem->setInStock(0);
        newItemJSON["In stock"] = false;
    } else {
        newItem->setInStock(1);
        newItemJSON["In stock"] = true;
    }

    items_.push_back(newItem);
    itemsJSON_.push_back(newItemJSON);

    // Записываем в .json файл
    writeToFile();
}

void Widget::on_clearButton_clicked() {
    lastSlotInvoked = "on_clearButton_clicked";
    ui->textEdit->clear();
    QFile file(FILE_PATH);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing:" << file.errorString();
        return;
    }
    QByteArray emptyData = "";
    file.write(emptyData);
    file.close();
}

void Widget::on_openListButton_clicked() {
    lastSlotInvoked = "on_openListButton_clicked";
    QFile file(FILE_PATH);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading:" << file.errorString();
        return;
    }

    // Читаем из файла
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonData, &parseError);
    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "Failed to parse JSON:" << parseError.errorString();
        return;
    }

    itemsJSON_ = jsonDocument.array();
    // Копируем массив в массив объектов класса Item
    items_.clear();
    for (const auto& tmp : itemsJSON_) {
        auto item = tmp.toObject();
        Item* newItem = new Item;
        newItem->setGroup(item["Group"].toString());
        newItem->setCode(item["Code"].toInt());
        newItem->setName(item["Name"].toString());
        newItem->setModel(item["Model"].toString());
        newItem->setPrice(item["Price"].toDouble());
        newItem->setQuantity(item["Quantity"].toInt());
        newItem->setInStock(item["In stock"].toBool());
        items_.push_back(newItem);
    }

    //  Выводим на экран
    print();
}

void Widget::print() {
    QString str = "";
    for (const auto& item : items_) {
        str += "Group: " + item->getGroup() + "\n";
        str += "Code: " + QString::number(item->getCode()) + "\n";
        str += "Name: " + item->getName() + "\n";
        str += "Model: " + item->getModel() + "\n";
        str += "Price: " + QString::number(item->getPrice()) + "\n";
        str += "Quantity: " + QString::number(item->getQuantity()) + "\n";
        if (item->getInStock()) {
            str += "In stock: true\n";
        } else {
            str += "In stock: false\n";
        }
        str += "\n";
    }
    ui->textEdit->setText(str);
}

bool Widget::compareItems(const Item* a, const Item* b) {
    switch (ui->sortComboBox->currentIndex()) {
    case 0:
        return a->getName() < b->getName();
    case 1:
        return a->getCode() < b->getCode();
    case 2:
        return a->getPrice() < b->getPrice();
    case 3:
        return a->getPrice() > b->getPrice();
    default:
        return false;
    }
}

void Widget::writeToFile() {
    QJsonDocument jsonDocument(itemsJSON_);
    QByteArray jsonString = jsonDocument.toJson();
    qDebug() << "JSON data to be written:" << jsonString;
    QFile file(FILE_PATH);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing:" << file.errorString();
        return;
    }
    file.write(jsonString);
    file.close();
}

void Widget::on_stockButton_clicked() {
    lastSlotInvoked = "on_stockButton_clicked";
    QString str = "";
    if (!ui->inStockComboBox->currentIndex()) {
        for (const auto& tmp : itemsJSON_) {
            auto item = tmp.toObject();
            if (item["In stock"].toBool()) {
                str += "Group: " + item["Group"].toString() + "\n";
                str += "Code: " + QString::number(item["Code"].toInt()) + "\n";
                str += "Name: " + item["Name"].toString() + "\n";
                str += "Model: " + item["Model"].toString() + "\n";
                str += "Price: " + QString::number(item["Price"].toDouble()) + "\n";
                str += "Quantity: " + QString::number(item["Quantity"].toInt()) + "\n";
                str += "In stock: true\n";
                str += "\n";
            }
        }
        ui->textEdit->setText(str);
    } else {
        for (const auto& tmp : itemsJSON_) {
            auto item = tmp.toObject();
            if (!item["In stock"].toBool()) {
                str += "Group: " + item["Group"].toString() + "\n";
                str += "Code: " + QString::number(item["Code"].toInt()) + "\n";
                str += "Name: " + item["Name"].toString() + "\n";
                str += "Model: " + item["Model"].toString() + "\n";
                str += "Price: " + QString::number(item["Price"].toDouble()) + "\n";
                str += "Quantity: " + QString::number(item["Quantity"].toInt()) + "\n";
                str += "In stock: false\n";
                str += "\n";
            }
        }
        ui->textEdit->setText(str);
    }
}

void Widget::on_searchButton_clicked() {
    lastSlotInvoked = "on_searchButton_clicked";
    if (ui->searchAndDeleteRadioButton->isChecked()) {
        QString str = "";
        for (const auto& item : items_) {
            if (ui->nameLineEdit->text() == item->getName() && ui->modelLineEdit->text() == item->getModel()) {
                str += "Group: " + item->getGroup() + "\n";
                str += "Code: " + QString::number(item->getCode()) + "\n";
                str += "Name: " + item->getName() + "\n";
                str += "Model: " + item->getModel() + "\n";
                str += "Price: " + QString::number(item->getPrice()) + "\n";
                str += "Quantity: " + QString::number(item->getQuantity()) + "\n";
                if (item->getInStock()) {
                    str += "In stock: true\n";
                } else {
                    str += "In stock: false\n";
                }
                str += "\n";
            }
        }
        ui->textEdit->setText(str);
    }
}

void Widget::on_deleteButton_clicked() {
    lastSlotInvoked = "on_deleteButton_clicked";
    if (ui->searchAndDeleteRadioButton->isChecked()) {
        QString name = ui->nameLineEdit->text();
        QString model = ui->modelLineEdit->text();
        for (int i = 0; i < items_.size(); ++i) {
            if (items_[i]->getName() == name && items_[i]->getModel() == model) {
                items_.removeAt(i);
            }
            if (itemsJSON_[i].toObject()["Name"] == name && itemsJSON_[i].toObject()["Model"] == model) {
                itemsJSON_.removeAt(i);
                break;
            }
        }

        // Перезаписываем файл
        writeToFile();
        print(); // Выводим на экран
    }
}

void Widget::on_searchAndDeleteRadioButton_toggled(bool checked) {
    lastSlotInvoked = "on_searchAndDeleteRadioButton_toggled";
    if (checked) {
        ui->groupLineEdit->setDisabled(true);
        ui->codeLineEdit->setDisabled(true);
        ui->priceLineEdit->setDisabled(true);
        ui->quantityLineEdit->setDisabled(true);
        ui->addButton->setDisabled(true);
    } else {
        ui->groupLineEdit->setDisabled(false);
        ui->codeLineEdit->setDisabled(false);
        ui->priceLineEdit->setDisabled(false);
        ui->quantityLineEdit->setDisabled(false);
        ui->addButton->setDisabled(false);
    }
}

void Widget::on_sortButton_clicked() {
    QList<Item*> tmp(items_);
    if (lastSlotInvoked == "on_stockButton_clicked") {
        if (ui->inStockComboBox->currentIndex() == 0) {
            for (int i = 0; i < items_.size(); ++i) {
                if (!items_[i]->getInStock()) {
                    items_.removeAt(i);
                    --i;
                }
            }
            std::sort(items_.begin(), items_.end(), [this](const Item* a, const Item* b) {
                return compareItems(a, b);
            });
            print();
            items_ = tmp;
            tmp.clear();
        } else {
            for (int i = 0; i < items_.size(); ++i) {
                if (items_[i]->getInStock()) {
                    items_.removeAt(i);
                    --i;
                }
            }
            std::sort(items_.begin(), items_.end(), [this](const Item* a, const Item* b) {
                return compareItems(a, b);
            });
            print();
            items_ = tmp;
            tmp.clear();
        }
    } else {
        std::sort(items_.begin(), items_.end(), [this](const Item* a, const Item* b) {
            return compareItems(a, b);
        });
        print();
    }
}

