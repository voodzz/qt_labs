#include "widget.h"
#include "ui_widget.h"
#include "item.h"
#include <QFile>
#include <QTextCodec>
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
    // Проверяем есть ли такой объект, чтобы, если что, добавлять количество
    for (auto& item : items_) {
        ++index;
        if (item->getName() == ui->nameLineEdit->text() && item->getModel() == ui->modelLineEdit->text()) {
                int quantity = item->getQuantity();
                quantity += ui->quantityLineEdit->text().toInt();
                item->setQuantity(quantity);
                auto JSONobject = itemsJSON_[index].toObject();
                JSONobject["Количество"] = quantity;
                itemsJSON_[index] = JSONobject;

                // Записываем в .json файл
                QJsonDocument jsonDocument(itemsJSON_);
                QByteArray jsonString = jsonDocument.toJson();
                qDebug() << "JSON data to be written:" << jsonString;
                QString filePath = "C:/Task_Bar/Two/Studying/Programming/qt_labs/QTLabs/Lab_06_Files/shop_database/data.json";
                QFile file(filePath);
                if (!file.open(QIODevice::WriteOnly)) {
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

    if (newItem->getQuantity() == 0) {
        newItem->setInStock(0);
        newItemJSON["В наличии"] = false;
    } else {
        newItem->setInStock(1);
        newItemJSON["В наличии"] = true;
    }

    items_.push_back(newItem);
    itemsJSON_.push_back(newItemJSON);

    // Записываем в .json файл
    QJsonDocument jsonDocument(itemsJSON_);
    QByteArray jsonString = jsonDocument.toJson();
    qDebug() << "JSON data to be written:" << jsonString;
    QFile file(filePath_);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Failed to open file for writing:" << file.errorString();
        return;
    }
    QTextStream out(&file);
    out << jsonString;
    file.close();
}


void Widget::on_clearButton_clicked() {
    ui->textEdit->clear();
    QFile file(filePath_);
    QByteArray emptyData;
    file.write(emptyData);
    file.close();
}

void Widget::on_openListButton_clicked() {
    QFile file(filePath_);
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading:" << file.errorString();
        return;
    }

    // Read JSON data from file
    QByteArray jsonData = codec->toUnicode(file.readAll()).toUtf8();
    file.close();

    // Parse JSON data
    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);
    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "Failed to parse JSON:" << parseError.errorString();
        return;
    }
}

