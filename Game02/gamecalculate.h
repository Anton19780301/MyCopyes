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
    Q_PROPERTY(QColor statecolor READ statecolor WRITE setStatecolor NOTIFY statecolorChanged)
    Q_PROPERTY(int xmax READ xmax WRITE setXmax NOTIFY xmaxChanged)
    Q_PROPERTY(int ymax READ ymax WRITE setYmax NOTIFY ymaxChanged)

    QColor statecolor() const;
    void setStatecolor(const QColor &newStatecolor);

    int xmax() const;
    void setXmax(int newXmax);

    int ymax() const;
    void setYmax(int newYmax);

public slots:
    void click(int x, int y); //проверим что там и если что откроем соседние клетки
    void reset(); //перезапуск игры
    void markFlag(int x, int y); //маркировка места флагом


signals:
    void statecolorChanged();
    void xmaxChanged();
    void ymaxChanged();

private:

    QObjectList *_dataZ = new QObjectList();
    CustomDataModel *bombCount[30][30] = {};
    QVector<QVector<CustomDataModel>> *_bombCount = {};

    void checkCells(int x, int y); //проверка необходимости открытия соседних клеток
    void updateModel(); //обновляет модель
    void checkToWin(); //проверить на выйгрыш
    void win();// выполняется если игра выйграна
    void lose();// выполняется если игра проиграна

    QColor m_statecolor = Qt::red;
    int m_xmax = 30;
    int m_ymax = 30;
};

#endif // GAMECALCULATE_H
