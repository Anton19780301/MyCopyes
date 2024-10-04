#include "registration.h"
#include <QGuiApplication>
#include <QQmlContext>
#include <qqmlapplicationengine.h>
#include <programmactions.h>
#include <QSharedPointer>
//#include <filecalculate.h>
#include <QQmlContext>
#include <QTimer>

Registration::Registration(QQmlApplicationEngine *engine)
{
    pa = QSharedPointer<ProgrammActions>::create();
    QVector<WordsData*> *dataZ = new QVector<WordsData*>();
    pa->addObjectList(dataZ);
    pa->restartGame();

    QTimer *_timer = new QTimer();
    QObject::connect(_timer,&QTimer::timeout,[this](){pa.get()->restartGame();});
    _timer->start(1000);

    engine->rootContext()->setContextProperty("dataZ",QVariant::fromValue(*dataZ));
    engine->rootContext()->setContextProperty("pa",pa.get());
}
