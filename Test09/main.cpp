#include <QGuiApplication>
#include <registration.h>
#include <QQmlApplicationEngine>

#include <programmactions.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    //Registration reg(&engine);

    ProgrammActions *pa = new ProgrammActions();
    QVector<WordsData*> *dataZ = new QVector<WordsData*>();
    pa->addObjectList(dataZ);

    engine.rootContext()->setContextProperty("dataZ",QVariant::fromValue(*dataZ));
    engine.rootContext()->setContextProperty("pa",pa);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Test09", "Main");

    return app.exec();
}
