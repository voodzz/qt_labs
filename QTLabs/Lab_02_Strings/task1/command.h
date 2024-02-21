#ifndef COMMAND_H
#define COMMAND_H

#include "sentence.h"
#include <QString>


class Command
{
public:
    Command() = delete;
    // Command(const QString& sentence) : sentence_(sentence) {}
    // Command(const char* sentence) : sentence_(sentence) {}
    Command(Sentence& sentence): sentence_(sentence) {}

    virtual ~Command() = default;

    Command(const Command& other) = default;
    Command& operator=(const Command& other) = delete;
    Command(Command&& other) = default;
    Command& operator=(Command&& other) = delete;

    virtual void execute() = 0;
protected:
    Sentence& sentence_;
};

#endif // COMMAND_H
