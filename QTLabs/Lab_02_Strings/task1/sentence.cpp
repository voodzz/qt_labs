#include <QTextStream>
#include <QStringList>
#include <QSet>
#include "sentence.h"

Sentence::~Sentence() = default;

Sentence::Sentence(const Sentence& other) = default;

Sentence& Sentence::operator=(const Sentence& other) = default;

Sentence::Sentence(Sentence&& other) = default;

Sentence& Sentence::operator =(Sentence&& other) = default;

Sentence::Sentence(const QString& sentence) : sentence_(sentence) {}

Sentence::Sentence(const char* sentence) : sentence_(sentence) {}

Sentence::Sentence(const std::string& sentence) : Sentence(sentence.c_str()) {}

QTextStream out(stdout);

void Sentence::PerformTaskOne() {
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
    out << "The maximum number of consecutive spaces is " << max << '.' << Qt::endl << Qt::endl;
}

void Sentence::PerformTaskTwo() {
    int i = 0;
    foreach (QChar symbol, sentence_) {
        // if ((symbol >= 33 && symbol <= 47) || (symbol >= 58 && symbol <= 64) || (symbol >= 91 && symbol <= 96) || (symbol >= 123 && symbol <= 127)) {
        //     sentence_.remove(i, 1);
        //     --i;
        // }

        if (symbol.isPunct()) {
            sentence_.remove(i, 1);
            --i;
        }
        ++i;
    }

    // std::vector<QString> words(10);
    // int j= 0;
    // for (int i = 0; i != 10; ++i) {
    //     QString tmp;
    //     while (j != sentence_.length() && sentence_[j] != ' ') {
    //         tmp += sentence_[j];
    //         ++j;
    //     }
    //     words[i] = tmp;
    //     ++j;
    // }

    out << "The array is: ";

    QStringList words = sentence_.split(' ');

    for (int i = 0; i != words.size(); ++i) {
        if (i != words.size() - 1) {
            out << words[i] << ", ";
        } else {
            out << words[i] << ".\n";
        }
    }
    out << '\n';
}

void Sentence::PerformTaskThree() {
    int i = 0;
    foreach (QChar symbol, sentence_) {
        // if ((symbol >= 33 && symbol <= 47) || (symbol >= 58 && symbol <= 64) || (symbol >= 91 && symbol <= 96) || (symbol >= 123 && symbol <= 127)) {
        //     sentence_.remove(i, 1);
        //     --i;
        // }

        if (symbol.isPunct()) {
            sentence_.remove(i, 1);
            --i;
        }
        ++i;
    }
    sentence_ = sentence_.toLower();

    //std::set<QString> words;
    // int j= 0;
    // for (int i = 0; i != 10; ++i) {
    //     QString tmp;
    //     while (j != sentence_.length() && sentence_[j] != ' ') {
    //         tmp += sentence_[j];
    //         ++j;
    //     }
    //     words.insert(tmp);
    //     ++j;
    // }

    QStringList words = sentence_.split(' ');
    QSet<QString> result;

    for (const auto& word : words) {
        result.insert(word);
    }
    words.clear();

    out << "All the different words from the sentence:\n";
    for (const auto& word : result) {
        out << word << '\n';
    }
    out << '\n';
}
