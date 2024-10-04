#ifndef PROGRAMMACTIONS_H
#define PROGRAMMACTIONS_H

//! действия с QML
/*!
@brief действия с QML
    \param[ProgrammActions] - конструктор класса
    \param[namePB] - свйство, надпись на кнопке Пауза
    \param[len] - свойство, длинна элемента гистограммы
    \param[maxlenght] - свойство, максимальный размер файла анализируемого файла, передаётся в QML
    \param[curentbyte] - свойство, текущий байт анализируемого файла, передаётся в QML
    \param[pbtext] - свойство, вычисляемый текст для ProgressBar в QML
    \param[openFile] - метод сообщает классу FileCalculate имя файла для анализа
    \param[startCalculate] - начала анализа выбранного файла
    \param[pauseCalculate] - пауза
    \param[createThread] - метод устанавливает первоначальное состояние программы, выполняется при первом запуске и отмене анализа
    \param[cancelCalculate] - метод отменяет процесс вычисления, программа возвращается в первоначальное состояние
    \param[reiting] - сетер _reiting
    \param[setReiting] - публичный слот, принимает значения из FileCalculate
    \param[_timer] - таймер для разблокировки потока FileCalculate. Это часть механизма замедления обработки.
    \param[_reiting] - список рейтинговых слов, получен из FileCalculate. Основа модели данных в гистограмме
    \param[DELAY_TIME] - задержка обработки файла в микросекундах, уменьшите это значение до 1 и задержки почти не будет
    \param[RAITING_COUNT] - размер рейтинговой таблицы, менять не желательно. Увеличение знгачения 15 может вызвать поломку
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
    Q_PROPERTY(int len READ len WRITE setLen NOTIFY lenChanged) //длинна элемента гистограммы
    Q_PROPERTY(int maxlenght READ maxlenght WRITE setMaxlenght NOTIFY maxlenghtChanged)
    Q_PROPERTY(int curentbyte READ curentbyte WRITE setCurentbyte NOTIFY curentbyteChanged)
    Q_PROPERTY(QString pbtext READ pbtext WRITE setPbtext NOTIFY pbtextChanged)

    Q_INVOKABLE void openFile(QString fileName);
    Q_INVOKABLE void startCalculate();
    Q_INVOKABLE void pauseCalculate();
    Q_INVOKABLE void cancelCalculate();

    QString namePB() const;
    void setNamePB(const QString &newNamePB);
    void addObjectList(QVector<WordsData*> *reiting);

    QVector<WordsData*> *reiting() {return _reiting;}

    int len() const;
    void setLen(int newLen);
    int maxlenght() const;
    int curentbyte() const;

    QString pbtext() const;
    void setPbtext(const QString &newPbtext);

private slots:
    void setReiting(QVector<WordsData*> *reiting);
    void setMaxlenght(int newMaxlenght);
    void setCurentbyte(int newCurentbyte);

signals:
    void namePBChanged();
    void lenChanged();
    void maxlenghtChanged();
    void curentbyteChanged();
    void pbtextChanged();

private:
    const int DELAY_TIME = 150;
    const int RAITING_COUNT = 15;

    void createThread();

    FileCalculate *_fc = nullptr;
    QThread *_calculateThread = nullptr;
    QWaitCondition *_wc = nullptr;
    QMutex *_mx = nullptr;
    QTimer *_timer = nullptr;

    bool _pause = false;
    QString m_namePB = "Пауза";

    QVector<WordsData*> *_reiting = new QVector<WordsData*>();
    int m_len = 0;
    int m_maxlenght = 0;
    int m_curentbyte = 0;
    QString m_pbtext = "";
};

#endif // PROGRAMMACTIONS_H
