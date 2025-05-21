#include "singlescene.h"
#include "qgraphicsitem.h"

SingleScene::SingleScene()
{

}

void SingleScene::drawCircle(int x, int y, int d)
{
    auto circle = new QGraphicsEllipseItem(x, y, d, d);
    circle->setBrush(Qt::green);
    this->addItem(circle);
}

void SingleScene::drawSqere(int x, int y, int d)
{
    QPen *pen = new QPen(Qt::red);
    QBrush *brush = new QBrush(Qt::green);
    this->addRect(x, y, d, d,*pen,*brush);
}

void SingleScene::background(int r, int g, int b)
{
    QBrush *brush = new QBrush(QColor(r,g,b));
    this->setBackgroundBrush(*brush);
}

void SingleScene::line(int x0, int y0, int x1, int y1)
{
    QPen *pen = new QPen(Qt::black);
    this->addLine(x0, y0, x1, y1, *pen);
}
