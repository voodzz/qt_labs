#include <iostream>
#include "spacecounter.h"

void SpaceCounter::execute() {
    uint16_t counter = 0;
    uint16_t max = 0;
    foreach (QChar symbol, sentence_) {
        if  (symbol == ' ') {
            ++counter;
        } else {
            counter = 0;
        }
        if (counter > max) {
            max = counter;
        }
    }
    std::cout << "The maximum number of consecutive spaces is " << max << std::endl;
}
