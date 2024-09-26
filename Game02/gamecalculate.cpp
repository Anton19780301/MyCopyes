#include "gamecalculate.h"
#include "QDebug"
#include <QRandomGenerator64>
#include <customdatamodel.h>

GameCalculate::GameCalculate()
{
    for(int y = 0;y<m_ymax;++y)
    {
        for(int x = 0;x<m_xmax;++x)
        {
            bombCount[x][y] = new CustomDataModel();
            bombCount[x][y]->setVisible(true);
            bombCount[x][y]->setName("0");
            bombCount[x][y]->setXID(x);
            bombCount[x][y]->setYID(y);
            bombCount[x][y]->setFlagMarker(false);
        }
    }




}

void GameCalculate::click(int x, int y)
{
    bombCount[x][y]->setVisible(false);
    qDebug() <<  bombCount[x][y]->name();
    if (bombCount[x][y]->name() == "") //только если не наступили на бомбу
    {
        GameCalculate::checkCells(x,y);
        checkToWin();
    }
    else if (bombCount[x][y]->name() != "B" && bombCount[x][y]->name() != "0")
    {
        bombCount[x][y]->setVisible(false);
    }
    else if (bombCount[x][y]->name() == "B")
    {
        lose();
    }

    updateModel();
    checkToWin();
}

void GameCalculate::reset()
{
    restartGame();
    updateModel();
}

void GameCalculate::markFlag(int x, int y)
{
    bombCount[x][y]->setFlagMarker(!bombCount[x][y]->flagMarker());
    checkToWin();
}

void GameCalculate::checkCells(int x, int y)
{
    //переберем соседние клетки и раскроем те где нет бомбы
    if (x >= 0 && y-1 >= 0 && bombCount[x][y-1]->name() != "B" && bombCount[x][y]->name() == "" && bombCount[x][y-1]->visible())
    {
        bombCount[x][y-1]->setVisible(false); //верх
        checkCells(x,y-1);
    }

    if (x+1 < m_xmax && y >= 0 && bombCount[x+1][y]->name() != "B" && bombCount[x][y]->name() == "" && bombCount[x+1][y]->visible())
    {
        bombCount[x+1][y]->setVisible(false); //право
        checkCells(x+1,y);
    }

    if (x >= 0 && y+1 < m_ymax && bombCount[x][y+1]->name() != "B" && bombCount[x][y]->name() == "" && bombCount[x][y+1]->visible())
    {
        bombCount[x][y+1]->setVisible(false); //вниз
        checkCells(x,y+1);
    }

    if (x-1 >= 0 && y < m_ymax && bombCount[x-1][y]->name() != "B" && bombCount[x][y]->name() == "" && bombCount[x-1][y]->visible())
    {
        bombCount[x-1][y]->setVisible(false); // лево
        checkCells(x-1,y);
    }
}

void GameCalculate::updateModel()
{
    for(int y = 0;y<m_ymax;++y)
    {
        for(int x = 0;x<m_xmax;++x)
        {
            _dataZ->append(bombCount[x][y]);
        }
    }
}

void GameCalculate::checkToWin()
{
    int countBomb = 0;
    for(int y = 0;y<m_ymax;++y)
    {
        for(int x = 0;x<m_xmax;++x)
        {
            if (bombCount[x][y]->name() == "B" &&
                bombCount[x][y]->flagMarker() == false)
            {
                countBomb++;
            }
        }
    }
    qDebug() << "осталось бомб " << countBomb;
    if (countBomb < 1) win();
}

void GameCalculate::win()
{
    setStatecolor(Qt::green);
}

void GameCalculate::lose()
{
    qDebug() << "this the end.... ";
    for(int y = 0;y<m_ymax;++y)
    {
        for(int x = 0;x<m_xmax;++x)
        {
            bombCount[x][y]->setVisible(false);
        }
    }
    setStatecolor(Qt::red);
}

void GameCalculate::restartGame()
{
    for(int y = 0;y<m_ymax;++y)
    {
        for(int x = 0;x<m_xmax;++x)
        {
            bombCount[x][y]->setVisible(true);
            bombCount[x][y]->setName("0");
            bombCount[x][y]->setXID(x);
            bombCount[x][y]->setYID(y);
            bombCount[x][y]->setFlagMarker(false);
        }
    }

    _dataZ->clear();

    //растановка бомб и маркеров
    for(int y = 0;y<m_ymax;++y)
    {
        for(int x = 0;x<m_xmax;++x)
        {
            int isBomb = QRandomGenerator64().global()->bounded(0,100);
            if (isBomb < 15) //isBomb < 2   //x == 0 && y == 0
            {
                bombCount[x][y]->setName("B");
                //переберем соседние клетки и расставим маркеры
                if (x-1 >= 0 && y-1 >= 0 && bombCount[x-1][y-1]->name() != "B") bombCount[x-1][y-1]->setName(QString::number(bombCount[x-1][y-1]->name().toInt() + 1)); //лево верх
                if (x >= 0 && y-1 >= 0 && bombCount[x][y-1]->name() != "B") bombCount[x][y-1]->setName(QString::number(bombCount[x][y-1]->name().toInt() + 1)); //верх
                if (x+1 < m_xmax && y-1 >= 0 && bombCount[x+1][y-1]->name() != "B") bombCount[x+1][y-1]->setName(QString::number(bombCount[x+1][y-1]->name().toInt() + 1)); //право верх
                if (x+1 < m_xmax && y >= 0 && bombCount[x+1][y]->name() != "B") bombCount[x+1][y]->setName(QString::number(bombCount[x+1][y]->name().toInt() + 1)); //право
                if (x+1 < m_xmax && y+1 < m_ymax && bombCount[x+1][y+1]->name() != "B") bombCount[x+1][y+1]->setName(QString::number(bombCount[x+1][y+1]->name().toInt() + 1)); //право низ
                if (x >= 0 && y+1 < m_ymax && bombCount[x][y+1]->name() != "B") bombCount[x][y+1]->setName(QString::number(bombCount[x][y+1]->name().toInt() + 1)); //вниз
                if (x-1 >= 0 && y+1 < m_ymax && bombCount[x-1][y+1]->name() != "B") bombCount[x-1][y+1]->setName(QString::number(bombCount[x-1][y+1]->name().toInt() + 1)); //вниз лево
                if (x-1 >= 0 && y < m_ymax && bombCount[x-1][y]->name() != "B") bombCount[x-1][y]->setName(QString::number(bombCount[x-1][y]->name().toInt() + 1)); // лево
            }
        }
    }

    //уберем нули
    for(int y = 0;y<m_ymax;++y)
    {
        for(int x = 0;x<m_xmax;++x)
        {
            if (bombCount[x][y]->name() == "0") bombCount[x][y]->setName("");
        }
    }

    updateModel();
    setStatecolor(Qt::yellow);
}

QColor GameCalculate::statecolor() const
{
    return m_statecolor;
}

void GameCalculate::setStatecolor(const QColor &newStatecolor)
{
    if (m_statecolor == newStatecolor)
        return;
    m_statecolor = newStatecolor;
    emit statecolorChanged();
}

int GameCalculate::xmax() const
{
    return m_xmax;
}

void GameCalculate::setXmax(int newXmax)
{
    if (m_xmax == newXmax)
        return;
    m_xmax = newXmax;
    emit xmaxChanged();
}

int GameCalculate::ymax() const
{
    return m_ymax;
}

void GameCalculate::setYmax(int newYmax)
{
    if (m_ymax == newYmax)
        return;
    m_ymax = newYmax;
    emit ymaxChanged();
}
