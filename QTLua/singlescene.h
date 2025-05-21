#ifndef SINGLESCENE_H
#define SINGLESCENE_H

#include "QGraphicsScene"

class SingleScene final : public QGraphicsScene
{
public:
    explicit SingleScene();
    ~SingleScene() = default;
    void drawCircle(int x, int y, int d);
    void drawSqere(int x, int y, int d);
    void background(int r, int g, int b);
    void line(int x0, int y0,int x1, int y1);

private:
    const int DIAMETER = 100;
};

#endif // SINGLESCENE_H
