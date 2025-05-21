#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <singlescene.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void addToOut(const QString &text);
    void clearOut();
    void setScene(QGraphicsScene *scene);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
