#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "luaworck.h"
#include "qdebug.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Aftermatch");


    LuaWorck *luaWorck = new LuaWorck(this);
    QObject::connect(ui->toolButton_run,&QToolButton::clicked,[=]()
    {
        luaWorck->runScript(ui->textBrowser_in->toPlainText());
    });
    QObject::connect(ui->toolButton_clear,&QToolButton::clicked,[=]()
    {
        ui->textBrowser_in->clear();
        ui->textBrowser_out->clear();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addToOut(const QString &text)
{
    ui->textBrowser_out->setText(ui->textBrowser_in->toPlainText() + text);
}

void MainWindow::clearOut()
{
    ui->textBrowser_out->clear();
}

