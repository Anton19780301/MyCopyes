#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDataStream>
#include <QHostAddress>

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
    void on_pushButton_connect_clicked();
    void on_pushButton_send_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *_socket{};
    QByteArray _allData{};
    qint64 _size{};
    void read();
    void write();

};
#endif // MAINWINDOW_H
