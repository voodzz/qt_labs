#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item {
public:
    Item() = default;
    Item(QString group, QString name, QString model, quint32 code, qreal price, quint32 quantity) :
        group_(group), name_(name), model_(model), code_(code), price_(price), quantity_(quantity) {};
    ~Item() = default;

    Item(const Item& other) = default;
    Item& operator =(const Item& other) = default;
    Item (Item&& other) = default;
    Item& operator =(Item&& other) = default;

    // getters
    QString getGroup() const;
    QString getName() const;
    QString getModel() const;
    int getCode() const;
    qreal getPrice() const;
    int getQuantity() const;
    bool getInStock() const;

    // setters
    void setGroup(const QString& group);
    void setName(const QString& name);
    void setModel(const QString& model);
    void setCode (int code);
    void setPrice (qreal price);
    void setQuantity(int quantity);
    void setInStock(bool inStock);

private:
    QString group_;
    QString name_;
    QString model_;
    int code_;
    qreal price_;
    int quantity_;
    bool inStock_ = false;
};

#endif // ITEM_H
