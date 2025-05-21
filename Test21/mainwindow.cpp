#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include <QScreen>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _data = new QByteArray();
    _out = new QDataStream(_data,QIODevice::WriteOnly);
    _server = new QTcpServer(this);

    _server->listen(QHostAddress::Any,6666);

    QObject::connect(_server,&QTcpServer::newConnection,[this]()
    {
        QTcpSocket *_socket = _server->nextPendingConnection();
        ui->textBrowser->append("New connection " + QString::number(_socket->socketDescriptor()));
        _clients.insert(_socket);

        QObject::connect(_socket,&QTcpSocket::readyRead,[this,_socket](){ this->read(_socket);});
        QObject::connect(_socket,&QTcpSocket::errorOccurred,[this,_socket]()
        {
            ui->textBrowser->append(_socket->errorString());
        });
        QObject::connect(_socket,&QTcpSocket::stateChanged,[this,_socket]()
        {
            ui->textBrowser->append(&"New state " [ _socket->state()]);
        });



    });
    QObject::connect(_server,&QTcpServer::acceptError,[this]()
    {
        ui->textBrowser->append(_server->errorString());
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::read(QTcpSocket *socket)
{
    QByteArray data = socket->readAll();
    QDataStream in(&data,QIODevice::ReadOnly);
    qDebug() << data;
    QString msg{};
    in >> msg;
    ui->textBrowser->append(QString::number(socket->socketDescriptor()) + " : " + msg);
}

void MainWindow::write()
{
    for (auto &a: _clients)
    {
        QScreen *sc = QGuiApplication::screens()[0];
        QPixmap pix = sc->grabWindow(0);
        QByteArray data;
        QDataStream out(&data,QIODevice::WriteOnly);
        QString msg = "Message from server";
        out.device()->seek(8);
        out << msg << pix;
        qint64 size = data.size();
        out.device()->seek(0);
        out << size;
        a->write(data);
    }
}


void MainWindow::on_pushButton_clicked()
{
    this->write();
}
