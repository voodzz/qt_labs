#ifndef ARRAYFILLER_H
#define ARRAYFILLER_H

#include <QTextStream>
#include <QString>
#include "command.h"
#include "sentence.h"

class ArrayFiller : public Command
{
public:
    // ArrayFiller(const QString& sentence);
    // ArrayFiller(const std::string& sentence);
    // ArrayFiller(const char* sentence);
    ArrayFiller(Sentence& sentence);

    ~ArrayFiller() override = default;

    ArrayFiller(const ArrayFiller& other) = default;
    ArrayFiller& operator=(const ArrayFiller& other) = delete;
    ArrayFiller(ArrayFiller&& other) = default;
    ArrayFiller& operator=(ArrayFiller&& other) = delete;

    void execute() override;
};

#endif // ARRAYFILLER_H
