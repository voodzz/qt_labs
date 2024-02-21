#include <iostream>
#include <set>
#include "differentwords.h"

DifferentWords::DifferentWords(const QString& sentence): Command(sentence) {};

DifferentWords::DifferentWords(const char* sentence): Command(sentence) {}

DifferentWords::DifferentWords(const std::string& sentence): Command(sentence.c_str()) {}

void DifferentWords::execute() {
    int i = 0;
    foreach (QChar symbol, sentence_) {
        if ((symbol >= 33 && symbol <= 47) || (symbol >= 58 && symbol <= 64) || (symbol >= 91 && symbol <= 96) || (symbol >= 123 && symbol <= 127)) {
            sentence_.remove(i, 1);
            --i;
        }
        ++i;
    }
    sentence_ = sentence_.toLower();

    std::set<QString> words;
    int j= 0;
    for (int i = 0; i != 10; ++i) {
        QString tmp;
        while (j != sentence_.length() && sentence_[j] != ' ') {
            tmp += sentence_[j];
            ++j;
        }
        words.insert(tmp);
        ++j;
    }
    for (const auto& word : words) {
        std::cout << word.toStdString() << '\n';
    }
    std::cout << '\n';
}
