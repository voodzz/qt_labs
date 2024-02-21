#include "sentence.h"
#include "spacecounter.h"

// SpaceCounter::SpaceCounter(const QString& sentence): Command(sentence) {};

// SpaceCounter::SpaceCounter(const std::string& sentence): Command(sentence.c_str()) {};

// SpaceCounter::SpaceCounter(const char* sentence): Command(sentence) {};

SpaceCounter::SpaceCounter(Sentence& sentence) : Command(sentence) {}

void SpaceCounter::execute() {
    // uint16_t counter = 0;
    // uint16_t max = 0;
    // foreach (QChar symbol, sentence_) {
    //     if  (symbol == ' ') {
    //         ++counter;
    //     } else {
    //         counter = 0;
    //     }
    //     if (counter > max) {
    //         max = counter;
    //     }
    // }
    // std::cout << "The maximum number of consecutive spaces is " << max << '.' << std::endl << std::endl;
    sentence_.PerformTaskOne();
}
