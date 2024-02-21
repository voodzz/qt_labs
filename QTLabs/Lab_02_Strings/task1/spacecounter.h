#ifndef SPACECOUNTER_H
#define SPACECOUNTER_H

#include <QTextStream>
#include <QString>
#include "command.h"

class SpaceCounter : public Command
{
public:
    SpaceCounter(const QString& sentence): Command(sentence) {};
    SpaceCounter(const std::string& sentence): Command(sentence.c_str()) {};
    SpaceCounter(const char* sentence): Command(sentence) {};

    ~SpaceCounter() override = default;

    SpaceCounter(const SpaceCounter& other) = default;
    SpaceCounter& operator=(const SpaceCounter& other) = default;
    SpaceCounter(SpaceCounter&& other) = default;
    SpaceCounter& operator=(SpaceCounter&& other) = default;

    virtual void execute() override;
};

#endif // SPACECOUNTER_H
