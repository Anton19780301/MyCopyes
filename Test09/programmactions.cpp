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
    createThread();
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
    QMetaObject::invokeMethod(_fc,"startCalculate");
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
    QMetaObject::invokeMethod(_fc,"cancelCalculate");
    _calculateThread->terminate();
    for(int x = 0;x < RAITING_COUNT;++x)
    {
        _reiting->at(x)->setWord("");
        _reiting->at(x)->setCount(0);
    }

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
    for(int x = 0;x < RAITING_COUNT;++x)
    {
        WordsData *wordForInsert = new WordsData("" , 0);
        wordForInsert->setParent(this);
        _reiting->append(wordForInsert);
    }
}

void ProgrammActions::setReiting(QVector<WordsData *> *reiting)
{
    for (int x = 0;x < reiting->count();++x)
    {
        qDebug() << _reiting->at(x)->word();
        _reiting->at(x)->setWord(reiting->at(x)->word());
        _reiting->at(x)->setCount(reiting->at(x)->count());
    }
    if (reiting->count() > 0) setLen(reiting->at(0)->count());
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

int ProgrammActions::maxlenght() const
{
    return m_maxlenght;
}

void ProgrammActions::setMaxlenght(int newMaxlenght)
{
    if (m_maxlenght == newMaxlenght)
        return;
    m_maxlenght = newMaxlenght;
    emit maxlenghtChanged();
    if (m_maxlenght > 0)
    {
        int as = (int)((double)m_curentbyte/(double)m_maxlenght * 100.);
        setPbtext(QString::number(as) + "%");
    }
}

int ProgrammActions::curentbyte() const
{
    return m_curentbyte;
}

void ProgrammActions::setCurentbyte(int newCurentbyte)
{
    if (m_curentbyte == newCurentbyte)
        return;
    m_curentbyte = newCurentbyte;
    emit curentbyteChanged();
    if (m_maxlenght > 0)
    {
        int as = (int)((double)m_curentbyte/(double)m_maxlenght * 100.);
        setPbtext(QString::number(as) + "%");
    }
}

void ProgrammActions::createThread()
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
    QObject::connect(_fc,&FileCalculate::maxFileSizeChanged,this,&ProgrammActions::setMaxlenght);
    QObject::connect(_fc,&FileCalculate::curentFilePosChanged,this,&ProgrammActions::setCurentbyte);

    QObject::connect(_calculateThread,&QThread::finished,[this]()
                     {
                         qDebug() << "finished";
                         createThread();
                     });


}

QString ProgrammActions::pbtext() const
{
    return m_pbtext;
}

void ProgrammActions::setPbtext(const QString &newPbtext)
{
    if (m_pbtext == newPbtext)
        return;
    m_pbtext = newPbtext;
    emit pbtextChanged();
}
