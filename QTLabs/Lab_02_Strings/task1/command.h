#ifndef COMMAND_H
#define COMMAND_H

class Command
{
public:
    Command() = default;
    virtual ~Command() = default;

    Command(const Command& other) = default;
    Command& operator=(const Command& other) = default;
    Command(Command&& other) = default;
    Command& operator=(Command&& other) = default;

    virtual void execute() = 0;
};

#endif // COMMAND_H
