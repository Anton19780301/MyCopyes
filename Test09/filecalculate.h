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
    void maxFileSizeChanged(int maxsize);
    void curentFilePosChanged(int pos);

public slots:
    void addFile(QString fileName);
    void cancelCalculate();
    void pause(bool pause);
    void startCalculate();

private:
    void fillAnaliseList();
    void calculateWords(QString line);
    void removeCharacters(QString &word); //удалитель символов из текста
    static bool comparatorListWS(WordsData *a, WordsData *b); //компоратор для сортировки
    static bool predicatListWS(const QString &a); //предикат для удаления
    inline static QStringList delList = {""," ","\n","\t", "\\","и"}; //список для исключения из подсчета слов
    QStringList remList = {".",",","!",":","-","[","]","(",")"}; //список для удаления символов, эти символы заменяться на пробел

    QString _fileName = "";
    QFile _inputFile;
    QWaitCondition *_wc = nullptr;
    QMutex *_mx = nullptr;
    bool _pause = false;
    int _fileSize = 0;
    int _curuentByte = 0;

    QVector<WordsData*> _wordsData = {};
    QVector<WordsData*> *_reiting = new QVector<WordsData*>();
};

#endif // FILECALCULATE_H
