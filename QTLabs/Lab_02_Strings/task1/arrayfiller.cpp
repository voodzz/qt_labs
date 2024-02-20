#include <iostream>
#include <vector>
#include "arrayfiller.h"

ArrayFiller::ArrayFiller(const QString& sentence): sentence_(sentence) {
    int i = 0;
    foreach (QChar symbol, sentence_) {
            if ((symbol >= 33 && symbol <= 47) || (symbol >= 58 && symbol <= 64) || (symbol >= 91 && symbol <= 96) || (symbol >= 123 && symbol <= 127)) {
                sentence_.remove(i, 1);
                --i;
            }
            ++i;
    }
};

ArrayFiller::ArrayFiller(const char* sentence): sentence_(sentence) {
    int i = 0;
    foreach (QChar symbol, sentence_) {
        if ((symbol >= 33 && symbol <= 47) || (symbol >= 58 && symbol <= 64) || (symbol >= 91 && symbol <= 96) || (symbol >= 123 && symbol <= 127)) {
            sentence_.remove(i, 1);
            --i;
        }
        ++i;
    }
}

ArrayFiller::ArrayFiller(const std::string& sentence): sentence_(sentence.c_str()) {
    int i = 0;
    foreach (QChar symbol, sentence_) {
        if ((symbol >= 33 && symbol <= 47) || (symbol >= 58 && symbol <= 64) || (symbol >= 91 && symbol <= 96) || (symbol >= 123 && symbol <= 127)) {
            sentence_.remove(i, 1);
            --i;
        }
        ++i;
    }
}

void ArrayFiller::execute() {
    std::vector<QString> words(10);
    int j= 0;
    for (int i = 0; i != 10; ++i) {
        QString tmp;
        while (j != sentence_.length() && sentence_[j] != ' ') {
            tmp += sentence_[j];
            ++j;
        }
        words[i] = tmp;
        ++j;
    }
    for (const auto& word : words) {
        std::cout << word.toStdString() << '\n';
    }
    std::cout << '\n';
}
