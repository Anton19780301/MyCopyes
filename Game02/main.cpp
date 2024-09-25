#include "gamecalculate.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <customdatamodel.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObjectList *dataZ = new QObjectList();
    GameCalculate *gc = new GameCalculate();
    gc->addObjectList(dataZ);
    gc->restartGame();

    engine.rootContext()->setContextProperty("dataZ",QVariant::fromValue(*dataZ));
    engine.rootContext()->setContextProperty("gc",gc);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.loadFromModule("Game02", "Main");

    return app.exec();
}
