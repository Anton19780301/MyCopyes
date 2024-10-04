#ifndef FILECALCULATE_H
#define FILECALCULATE_H

/*
    класс обрабатывает файл в отдельном потоке и отправляет статистику по словам в гистограмму
*/

#include <QObject>
#include <QFile>

class QTimer;
class QMutex;
class QWaitCondition;
class WordsData;

class FileCalculate : public QObject
{
    Q_OBJECT

public:
    explicit FileCalculate(QWaitCondition *wc, QMutex *mx);

signals:
    void raitingRecalculate(QVector<WordsData*> *reiting);

public slots:
    void addFile(QString fileName);
    void cancelCalculate();
    void pause(bool pause);

private:
    void startCalculate();
    void fillAnaliseList();
    void calculateWords(QString line);
    static bool comparatorListWS(WordsData *a, WordsData *b);

    QString _fileName = "";
    QFile _inputFile;
    QWaitCondition *_wc = nullptr;
    QMutex *_mx = nullptr;
    bool _pause = false;

    QVector<WordsData*> _wordsData = {};
    QVector<WordsData*> *_reiting = new QVector<WordsData*>();
};

#endif // FILECALCULATE_H
