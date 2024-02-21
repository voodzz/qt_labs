#ifndef SPACECOUNTER_H
#define SPACECOUNTER_H

#include <QTextStream>
#include <QString>
#include "command.h"
#include "sentence.h"

class SpaceCounter : public Command
{
public:
    // SpaceCounter(const QString& sentence);
    // SpaceCounter(const std::string& sentence);
    // SpaceCounter(const char* sentence);
    SpaceCounter(Sentence& sentence);

    ~SpaceCounter() override = default;

    SpaceCounter(const SpaceCounter& other) = default;
    SpaceCounter& operator=(const SpaceCounter& other) = delete;
    SpaceCounter(SpaceCounter&& other) = default;
    SpaceCounter& operator=(SpaceCounter&& other) = delete;

    virtual void execute() override;
};

#endif // SPACECOUNTER_H
