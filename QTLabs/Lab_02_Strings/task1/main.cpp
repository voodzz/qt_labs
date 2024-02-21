#include <QCoreApplication>
#include "arrayfiller.h"
#include "differentwords.h"
#include "spacecounter.h"
#include "sentence.h"
#include "task.h"

int main() {
    // SpaceCounter tool("I know you will          be a star in            somebody's sky...");
    // tool.execute();
    // ArrayFiller tmp("But why, why can't it be... can't it be mine?");
    // tmp.execute();
    // DifferentWords str("Why why why do we have to do this... stupid lab????");
    // str.execute();
    Sentence sentenceForTask1("I know you will          be a star in            somebody's sky...");
    Sentence sentenceForTask2("But why, why can't it be... can't it be mine?");
    Sentence sentenceForTask3("Why why why do we have to do this... stupid lab????");

    SpaceCounter task1(sentenceForTask1);
    ArrayFiller task2(sentenceForTask2);
    DifferentWords task3(sentenceForTask3);

    Task task;
    task.addCommand(&task1);
    task.addCommand(&task2);
    task.addCommand(&task3);

    task.performTask(1);
    task.performTask(2);
    task.performTask(3);
    return 0;
}
