#ifndef DIFFERENTWORDS_H
#define DIFFERENTWORDS_H

#include <QString>
#include <string>
#include "command.h"

class DifferentWords : public Command {
public:
    DifferentWords(const QString& sentence);
    DifferentWords(const std::string& sentence);
    DifferentWords(const char* sentence);

    ~DifferentWords() override = default;

    DifferentWords(const DifferentWords& other) = default;
    DifferentWords& operator=(const DifferentWords& other) = default;
    DifferentWords(DifferentWords&& other) = default;
    DifferentWords& operator=(DifferentWords&& other) = default;

    void execute() override;
};

#endif // DIFFERENTWORDS_H
