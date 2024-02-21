#ifndef COMMAND_H
#define COMMAND_H

#include <QString>

class Command
{
public:
    Command() = default;
    Command(const QString& sentence) : sentence_(sentence) {

    }
    Command(const char* sentence) : sentence_(sentence) {

    }
    virtual ~Command() = default;

    Command(const Command& other) = default;
    Command& operator=(const Command& other) = default;
    Command(Command&& other) = default;
    Command& operator=(Command&& other) = default;

    virtual void execute() = 0;
protected:
    QString sentence_;
};

#endif // COMMAND_H
