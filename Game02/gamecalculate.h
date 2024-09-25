#ifndef GAMECALCULATE_H
#define GAMECALCULATE_H

#include "customdatamodel.h"
#include <QObject>
#include <QColor>

class GameCalculate : public QObject
{
    Q_OBJECT

public:
    explicit GameCalculate();

    void addObjectList(QObjectList *list){_dataZ = list;}
    void restartGame(); //сформируем новое поле с новыми параметрами
    Q_PROPERTY(QColor statecolor READ statecolor WRITE setStatecolor NOTIFY statecolorChanged FINAL)


    QColor statecolor() const;
    void setStatecolor(const QColor &newStatecolor);

public slots:
    void click(int x, int y); //проверим что там и если что откроем соседние клетки
    void reset(); //перезапуск игры
    void markFlag(int x, int y); //маркировка места флагом


signals:
    void statecolorChanged();

private:
    int _x = 10;
    int _y = 10;

    QObjectList *_dataZ = new QObjectList();
    CustomDataModel *bombCount[10][10] = {};

    void checkCells(int x, int y); //проверка необходимости открытия соседних клеток
    void updateModel(); //обновляет модель
    void checkToWin(); //проверить на выйгрыш
    void win();// выполняется если игра выйграна
    void lose();// выполняется если игра проиграна

    QColor m_statecolor = Qt::red;
};

#endif // GAMECALCULATE_H
