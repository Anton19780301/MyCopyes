/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QToolButton *toolButton_fileIn_select;
    QCheckBox *checkBox_fileRemove;
    QLabel *label_3;
    QToolButton *toolButton_fileOut_select;
    QLabel *label_4;
    QComboBox *comboBox_fileOverridePolicy;
    QToolButton *toolButton_fileOnceSave;
    QCheckBox *checkBox_forSaveTimer;
    QSpinBox *spinBox_repeat_foTime;
    QLabel *label_5;
    QSpinBox *spinBox_repeat_checkFile;
    QLabel *label_7;
    QLabel *label_8;
    QSpinBox *spinBox_binaryOperationValue;
    QLabel *label_9;
    QComboBox *comboBox_action;
    QCheckBox *checkBox_forOpenTimer;
    QLabel *label__open_file;
    QLabel *label__save_file;
    QWidget *tab_2;
    QTextBrowser *textBrowser_income;
    QWidget *tab_3;
    QTextBrowser *textBrowser_output;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(450, 400);
        MainWindow->setMinimumSize(QSize(450, 400));
        MainWindow->setMaximumSize(QSize(450, 400));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 450, 400));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setMinimumSize(QSize(0, 0));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 137, 16));
        toolButton_fileIn_select = new QToolButton(tab);
        toolButton_fileIn_select->setObjectName(QString::fromUtf8("toolButton_fileIn_select"));
        toolButton_fileIn_select->setGeometry(QRect(365, 20, 22, 22));
        checkBox_fileRemove = new QCheckBox(tab);
        checkBox_fileRemove->setObjectName(QString::fromUtf8("checkBox_fileRemove"));
        checkBox_fileRemove->setGeometry(QRect(10, 50, 171, 20));
        checkBox_fileRemove->setChecked(true);
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 91, 137, 16));
        toolButton_fileOut_select = new QToolButton(tab);
        toolButton_fileOut_select->setObjectName(QString::fromUtf8("toolButton_fileOut_select"));
        toolButton_fileOut_select->setGeometry(QRect(365, 90, 22, 22));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 120, 141, 81));
        comboBox_fileOverridePolicy = new QComboBox(tab);
        comboBox_fileOverridePolicy->addItem(QString());
        comboBox_fileOverridePolicy->addItem(QString());
        comboBox_fileOverridePolicy->setObjectName(QString::fromUtf8("comboBox_fileOverridePolicy"));
        comboBox_fileOverridePolicy->setGeometry(QRect(160, 150, 200, 20));
        toolButton_fileOnceSave = new QToolButton(tab);
        toolButton_fileOnceSave->setObjectName(QString::fromUtf8("toolButton_fileOnceSave"));
        toolButton_fileOnceSave->setGeometry(QRect(365, 129, 61, 61));
        checkBox_forSaveTimer = new QCheckBox(tab);
        checkBox_forSaveTimer->setObjectName(QString::fromUtf8("checkBox_forSaveTimer"));
        checkBox_forSaveTimer->setGeometry(QRect(10, 208, 181, 31));
        spinBox_repeat_foTime = new QSpinBox(tab);
        spinBox_repeat_foTime->setObjectName(QString::fromUtf8("spinBox_repeat_foTime"));
        spinBox_repeat_foTime->setGeometry(QRect(240, 216, 51, 22));
        spinBox_repeat_foTime->setMinimum(1);
        spinBox_repeat_foTime->setMaximum(60);
        spinBox_repeat_foTime->setSingleStep(1);
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(300, 220, 49, 16));
        spinBox_repeat_checkFile = new QSpinBox(tab);
        spinBox_repeat_checkFile->setObjectName(QString::fromUtf8("spinBox_repeat_checkFile"));
        spinBox_repeat_checkFile->setGeometry(QRect(240, 248, 51, 22));
        spinBox_repeat_checkFile->setMinimum(1);
        spinBox_repeat_checkFile->setMaximum(60);
        spinBox_repeat_checkFile->setSingleStep(1);
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(300, 250, 49, 16));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 290, 231, 16));
        spinBox_binaryOperationValue = new QSpinBox(tab);
        spinBox_binaryOperationValue->setObjectName(QString::fromUtf8("spinBox_binaryOperationValue"));
        spinBox_binaryOperationValue->setGeometry(QRect(250, 288, 51, 22));
        spinBox_binaryOperationValue->setMinimum(0);
        spinBox_binaryOperationValue->setMaximum(254);
        spinBox_binaryOperationValue->setSingleStep(1);
        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 320, 71, 16));
        comboBox_action = new QComboBox(tab);
        comboBox_action->addItem(QString());
        comboBox_action->addItem(QString());
        comboBox_action->addItem(QString());
        comboBox_action->addItem(QString());
        comboBox_action->addItem(QString());
        comboBox_action->addItem(QString());
        comboBox_action->setObjectName(QString::fromUtf8("comboBox_action"));
        comboBox_action->setGeometry(QRect(80, 320, 221, 20));
        checkBox_forOpenTimer = new QCheckBox(tab);
        checkBox_forOpenTimer->setObjectName(QString::fromUtf8("checkBox_forOpenTimer"));
        checkBox_forOpenTimer->setGeometry(QRect(10, 250, 211, 20));
        label__open_file = new QLabel(tab);
        label__open_file->setObjectName(QString::fromUtf8("label__open_file"));
        label__open_file->setGeometry(QRect(150, 22, 211, 16));
        label__save_file = new QLabel(tab);
        label__save_file->setObjectName(QString::fromUtf8("label__save_file"));
        label__save_file->setGeometry(QRect(160, 93, 201, 16));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        textBrowser_income = new QTextBrowser(tab_2);
        textBrowser_income->setObjectName(QString::fromUtf8("textBrowser_income"));
        textBrowser_income->setGeometry(QRect(0, 0, 450, 372));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        textBrowser_output = new QTextBrowser(tab_3);
        textBrowser_output->setObjectName(QString::fromUtf8("textBrowser_output"));
        textBrowser_output->setGeometry(QRect(0, 0, 450, 572));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217 \320\262\321\205\320\276\320\264\320\275\320\276\320\263\320\276 \321\204\320\260\320\271\320\273\320\260 :", nullptr));
        toolButton_fileIn_select->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        checkBox_fileRemove->setText(QCoreApplication::translate("MainWindow", "\321\203\320\264\320\260\320\273\321\217\321\202\321\214 \320\262\321\205\320\276\320\264\320\275\321\213\320\265 \321\204\320\260\320\271\320\273\321\213", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217 \320\270\321\201\321\205\320\276\320\264\321\217\321\211\320\265\320\263\320\276 \321\204\320\260\320\271\320\273\320\260 :", nullptr));
        toolButton_fileOut_select->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\224\320\265\320\271\321\201\321\202\320\262\320\270\321\217 \320\277\321\200\320\270 </p><p>\320\277\320\276\320\262\321\202\320\276\321\200\320\265\320\275\320\270\320\270 \320\270\320\274\320\265\320\275\320\270 </p><p>\320\262\321\213\321\205\320\276\320\264\320\275\320\276\320\263\320\276 \321\204\320\260\320\271\320\273\320\260:</p></body></html>", nullptr));
        comboBox_fileOverridePolicy->setItemText(0, QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\277\320\270\321\201\320\260\321\202\321\214", nullptr));
        comboBox_fileOverridePolicy->setItemText(1, QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\276\321\201\321\202\321\204\320\270\320\272\321\201 \320\272 \320\270\320\274\320\265\320\275\320\270", nullptr));

        toolButton_fileOnceSave->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214 \n"
"1 \321\200\320\260\320\267", nullptr));
        checkBox_forSaveTimer->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\321\213\320\262\320\260\321\202\321\214 \321\204\320\260\320\271\320\273 \321\200\320\260\320\267 \320\262 ", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\321\201\320\265\320\272\321\203\320\275\320\264", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\321\201\320\265\320\272\321\203\320\275\320\264", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 8 \320\261\320\260\320\271\321\202 \320\264\320\273\321\217 \320\261\320\270\320\275\320\260\321\200\320\275\320\276\320\271 \320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\270", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\224\320\265\320\271\321\201\321\202\320\262\320\270\321\217 :", nullptr));
        comboBox_action->setItemText(0, QCoreApplication::translate("MainWindow", "AND", nullptr));
        comboBox_action->setItemText(1, QCoreApplication::translate("MainWindow", "OR", nullptr));
        comboBox_action->setItemText(2, QCoreApplication::translate("MainWindow", "XOR", nullptr));
        comboBox_action->setItemText(3, QCoreApplication::translate("MainWindow", "NOT", nullptr));
        comboBox_action->setItemText(4, QCoreApplication::translate("MainWindow", "<<", nullptr));
        comboBox_action->setItemText(5, QCoreApplication::translate("MainWindow", ">>", nullptr));

        checkBox_forOpenTimer->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\262\320\265\321\200\321\217\321\202\321\214 \320\275\320\260\320\273\320\270\321\207\320\270\320\265 \321\204\320\260\320\271\320\273\320\260 \321\200\320\260\320\267 \320\262 ", nullptr));
        label__open_file->setText(QString());
        label__save_file->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264\321\217\321\211\320\270\320\271 \321\204\320\260\320\271\320\273", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\275\321\213\320\271 \321\204\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
