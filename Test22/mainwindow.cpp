#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _socket = new QTcpSocket(this);
    QObject::connect(_socket,&QTcpSocket::readyRead,[this](){this->read();});
    QObject::connect(_socket,&QTcpSocket::connected,[this](){ui->textBrowser->append("Connected to server.....");});
    QObject::connect(_socket,&QTcpSocket::errorOccurred,[this]()
    {
        ui->textBrowser->append(_socket->errorString());
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_connect_clicked()
{
    _socket->connectToHost(QHostAddress::LocalHost,6666);
}


void MainWindow::on_pushButton_send_clicked()
{
    this->write();
}

void MainWindow::read()
{
    QByteArray data = _socket->readAll();
    QDataStream _ds(&data,QIODevice::ReadOnly);
    if (_size == 0) _ds >> _size;
    if (_size > _allData.size())
    {
        _allData.append(data);
        qDebug() << "continue " << _size << _allData.size();
    }
    if (_size == _allData.size())
    {
        QString msg{};
        QPixmap pix{};
        QDataStream ads(&_allData,QIODevice::ReadOnly);
        ads >> _size >> msg >> pix;
        ui->textBrowser->append(msg);
        ui->label->setPixmap(pix);
        _size = 0;
        _allData.clear();
        _allData.resize(0);
    }
}

void MainWindow::write()
{
    QByteArray data;
    QDataStream out(&data,QIODevice::WriteOnly);
    QString msg = ui->lineEdit->text();
    out << msg;
    qDebug() << msg;
    _socket->write(data);
    _socket->flush();
}

