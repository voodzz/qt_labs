#include "item.h"

QString Item::getGroup() {
    return group_;
}

QString Item::getName() {
    return name_;
}

QString Item::getModel() {
    return model_;
}

qint32 Item::getCode() {
    return code_;
}

qreal Item::getPrice() {
    return price_;
}

qint32 Item::getQuantity() {
    return quantity_;
}

bool Item::getInStock() {
    return inStock_;
}

void Item::setGroup(const QString &group) {
    group_ = group;
}

void Item::setName(const QString &name) {
    name_ = name;
}

void Item::setModel(const QString &model) {
    model_ = model;
}

void Item::setCode(qint32 code) {
    code_ = code;
}

void Item::setPrice(qreal price) {
    price_ = price;
}

void Item::setQuantity(qint32 quantity) {
    quantity_ = quantity;
}

void Item::setInStock(bool inStock) {
    inStock_ = inStock;
}
