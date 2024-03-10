/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *start_theory;
    QPushButton *start_test;
    QPushButton *start_visualization;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(664, 663);
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(11);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 80, 381, 111));
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        start_theory = new QPushButton(centralwidget);
        start_theory->setObjectName(QString::fromUtf8("start_theory"));
        start_theory->setGeometry(QRect(200, 190, 251, 51));
        start_test = new QPushButton(centralwidget);
        start_test->setObjectName(QString::fromUtf8("start_test"));
        start_test->setGeometry(QRect(200, 250, 251, 51));
        start_visualization = new QPushButton(centralwidget);
        start_visualization->setObjectName(QString::fromUtf8("start_visualization"));
        start_visualization->setGeometry(QRect(200, 310, 251, 51));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 370, 321, 121));
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 664, 27));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\243\320\247\320\225\320\221\320\235\320\236-\320\224\320\225\320\234\320\236\320\235\320\241\320\242\320\240\320\220\320\246\320\230\320\236\320\235\320\235\320\220\320\257 \320\237\320\240\320\236\320\223\320\240\320\220\320\234\320\234\320\220  <<\320\237\320\276\320\270\321\201\320\272 \320\272\321\200\320\260\321\202\321\207\320\260\320\271\321\210\320\265\320\263\320\276 \320\277\321\203\321\202\320\270. \320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\224\320\265\320\271\320\272\321\201\321\202\321\200\321\213>>", nullptr));
        start_theory->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \321\202\320\265\320\276\321\200\320\270\321\216", nullptr));
        start_test->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\271\321\202\320\270 \321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        start_visualization->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\262\320\270\320\267\321\203\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\216", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\320\273 \321\201\321\202\321\203\320\264\320\265\320\275\321\202 \320\263\321\200\321\203\320\277\320\277\321\213 \320\224\320\230\320\237\320\240\320\261 21 \320\257\320\263\320\260\321\204\320\260\321\200\320\276\320\262 \320\242\320\270\320\274\321\203\321\200 \320\240\320\270\320\274\320\276\320\262\320\270\321\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
