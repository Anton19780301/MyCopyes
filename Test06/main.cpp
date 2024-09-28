#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <calclogic.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    CalcLogic *cl = new CalcLogic();

    engine.rootContext()->setContextProperty("cl",cl);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Test06", "Main");

    return app.exec();
}
