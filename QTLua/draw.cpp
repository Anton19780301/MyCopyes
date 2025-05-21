#include "draw.h"
#include "mainwindow.h"

Draw &Draw::Instance()
{
    static Draw theSingleInstance;
    return theSingleInstance;
}

void Draw::addMainWindow(MainWindow *mw)
{
    _mw = mw;
    _mw->setScene(_scene);
}

void Draw::drawCircle(int x, int y, int d)
{
    _mw->addToOut("Draw Circle " + QString::number(x) +
                  " " + QString::number(y) + " " +
                  QString::number(d) + "\n");
    _scene->drawCircle(x,y,d);
}

void Draw::drawSqere(int x, int y, int d)
{
    _mw->addToOut("Draw Sqere " + QString::number(x) + " " +
                  QString::number(y) + " " + QString::number(d) + "\n");
    _scene->drawSqere(x,y,d);
}

void Draw::clear()
{
    _mw->addToOut("Clear area ");
    _scene->clear();
}

void Draw::backround(int r, int g, int b)
{
    _mw->addToOut("Set background " +
                  QString::number(r) + " " +
                  QString::number(g) + " " +
                  QString::number(b));
    _scene->background(r,g,b);
}

void Draw::line(int x0, int y0, int x1, int y1)
{
    _mw->addToOut("line " +
                  QString::number(x0) + " " +
                  QString::number(y0) + " " +
                  QString::number(x1) + " " +
                  QString::number(y1) + "\n");
    _scene->line(x0, y0, x1, y1);
}

Draw::Draw()
{
    _scene = new SingleScene();
}
