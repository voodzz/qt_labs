#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item {
public:
    Item() = default;
    Item(QString group, QString name, QString model, qint32 code, qreal price, qint32 quantity) :
        group_(group), name_(name), model_(model), code_(code), price_(price), quantity_(quantity) {};
    ~Item() = default;

    Item(const Item& other) = default;
    Item& operator =(const Item& other) = default;
    Item (Item&& other) = default;
    Item& operator =(Item&& other) = default;

    // getters
    QString getGroup();
    QString getName();
    QString getModel();
    qint32 getCode();
    qreal getPrice();
    qint32 getQuantity();
    bool getInStock();

    // setters
    void setGroup(const QString& group);
    void setName(const QString& name);
    void setModel(const QString& model);
    void setCode (qint32 code);
    void setPrice (qreal price);
    void setQuantity(qint32 quantity);
    void setInStock(bool inStock);

private:
    QString group_;
    QString name_;
    QString model_;
    qint32 code_;
    qreal price_;
    qint32 quantity_;
    bool inStock_ = false;
};

#endif // ITEM_H
