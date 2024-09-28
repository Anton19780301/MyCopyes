#ifndef CALCLOGIC_H
#define CALCLOGIC_H

#include <QObject>

class QTimer;

class CalcLogic : public QObject
{
    Q_OBJECT

    enum class Action{
        NONE,ADD,SUBSTRACT,MULT,DIV,EXP //ничего, сумма, вычесть, умножить, делить, возвести в степень
    };

public:
    explicit CalcLogic();
    Q_PROPERTY(QString indiacatorCondition READ indiacatorCondition WRITE setIndiacatorCondition NOTIFY indiacatorConditionChanged)
    Q_PROPERTY(QString memoryCondition READ memoryCondition WRITE setMemoryCondition NOTIFY memoryConditionChanged)
    Q_PROPERTY(QString actionCondition READ actionCondition WRITE setActionCondition NOTIFY actionConditionChanged)

    /*
        кнопки сделать покрасивее, круглее и с градиентом
    */

    Q_INVOKABLE void buttonPresed(QString buttonName);
    Q_INVOKABLE void beginFinalCountdown();
    Q_INVOKABLE void stopFinalCountdown();

    QString indiacatorCondition() const;
    void setIndiacatorCondition(const QString &newIndiacatorCondition);

    QString memoryCondition() const;
    void setMemoryCondition(const QString &newMemoryCondition);

    QString actionCondition() const;
    void setActionCondition(const QString &newActionCondition);


signals:
    void indiacatorConditionChanged();
    void memoryConditionChanged();
    void actionConditionChanged();
    void open();

private:
    const QString SECRET_PASSWORD = "123";
    const int MAXIMUM_NUMBERS = 25;

    void clear();
    void prepToCalculate(QString math);
    void calulate();
    void correct();

    QString m_indiacatorCondition = "";
    QString m_memoryCondition = "";
    QString m_actionCondition = "";

    Action _action = Action::NONE;

    QTimer *_timerFC = nullptr;
    QTimer *_timerBE = nullptr;
    bool pointcanpressed = true;
    bool secretMenuPasword = false;
};

#endif // CALCLOGIC_H
