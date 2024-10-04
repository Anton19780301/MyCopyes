#ifndef WORDSDATA_H
#define WORDSDATA_H

//! файл хранит информацию о позиции слова в рейтинге
/*!
@brief файл хранит информацию о позиции слова в рейтинге. В нем только два поля,
       и их гетеры и сетеры, а так же сигналы уведомления.
    \param[WordsData] - конструктор класса без параметров
    \param[WordsData] - конструктор класса с параметрами. Сразу инициализирует и слова ипозицию в рейтинге.
    \param[word] - слово из рейтинга
    \param[count] - сколько раз слово найдено в тексте
*/

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
    QString m_word = "";
    int m_count = 0;
};

Q_DECLARE_METATYPE(WordsData)

#endif // WORDSDATA_H
