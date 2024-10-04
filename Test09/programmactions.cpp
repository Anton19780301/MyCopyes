#include "programmactions.h"
#include "filecalculate.h"
#include <qdebug.h>
#include <QThread>
#include <QWaitCondition>
#include <QMutex>
#include <QTimer>
#include <wordsdata.h>

ProgrammActions::ProgrammActions()
{
    _mx = new QMutex();
    _wc = new QWaitCondition();
    _fc = new FileCalculate(_wc,_mx);
    _calculateThread = new QThread(this);
    _fc->moveToThread(_calculateThread);
    _calculateThread->start();

    _timer = new QTimer(this);
    QObject::connect(_timer,&QTimer::timeout,[this](){
        if (!_pause) _wc->wakeAll();
    });
    _timer->start(DELAY_TIME);

    QObject::connect(_fc,&FileCalculate::raitingRecalculate,this,&ProgrammActions::setReiting);
}

ProgrammActions::~ProgrammActions()
{
    _calculateThread->deleteLater();
    qInfo() << "destroy registration";
}

void ProgrammActions::openFile(QString fileName)
{
    QString _fileName;
    _fileName = fileName.replace("file:///","");
    QMetaObject::invokeMethod(_fc,"addFile",_fileName);
}

void ProgrammActions::startCalculate()
{
    qInfo() << "start";
}

void ProgrammActions::pauseCalculate()
{
    _wc->wakeAll();
    if(_pause)
    {
        _pause = false;
        setNamePB("Пауза");
    }
    else
    {
        _pause = true;
        setNamePB("Продолжить");
    }
}

void ProgrammActions::cancelCalculate()
{
    qInfo() << "cancel";
}

QString ProgrammActions::namePB() const
{
    return m_namePB;
}

void ProgrammActions::setNamePB(const QString &newNamePB)
{
    if (m_namePB == newNamePB)
        return;
    m_namePB = newNamePB;
    emit namePBChanged();
}

void ProgrammActions::addObjectList(QVector<WordsData *> *reiting)
{
    _reiting = reiting;
    _reiting->clear();
    for(int x = 0;x < 15;++x)
    {
        WordsData *wordForInsert = new WordsData("" , 0);
        wordForInsert->setParent(this);
        _reiting->append(wordForInsert);
    }
}

void ProgrammActions::restartGame()
{

}

void ProgrammActions::setReiting(QVector<WordsData *> *reiting)
{
    qDebug() << "----------------------------";
    for (int x = 0;x < reiting->count();++x)
    {
        qDebug() << reiting->at(x)->word()  << reiting->at(x)->count();
        _reiting->at(x)->setWord(reiting->at(x)->word());
        _reiting->at(x)->setCount(reiting->at(x)->count());
    }
    if (reiting->count() > 0) setLen(reiting->at(0)->count());
    qDebug() << "----------------------------";
}

int ProgrammActions::len() const
{
    return m_len;
}

void ProgrammActions::setLen(int newLen)
{
    if (m_len == newLen)
        return;
    m_len = newLen;
    emit lenChanged();
}
