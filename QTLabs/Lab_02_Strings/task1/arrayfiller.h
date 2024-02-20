#ifndef ARRAYFILLER_H
#define ARRAYFILLER_H

#include <QTextStream>
#include <QString>
#include "command.h"

class ArrayFiller : public Command
{
public:
    ArrayFiller(const QString& sentence);
    ArrayFiller(const std::string& sentence);
    ArrayFiller(const char* sentence);

    ~ArrayFiller() override = default;

    ArrayFiller(const ArrayFiller& other) = default;
    ArrayFiller& operator=(const ArrayFiller& other) = default;
    ArrayFiller(ArrayFiller&& other) = default;
    ArrayFiller& operator=(ArrayFiller&& other) = default;

    void execute() override;
private:
    QString sentence_;
};

#endif // ARRAYFILLER_H
