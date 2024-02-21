#ifndef TASK_H
#define TASK_H

#include <vector>
#include "command.h"

// Invoker
class Task {
public:
    Task();
    ~Task();

    Task(const Task& other);
    Task& operator =(const Task& other);
    Task(Task&& other);
    Task& operator =(Task&& other);

    void addCommand(Command* command);
    void performTask(int number);
private:
    std::vector<Command*> commands;
};

#endif // TASK_H
