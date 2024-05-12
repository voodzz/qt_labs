#include "item.h"

QString Item::getGroup() const{
    return group_;
}

QString Item::getName() const{
    return name_;
}

QString Item::getModel() const{
    return model_;
}

int Item::getCode() const{
    return code_;
}

qreal Item::getPrice() const{
    return price_;
}

int Item::getQuantity() const{
    return quantity_;
}

bool Item::getInStock() const{
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

void Item::setCode(int code) {
    code_ = code;
}

void Item::setPrice(qreal price) {
    price_ = price;
}

void Item::setQuantity(int quantity) {
    quantity_ = quantity;
}

void Item::setInStock(bool inStock) {
    inStock_ = inStock;
}
