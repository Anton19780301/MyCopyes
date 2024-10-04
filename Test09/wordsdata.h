#ifndef WORDSDATA_H
#define WORDSDATA_H

#include <QObject>

class WordsData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString word READ word WRITE setWord NOTIFY wordChanged)
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)


public:
    explicit WordsData();
    explicit WordsData(QString word,int count );
    QString word() const;
    void setWord(const QString &newWord);
    int count() const;
    void setCount(int newCount);

signals:
    void wordChanged();
    void countChanged();

private:
    QString m_word;
    int m_count;
};

Q_DECLARE_METATYPE(WordsData)

#endif // WORDSDATA_H
