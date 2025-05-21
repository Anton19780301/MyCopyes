#ifndef DRAW_H
#define DRAW_H

class MainWindow;
class SingleScene;

class Draw
{
public:
    static Draw& Instance();
    static void addMainWindow(MainWindow *mw);
    static void drawCircle(int x, int y, int d);
    static void drawSqere(int x, int y, int d);
    static void clear();
    static void backround(int r, int g, int b);
    static void line(int x0, int y0,int x1, int y1);

private:
    explicit Draw();
    ~Draw() = default;
    inline static SingleScene *_scene = nullptr;
    inline static MainWindow *_mw = nullptr;
};

#endif // DRAW_H
