#include "mainwindow.h"

#include <QApplication>

//sudo apt install lua5.3

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
