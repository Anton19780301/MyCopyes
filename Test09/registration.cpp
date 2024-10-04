#include "registration.h"
#include <QGuiApplication>
#include <QQmlContext>
#include <qqmlapplicationengine.h>
#include <programmactions.h>
#include <QSharedPointer>
//#include <filecalculate.h>
#include <QQmlContext>
#include <QTimer>

Registration::Registration(QQmlApplicationEngine &engine)
{
    pa = QSharedPointer<ProgrammActions>::create();
    QVector<WordsData*> *dataZ = new QVector<WordsData*>();
    pa->addObjectList(dataZ);

    engine.rootContext()->setContextProperty("dataZ",QVariant::fromValue(*dataZ));
    engine.rootContext()->setContextProperty("pa",pa.get());
}
