#ifndef PROGRAMMACTIONS_H
#define PROGRAMMACTIONS_H

/*
    действия внутри QML
*/

#include "wordsdata.h"
#include <QObject>

class FileCalculate;
class QThread;
class QWaitCondition;
class QMutex;
class QTimer;

class ProgrammActions : public QObject
{
    Q_OBJECT
public:
    explicit ProgrammActions();
    ~ProgrammActions();

    Q_PROPERTY(QString namePB READ namePB WRITE setNamePB NOTIFY namePBChanged)
    Q_PROPERTY(int len READ len WRITE setLen NOTIFY lenChanged FINAL)

    Q_INVOKABLE void openFile(QString fileName);
    Q_INVOKABLE void startCalculate();
    Q_INVOKABLE void pauseCalculate();
    Q_INVOKABLE void cancelCalculate();

    QString namePB() const;
    void setNamePB(const QString &newNamePB);
    void addObjectList(QVector<WordsData*> *reiting);
    void restartGame();

    QVector<WordsData*> *reiting() {return _reiting;}

    int len() const;
    void setLen(int newLen);

public slots:
    void setReiting(QVector<WordsData*> *reiting);

signals:
    void namePBChanged();

    void lenChanged();

private:
    const int DELAY_TIME = 1000; //задержка обработки файла

    FileCalculate *_fc = nullptr;
    QThread *_calculateThread = nullptr;
    QWaitCondition *_wc = nullptr;
    QMutex *_mx = nullptr;
    QTimer *_timer = nullptr;

    bool _pause = false;
    QString m_namePB = "Пауза";

    QVector<WordsData*> *_reiting = new QVector<WordsData*>();
    int m_len = 0;
};

#endif // PROGRAMMACTIONS_H
