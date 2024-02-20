#ifndef SPACECOUNTER_H
#define SPACECOUNTER_H

#include <QTextStream>
#include <QString>
#include "command.h"

class SpaceCounter : public Command
{
public:
    SpaceCounter(const QString& sentence): sentence_(sentence) {};
    SpaceCounter(const std::string& sentence): sentence_(sentence.c_str()) {};
    SpaceCounter(const char* sentence): sentence_(sentence) {};

    ~SpaceCounter() override = default;

    SpaceCounter(const SpaceCounter& other) = default;
    SpaceCounter& operator=(const SpaceCounter& other) = default;
    SpaceCounter(SpaceCounter&& other) = default;
    SpaceCounter& operator=(SpaceCounter&& other) = default;

    virtual void execute() override;

private:
    QString sentence_;
};

#endif // SPACECOUNTER_H
