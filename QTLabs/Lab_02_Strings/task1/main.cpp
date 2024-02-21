#include <QCoreApplication>
#include "arrayfiller.h"
#include "differentwords.h"
#include "spacecounter.h"

int main() {
    ArrayFiller tool("I know you will be a star in somebody's sky...");
    tool.execute();
    ArrayFiller tmp("But why, why can't it be... can't it be mine?");
    tmp.execute();
    DifferentWords str("Why why why we have to do this... stupid lab????");
    str.execute();
    return 0;
}
