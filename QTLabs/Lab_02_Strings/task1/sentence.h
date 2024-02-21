#ifndef SENTENCE_H
#define SENTENCE_H

#include <QString>

// Receiver
class Sentence
{
public:
    Sentence() = delete;
    ~Sentence();

    Sentence(const QString& sentence);
    Sentence(const char* sentence);
    Sentence(const std::string& sentence);

    Sentence(const Sentence& other);
    Sentence& operator =(const Sentence& other);
    Sentence(Sentence&& other);
    Sentence& operator =(Sentence&& other);

    void PerformTaskOne();
    void PerformTaskTwo();
    void PerformTaskThree();
private:
    QString sentence_;
};

#endif // SENTENCE_H
