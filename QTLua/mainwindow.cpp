#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "luaworck.h"
#include "qdebug.h"
#include "draw.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Aftermatch");

    Draw::Instance();
    Draw::addMainWindow(this);

    LuaWorck *luaWorck = new LuaWorck();

    QObject::connect(ui->toolButton_run,&QToolButton::clicked,[=]()
    {
        luaWorck->runScript(ui->textBrowser_in->toPlainText());
    });
    QObject::connect(ui->toolButton_clear,&QToolButton::clicked,[=]()
    {
        ui->textBrowser_in->clear();
    });
    QObject::connect(ui->toolButton_outClear,&QToolButton::clicked,[=]()
    {
        ui->textBrowser_out->clear();
    });



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addToOut(const QString &text)
{
    ui->textBrowser_out->setText(ui->textBrowser_out->toPlainText() + text);
}

void MainWindow::clearOut()
{
    ui->textBrowser_out->clear();
}

void MainWindow::setScene(QGraphicsScene *scene)
{
    ui->graphicsView->setScene(scene);
}

