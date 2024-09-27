#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDataStream>
#include <QSharedPointer>
#include <QTimer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Бинарное преобразование файлов");

    _filePrefix = 0;

    _fileOpen = QSharedPointer<QFile>::create();
    _fileSave = QSharedPointer<QFile>::create();
    _fileOpenData = QSharedPointer<QByteArray>::create();
    _fileSaveData = QSharedPointer<QByteArray>::create();

    //TODO : добавить регулятор таймера
    _openTimer = new QTimer(this);
    _saveTimer = new QTimer(this);
    _openTimer->setInterval(1000);
    _saveTimer->setInterval(1000);

    QObject::connect(_openTimer,&QTimer::timeout,this,&MainWindow::openFile);
    QObject::connect(_saveTimer,&QTimer::timeout,this,&MainWindow::saveFile);

    QObject::connect(ui->toolButton_fileIn_select,&QToolButton::clicked,this,&MainWindow::setOpenFile);
    QObject::connect(ui->toolButton_fileOut_select,&QToolButton::clicked,this,&MainWindow::setSaveFile);
    QObject::connect(ui->comboBox_action,&QComboBox::currentTextChanged,this,&MainWindow::setCalcState);
    QObject::connect(ui->comboBox_fileOverridePolicy,&QComboBox::currentTextChanged,this,[this](){calculateSaveFaileName();});
    QObject::connect(ui->spinBox_binaryOperationValue,&QSpinBox::textChanged,[this](){this->recalculateFile();});
    QObject::connect(ui->toolButton_fileOnceSave,&QToolButton::clicked,this,&MainWindow::saveFile);

    QObject::connect(ui->spinBox_repeat_foTime,&QSpinBox::textChanged,[this](){
        //изменение времени записи
        if(ui->checkBox_forSaveTimer->checkState() == Qt::Checked)
        {
            _saveTimer->setInterval(ui->spinBox_repeat_foTime->value()*1000);
        }
    });
    QObject::connect(ui->spinBox_repeat_checkFile,&QSpinBox::textChanged,[this](){
        //изменение времени проверки файла
        if(ui->checkBox_forOpenTimer->checkState() == Qt::Checked)
        {
            _saveTimer->setInterval(ui->spinBox_repeat_checkFile->value()*1000);
        }
    });

    QObject::connect(ui->checkBox_forSaveTimer,&QCheckBox::stateChanged,[this](){
        if (ui->checkBox_forSaveTimer->checkState() == Qt::Checked) _saveTimer->start();
        else _saveTimer->stop();
    });
    QObject::connect(ui->checkBox_forOpenTimer,&QCheckBox::stateChanged,[this](){
        if (ui->checkBox_forOpenTimer->checkState() == Qt::Checked) _openTimer->start();
        else _openTimer->stop();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setOpenFile()
{
    if (_fileOpen->isOpen()) _fileOpen->close();
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open file"), "C:\\", tr("Binary files (*.txt *.bin)"));
    _fileOpen->setFileName(fileName);
    openFile();
}

//открытие файла
void MainWindow::openFile()
{
    if (!_fileOpen->fileName().isEmpty() && !_fileOpen->isOpen())
    {
        if(!_fileOpen->open(QIODevice::ReadOnly)) {
            qDebug() << "save file opened " << _fileOpen->errorString();
        }
        ui->label__open_file->setText(_fileOpen.get()->fileName());
        recalculateFile();
    }
}

void MainWindow::setSaveFile()
{
    _fileSave.get()->setFileName("");
    selectedSaveFileName = QFileDialog::getOpenFileName(this,tr("Open file"), "C:\\", tr("Binary files (*.txt *.bin)"));

    //откроем файл и вычислим имя для записи
    _fileSave->setFileName(selectedSaveFileName);
    calculateSaveFaileName();
    ui->label__save_file->setText(_fileSave->fileName());
}

void MainWindow::recalculateFile()
{
    ui->textBrowser_income->setText("");
    ui->textBrowser_output->setText("");
    _fileSaveData.data()->clear();
    int c = ui->spinBox_binaryOperationValue->value();
    _fileOpenData->append(_fileOpen->readAll());

    switch (calcState) {
    case CalcState::AND:
        for(int a:*_fileOpenData)
        {
            _fileSaveData->append(a & c);
        }
        break;
    case CalcState::OR:
        for(auto a:*_fileOpenData)
        {
            _fileSaveData->append(a | c);
        }
        break;
    case CalcState::XOR:
        for(auto a:*_fileOpenData)
        {
            _fileSaveData->append(a ^ c);
        }
        break;
    case CalcState::NOT:
        for(auto a:*_fileOpenData)
        {
            _fileSaveData->append(~a);
        }
        break;
    case CalcState::Left:
        for(auto a:*_fileOpenData)
        {
            _fileSaveData->append(a << c);
        }
        break;
    case CalcState::Right:
        for(auto a:*_fileOpenData)
        {
            _fileSaveData->append(a >> c);
        }
        break;
    }

    ui->textBrowser_income->setText(*_fileOpenData);
    ui->textBrowser_output->setText(*_fileSaveData);
}

void MainWindow::setCalcState()
{
    if (ui->comboBox_action->currentText() == "AND")  calcState = CalcState::AND;
    if (ui->comboBox_action->currentText() == "OR")  calcState = CalcState::OR;
    if (ui->comboBox_action->currentText() == "XOR")  calcState = CalcState::XOR;
    if (ui->comboBox_action->currentText() == "NOT")  calcState = CalcState::NOT;
    if (ui->comboBox_action->currentText() == "Left")  calcState = CalcState::Left;
    if (ui->comboBox_action->currentText() == "Right")  calcState = CalcState::Right;
    recalculateFile();
}

void MainWindow::calculateSaveFaileName()
{
    if (_fileSave.get()->fileName() != "")
    {
        QStringList fileName = selectedSaveFileName.split(".");
        QString file = fileName[0];
        QString exten = fileName[1];
        _filePrefix += 1;
        if (ui->comboBox_fileOverridePolicy->currentIndex() == 1)
        {
            _fileSave.get()->setFileName(file + "_" + QString::number(_filePrefix) + "." + exten);
        }
        else
        {
            _fileSave.get()->setFileName(selectedSaveFileName);
        }
    }
}

void MainWindow::saveFile()
{
    //если имя надо менять вычислим его еще раз
    calculateSaveFaileName();

    if (_fileOpen.get()->fileName() != "" && _fileSave.get()->fileName() != "")
    {
        if(_fileSave->open(QIODevice::WriteOnly))
        {
            qDebug() << "open file " << _fileOpen.get()->fileName();
            qDebug() << "save file " << _fileSave.get()->fileName();
            qDebug() << *_fileOpenData;
            qDebug() << *_fileSaveData;
            ui->label__save_file->setText(_fileSave->fileName());
            _fileSave.data()->write(*_fileSaveData);
            _fileSave->close();
        }
        else
        {
            qDebug() <<  "save file error " << _fileSave->errorString();
        }
    }
}
