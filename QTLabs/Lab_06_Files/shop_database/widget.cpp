#include "widget.h"
#include "ui_widget.h"
#include "item.h"
#include <QFile>
#include <QTextCodec>
#include <QJsonObject>

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
    int index = -1;
    // Проверяем есть ли такой объект, чтобы, если что, добавлять количество
    for (auto& item : items_) {
        ++index;
        if (item->getName() == ui->nameLineEdit->text() && item->getModel() == ui->modelLineEdit->text()) {
                int quantity = item->getQuantity();
                quantity += ui->quantityLineEdit->text().toInt();
                item->setQuantity(quantity);
                auto JSONobject = itemsJSON_[index].toObject();
                JSONobject["Quantity"] = quantity;
                itemsJSON_[index] = JSONobject;

                // Записываем в .json файл
                QJsonDocument jsonDocument(itemsJSON_);
                QByteArray jsonString = jsonDocument.toJson();
                qDebug() << "JSON data to be written:" << jsonString;
                QString filePath = "C:/Task_Bar/Two/Studying/Programming/qt_labs/QTLabs/Lab_06_Files/shop_database/data.json";
                QFile file(filePath);
                if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    qDebug() << "Failed to open file for writing:" << file.errorString();
                    return;
                }
                QTextStream out(&file);
                out << jsonString;
                file.close();
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
    QJsonDocument jsonDocument(itemsJSON_);
    QByteArray jsonString = jsonDocument.toJson();
    //QString jsonStringUtf8 = QString::fromUtf8(jsonString);
    qDebug() << "JSON data to be written:" << jsonString;
    QFile file(filePath_);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing:" << file.errorString();
        return;
    }
    file.write(jsonString);
    file.close();
}


void Widget::on_clearButton_clicked() {
    ui->textEdit->clear();
    QFile file(filePath_);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing:" << file.errorString();
        return;
    }
    QByteArray emptyData = "";
    file.write(emptyData);
    file.close();
}

void Widget::on_openListButton_clicked() {
    QFile file(filePath_);
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

    // QString json = QString::fromUtf8(jsonData);
    // ui->textEdit->setText(json);

    itemsJSON_ = jsonDocument.array();
    QString str = "";
    for (const auto& tmp : itemsJSON_) {
        auto item = tmp.toObject();
        Item* newItem = new Item;
        newItem->setGroup(item["Group"].toString());
        str += "Group: " + item["Group"].toString() + "\n";
        newItem->setCode(item["Code"].toInt());
        str += "Code: " + QString::number(item["Code"].toInt()) + "\n";
        newItem->setName(item["Name"].toString());
        str += "Name: " +item["Name"].toString() + "\n";
        newItem->setModel(item["Model"].toString());
        str += "Model: " +item["Model"].toString() + "\n";
        newItem->setPrice(item["Price"].toDouble());
        str += "Price: " + QString::number(item["Price"].toDouble()) + "\n";
        newItem->setQuantity(item["Quantity"].toInt());
        str += "Quantity: " + QString::number(item["Quantity"].toInt()) + "\n";
        newItem->setInStock(item["In stock"].toBool());
        if (item["In stock"].toBool()) {
            str += "In stock: true\n";
        } else {
            str += "In stock: false\n";
        }
        items_.push_back(newItem);
        str += "\n";
    }
    ui->textEdit->setText(str);
}

