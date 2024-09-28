#include "calclogic.h"
#include <qdebug.h>
#include <math.h>
#include <QTimer>

CalcLogic::CalcLogic()
{
    _timerFC = new QTimer(this);
    _timerBE = new QTimer(this);

    QObject::connect(_timerBE,&QTimer::timeout,[this](){
        _timerBE->stop();
        qDebug() << "654321";
        secretMenuPasword = false;
    });

    QObject::connect(_timerFC,&QTimer::timeout,[this](){
        secretMenuPasword = true;
        qDebug() << "12345678";
        _timerFC->stop();
        _timerBE->start(5000);
    });

}

void CalcLogic::buttonPresed(QString buttonName)
{
    if (buttonName == "0" ||
        buttonName == "1" ||
        buttonName == "2" ||
        buttonName == "3" ||
        buttonName == "4" ||
        buttonName == "5" ||
        buttonName == "6" ||
        buttonName == "7" ||
        buttonName == "8" ||
        buttonName == "9" ||
        buttonName == "."
        )
    {
        if (pointcanpressed &&
            buttonName == "." &&
            m_indiacatorCondition != "" &&
            m_indiacatorCondition.size() < MAXIMUM_NUMBERS)
        {
            QString forReturn = m_indiacatorCondition + buttonName;
            setIndiacatorCondition(forReturn);
            pointcanpressed = false;
        }
        else if (buttonName != "." && m_indiacatorCondition.size() < MAXIMUM_NUMBERS)
        {
            qDebug() << m_indiacatorCondition.size();
            QString forReturn = m_indiacatorCondition + buttonName;
            setIndiacatorCondition(forReturn);
        }
        if (secretMenuPasword)
        {
            if ( SECRET_PASSWORD == m_indiacatorCondition.right(3)) emit open();
        }

    }
    else if (buttonName == "a^b" ||
             buttonName == "*" ||
             buttonName == "/" ||
             buttonName == "+" ||
             buttonName == "-")
    {
        prepToCalculate(buttonName);
    }
    else if (buttonName == "=")
    {
        calulate();
    }
    else if (buttonName == "C")
    {
        clear();
    }
    else if (buttonName == "<-")
    {
        correct();
    }
}

void CalcLogic::beginFinalCountdown()
{
    _timerFC->start(4000);
}

void CalcLogic::stopFinalCountdown()
{
    _timerFC->stop();
}

QString CalcLogic::indiacatorCondition() const
{
    return m_indiacatorCondition;
}

void CalcLogic::setIndiacatorCondition(const QString &newIndiacatorCondition)
{
    if (m_indiacatorCondition == newIndiacatorCondition)
        return;
    m_indiacatorCondition = newIndiacatorCondition;
    emit indiacatorConditionChanged();
}

QString CalcLogic::memoryCondition() const
{
    return m_memoryCondition;
}

void CalcLogic::setMemoryCondition(const QString &newMemoryCondition)
{
    if (m_memoryCondition == newMemoryCondition)
        return;
    m_memoryCondition = newMemoryCondition;
    emit memoryConditionChanged();
}

void CalcLogic::clear()
{
    setActionCondition("");
    setMemoryCondition("");
    setIndiacatorCondition("");
    pointcanpressed = true;
}

void CalcLogic::prepToCalculate(QString math)
{
    if (m_indiacatorCondition != "" &&
        m_actionCondition == "" &&
        m_memoryCondition == "" )
    {
        setActionCondition(math);
        setMemoryCondition(m_indiacatorCondition);
        setIndiacatorCondition("");
        pointcanpressed = false;
    }

}

void CalcLogic::calulate()
{
    double result = 0.;

    double memoryCondition = 0.;
    double indiacatorCondition = 0.;

    if (m_memoryCondition != "") memoryCondition = m_memoryCondition.toDouble();
    if (m_indiacatorCondition != "") indiacatorCondition = m_indiacatorCondition.toDouble();

    qDebug() << m_memoryCondition << memoryCondition;
    qDebug() << m_actionCondition << m_actionCondition;

    switch (_action) {
    case Action::ADD:
        qDebug() << "ADD";
        result = memoryCondition + indiacatorCondition;
        break;
    case Action::SUBSTRACT:
        qDebug() << "SUBSTRACT";
        result = memoryCondition - indiacatorCondition;
        break;
    case Action::MULT:
        qDebug() << "MULT";
        result = memoryCondition * indiacatorCondition;
        break;
    case Action::DIV:
        qDebug() << "DIV";
        result = memoryCondition / indiacatorCondition;
        break;
    case Action::EXP:
        qDebug() << "EXP";
        result = pow(memoryCondition, indiacatorCondition);
        break;
    case Action::NONE:
        qDebug() << "NONE";
        break;
    }

        setActionCondition("");
        setMemoryCondition("");

        double num = QString::number(result).toDouble(NULL);
        QString s2 = QString::number(num, 'g', 25);

        setIndiacatorCondition(s2.toUtf8().constData());
}

void CalcLogic::correct()
{
    QString newStr = m_indiacatorCondition;
    if (m_indiacatorCondition != "") newStr.chop(1);
    setIndiacatorCondition(newStr);
}

QString CalcLogic::actionCondition() const
{
    return m_actionCondition;
}

void CalcLogic::setActionCondition(const QString &newActionCondition)
{
    if (m_actionCondition == newActionCondition)
        return;
    m_actionCondition = newActionCondition;
    if (newActionCondition == "") _action = Action::NONE;
    else if (newActionCondition == "+") _action = Action::ADD;
    else if (newActionCondition == "-") _action = Action::SUBSTRACT;
    else if (newActionCondition == "*") _action = Action::MULT;
    else if (newActionCondition == "/") _action = Action::DIV;
    else if (newActionCondition == "a^b") _action = Action::EXP;

    emit actionConditionChanged();
}

