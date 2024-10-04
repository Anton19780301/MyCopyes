#ifndef REGISTRATION_H
#define REGISTRATION_H

/*
    регистрация классов для работы с QML
*/

#include <QSharedPointer>

class QQmlApplicationEngine;
class ProgrammActions;

class Registration
{


public:
    Registration(QQmlApplicationEngine *engine);

private:
    QSharedPointer<ProgrammActions> pa = nullptr;
};

#endif // REGISTRATION_H
