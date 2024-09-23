#ifndef GAMECALULATE_H
#define GAMECALULATE_H

#include <QObject>
#include <qqml.h>

class GameCalulate : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit GameCalulate();
    Q_INVOKABLE int moveLocation(QString id); //проверит куда может двигаться фишка, если никуда вернет 0
    Q_INVOKABLE void move(QString id);
    Q_INVOKABLE QString getModel(); //отдать модель в QML
    Q_INVOKABLE void blendGamePlace(); //перемешать кости

private:
    int _gamePlace[4][4] = {};
    void checkPlace();// проверка выйграша

};

#endif // GAMECALULATE_H
