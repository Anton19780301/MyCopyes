#include "wordsdata.h"

WordsData::WordsData() {}

WordsData::WordsData(QString word, int count)
{
    setWord(word);
    setCount(count);
}

QString WordsData::word() const
{
    return m_word;
}

void WordsData::setWord(const QString &newWord)
{
    if (m_word == newWord)
        return;
    m_word = newWord;
    emit wordChanged();
}

int WordsData::count() const
{
    return m_count;
}

void WordsData::setCount(int newCount)
{
    if (m_count == newCount)
        return;
    m_count = newCount;
    emit countChanged();
}
