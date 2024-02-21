#ifndef DIFFERENTWORDS_H
#define DIFFERENTWORDS_H

#include <QString>
#include "command.h"
#include "sentence.h"

class DifferentWords : public Command {
public:
    // DifferentWords(const QString& sentence);
    // DifferentWords(const std::string& sentence);
    // DifferentWords(const char* sentence);
    DifferentWords(Sentence& sentence);

    ~DifferentWords() override = default;

    DifferentWords(const DifferentWords& other) = default;
    DifferentWords& operator=(const DifferentWords& other) = delete;
    DifferentWords(DifferentWords&& other) = default;
    DifferentWords& operator=(DifferentWords&& other) = delete;

    void execute() override;
};

#endif // DIFFERENTWORDS_H
