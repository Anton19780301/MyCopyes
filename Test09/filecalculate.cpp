#include "filecalculate.h"
#include "wordsdata.h"
#include <qdebug.h>
#include <QFile>
#include <qtimer.h>
#include <QThread>
#include <QMutex>
#include <qwaitcondition.h>

#include <algorithm>


FileCalculate::FileCalculate(QWaitCondition *wc, QMutex *mx) :
    _mx(mx), _wc(wc)
{
    for (int a = 0 ; a < 15 ; ++a)
    {
        WordsData *wordForInsert = new WordsData();
        wordForInsert->setParent(this);
        _reiting->append(wordForInsert);
    }
}

void FileCalculate::addFile(QString fileName)
{
    _fileName = fileName;
}

void FileCalculate::startCalculate()
{
    if (_fileName != "") {
        qInfo() << _fileName;

        _inputFile.setFileName(_fileName);
        _inputFile.open(QIODevice::ReadOnly);
        if (!_inputFile.isOpen())
            return;

        _fileSize = _inputFile.size();

        QTextStream stream(&_inputFile);
        stream.setEncoding(QStringConverter::System);

        for (QString line = stream.readLine(); //тут можно поменять кодировку
             !line.isNull();
             line = stream.readLine())
        {
            const QMutexLocker locker(_mx);
            calculateWords(line);
            _wc->wait(_mx);
        };
        //анализ файла завершен
        _curuentByte = _fileSize;
        maxFileSizeChanged(_fileSize);
        curentFilePosChanged(_curuentByte);

    }
}

void FileCalculate::calculateWords(QString line)
{
    _curuentByte += line.length();
    bool wordFinded = false;
    qDebug() << "QString " << line;
    removeCharacters(line); //подчистим от ненужных символов
    QStringList lineSplit  = line.split(" ");
    lineSplit.removeIf(predicatListWS); //удалим слова пробелы итп

    qDebug() << "QStringList " << lineSplit;


    for (auto &newWord: lineSplit)
    {
        wordFinded = false;
        for (auto &oldWord: _wordsData)
        {
            if (oldWord->word() == newWord) {
                oldWord->setCount(oldWord->count() + 1);
                wordFinded = true;
                break;
            }
        }
        if (!wordFinded)
        {
            WordsData *wordForInsert = new WordsData(newWord,1);
            wordForInsert->setParent(this);
            _wordsData.append(wordForInsert);
        }

    }

    std::stable_sort(_wordsData.begin(),_wordsData.end(),comparatorListWS);

    _reiting->clear();
    if (_wordsData.count() > 15)
    {
        for (size_t i = 0;i<15;++i)
        {
            _reiting->append(_wordsData[i]);
        }
    }

    emit raitingRecalculate(_reiting);
    emit maxFileSizeChanged(_fileSize);
    emit curentFilePosChanged(_curuentByte);
}

void FileCalculate::removeCharacters(QString &word)
{
    for (const auto &as: remList)
    {
        word.replace(as," ");
    }
}

bool FileCalculate::comparatorListWS(WordsData *a, WordsData *b)
{
    return a->count() > b->count();
}

bool FileCalculate::predicatListWS(const QString &a)
{
    bool forReturn = false;
    for (const auto &del: delList)
    {
        if (a == del)
        {
            forReturn = true;
            break;
        }
    }
    return forReturn;
}

void FileCalculate::cancelCalculate()
{
    //TODO : возможно стоит просто удалять экземпляр этого класса
    _fileName = "";
}

void FileCalculate::pause(bool pause)
{
    _pause = pause;
    qInfo() << "_pause fc " << _pause;
}

