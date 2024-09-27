#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openFile(); //укажем файл для загрузки
    void setOpenFile(); //откроем файл с тзвестным именем
    void saveFile(); //запишем новый файл на диск
    void setSaveFile(); //укажем файл для записи
    void recalculateFile(); //создадим новый файл
    void setCalcState(); //выбор режима бинарного преобразования

private:
    enum class CalcState{
      AND,
      OR,
      XOR,
      NOT,
      Left,
      Right
    };

    Ui::MainWindow *ui;
    QSharedPointer<QFile> _fileOpen = nullptr;
    QSharedPointer<QFile> _fileSave = nullptr;
    QTimer *_openTimer = nullptr;
    QTimer *_saveTimer = nullptr;
    QSharedPointer<QByteArray> _fileOpenData = nullptr;
    QSharedPointer<QByteArray> _fileSaveData = nullptr;

    CalcState calcState = CalcState::AND;
    QString selectedSaveFileName = "";
    inline static int _filePrefix ;
    void calculateSaveFaileName();

};
#endif // MAINWINDOW_H
