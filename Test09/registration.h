#ifndef REGISTRATION_H
#define REGISTRATION_H

//! регистрация классов для работы с QML
/*!
@brief регистрация классов для работы с QML, исключительно чтобы не писать лишнего в main.cpp
    \param[Registration] - конструктор класса, внутри происходит добавление пропетис в контекст QML
                           в том числе списка из которого сформирована модель
    \param[pa] - умный указатель на ProgrammActions
*/

#include <QSharedPointer>

class QQmlApplicationEngine;
class ProgrammActions;

class Registration
{
public:
    Registration(QQmlApplicationEngine &engine);

private:
    QSharedPointer<ProgrammActions> pa = nullptr;
};

#endif // REGISTRATION_H
