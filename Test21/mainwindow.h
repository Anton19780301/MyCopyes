#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSet>

class QTcpServer;
class QTcpSocket;
class QDataStream;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QByteArray *_data{};
    QDataStream *_out{};
    QTcpServer *_server{};
    QSet<QTcpSocket*> _clients{};

    void read(QTcpSocket *socket);
    void write();
};
#endif // MAINWINDOW_H
