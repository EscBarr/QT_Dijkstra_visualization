/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_test
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QListWidget *listWidget;
    QLabel *label_3;
    QLabel *label_4;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *test)
    {
        if (test->objectName().isEmpty())
            test->setObjectName(QString::fromUtf8("test"));
        test->resize(911, 388);
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(11);
        test->setFont(font);
        gridLayout = new QGridLayout(test);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(test);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 6, 0, 1, 1);

        pushButton_2 = new QPushButton(test);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 6, 3, 1, 1);

        textEdit = new QTextEdit(test);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setMinimumSize(QSize(310, 31));
        textEdit->setMaximumSize(QSize(16777215, 50));

        gridLayout->addWidget(textEdit, 5, 0, 1, 4);

        label_2 = new QLabel(test);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 4, 1, 1);

        pushButton_3 = new QPushButton(test);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(200, 20));

        gridLayout->addWidget(pushButton_3, 5, 4, 1, 1);

        label = new QLabel(test);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(70, 50));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 1, 1, 1);

        listWidget = new QListWidget(test);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 2, 4, 2, 1, Qt::AlignRight);

        label_3 = new QLabel(test);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(15, 15));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        label_4 = new QLabel(test);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);


        gridLayout->addWidget(label_4, 4, 0, 1, 1, Qt::AlignLeft|Qt::AlignVCenter);

        textBrowser = new QTextBrowser(test);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMinimumSize(QSize(631, 210));

        gridLayout->addWidget(textBrowser, 3, 0, 1, 4);


        retranslateUi(test);

        QMetaObject::connectSlotsByName(test);
    } // setupUi

    void retranslateUi(QDialog *test)
    {
        test->setWindowTitle(QCoreApplication::translate("test", "\320\242\320\265\321\201\321\202\320\276\320\262\321\213\320\271 \321\200\320\265\320\266\320\270\320\274", nullptr));
        pushButton->setText(QCoreApplication::translate("test", "<<", nullptr));
        pushButton_2->setText(QCoreApplication::translate("test", ">>", nullptr));
        label_2->setText(QCoreApplication::translate("test", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\262\320\276\320\277\321\200\320\276\321\201\320\276\320\262", nullptr));
        pushButton_3->setText(QCoreApplication::translate("test", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("test", "\320\222\320\276\320\277\321\200\320\276\321\201 \342\204\226", nullptr));
        label_3->setText(QCoreApplication::translate("test", "1", nullptr));
        label_4->setText(QCoreApplication::translate("test", "\320\237\320\276\320\273\320\265 \320\264\320\273\321\217 \320\262\320\262\320\276\320\264\320\260 \320\276\321\202\320\262\320\265\321\202\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class test: public Ui_test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
