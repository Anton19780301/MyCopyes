#include "gamecalulate.h"
#include "QDebug"
#include <QRandomGenerator64>

GameCalulate::GameCalulate()
{
    _gamePlace[0][0] = 1;
    _gamePlace[1][0] = 2;
    _gamePlace[2][0] = 3;
    _gamePlace[3][0] = 4;
    _gamePlace[0][1] = 5;
    _gamePlace[1][1] = 6;
    _gamePlace[2][1] = 7;
    _gamePlace[3][1] = 8;
    _gamePlace[0][2] = 9;
    _gamePlace[1][2] = 10;
    _gamePlace[2][2] = 11;
    _gamePlace[3][2] = 12;
    _gamePlace[0][3] = 13;
    _gamePlace[1][3] = 15;
    _gamePlace[2][3] = 14;
    _gamePlace[3][3] = 0;

    this->blendGamePlace();
}

int GameCalulate::moveLocation(QString id)
{
    /*
    направления движения 1 - лево, 2 - верх, 3 - право, 4 низ
    */

    //найдем нашу фишку в списке
    int xDc = 0;
    int yDc = 0;
    int xD0 = 0;
    int yD0 = 0;

    for(int y = 0;y<4;++y)
    {
        for(int x = 0;x<4;++x)
        {
            if(_gamePlace[x][y] == id.toInt())
            {
                xDc = x;
                yDc = y;
            }
        }
    }

    for(int y = 0;y<4;++y)
    {
        for(int x = 0;x<4;++x)
        {
            if(_gamePlace[x][y] == 0)
            {
                xD0 = x;
                yD0 = y;
            }
        }
    }

    //возможно движение влево
    if (yDc == yD0 && xDc == xD0 + 1) return 1;

    //возможно движение вверх
    if (xDc == xD0 && yDc == yD0 + 1) return 2;

    //возможно движение вправо
    if (yDc == yD0 && xDc == xD0 - 1) return 3;

    //возможно движение вниз
    if (xDc == xD0 && yDc == yD0 - 1) return 4;

    return 0;
}

void GameCalulate::move(QString id)
{
    //найдем нашу фишку в списке
    int xDc = 0;
    int yDc = 0;
    int xD0 = 0;
    int yD0 = 0;

    for(int y = 0;y<4;++y)
    {
        for(int x = 0;x<4;++x)
        {
            if(_gamePlace[x][y] == id.toInt())
            {
                xDc = x;
                yDc = y;
            }
        }
    }

    for(int y = 0;y<4;++y)
    {
        for(int x = 0;x<4;++x)
        {
            if(_gamePlace[x][y] == 0)
            {
                xD0 = x;
                yD0 = y;
            }
        }
    }
    _gamePlace[xD0][yD0] = _gamePlace[xDc][yDc];
    _gamePlace[xDc][yDc] = 0;

    checkPlace();
}

QString GameCalulate::getModel()
{
    QString forReturn = "";
    for(int y = 0;y<4;++y)
    {
        for(int x = 0;x<4;++x)
        {
            forReturn.append(QString::number(_gamePlace[x][y])+ ",");
        }
    }
    return forReturn;
}

void GameCalulate::blendGamePlace()
{
    QList<int> alco = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    for(int y = 0;y<4;++y)
    {
        for(int x = 0;x<4;++x)
        {
            int value = QRandomGenerator64::global()->bounded(0,alco.size());
            qDebug() << value;
            _gamePlace[x][y] = alco [value];
            alco.removeAt(value);
        }
    }
}

void GameCalulate::checkPlace()
{
    if( _gamePlace[0][0] == 1 &&
        _gamePlace[1][0] == 2 &&
        _gamePlace[2][0] == 3 &&
        _gamePlace[3][0] == 4 &&
        _gamePlace[0][1] == 5 &&
        _gamePlace[1][1] == 6 &&
        _gamePlace[2][1] == 7 &&
        _gamePlace[3][1] == 8 &&
        _gamePlace[0][2] == 9 &&
        _gamePlace[1][2] == 10 &&
        _gamePlace[2][2] == 11 &&
        _gamePlace[3][2] == 12 &&
        _gamePlace[0][3] == 13 &&
        _gamePlace[1][3] == 14 &&
        _gamePlace[2][3] == 15 &&
        _gamePlace[3][3] == 0
        )
    {
        qDebug() << "Game over - is OK";
    }
}
