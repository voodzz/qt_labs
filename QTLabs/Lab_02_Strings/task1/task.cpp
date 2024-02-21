#include <QString>
#include "task.h"

Task::Task() = default;

Task::~Task() = default;

Task::Task(const Task& other) = default;

Task& Task::operator=(const Task& other) = default;

Task::Task(Task&& other) = default;

Task& Task::operator =(Task&& other) = default;

void Task::addCommand(Command* command) {
    commands.push_back(command);
}

void Task::performTask(int number) {
    if (number > 0 && number <= commands.size()) {
        commands[number - 1]->execute();
    } else {
        throw std::invalid_argument("Invalid number of the task.");
    }
}
