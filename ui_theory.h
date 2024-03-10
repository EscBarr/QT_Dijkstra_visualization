/********************************************************************************
** Form generated from reading UI file 'theory.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THEORY_H
#define UI_THEORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Theory
{
public:
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser;
    QLabel *label_2;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Theory)
    {
        if (Theory->objectName().isEmpty())
            Theory->setObjectName(QString::fromUtf8("Theory"));
        Theory->resize(935, 483);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(11);
        Theory->setFont(font);
        gridLayout = new QGridLayout(Theory);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textBrowser = new QTextBrowser(Theory);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setStyleStrategy(QFont::PreferDefault);
        textBrowser->setFont(font1);

        gridLayout->addWidget(textBrowser, 0, 0, 2, 3);

        label_2 = new QLabel(Theory);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        listWidget = new QListWidget(Theory);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 1, 3, 1, 1, Qt::AlignRight);

        pushButton = new QPushButton(Theory);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);

        label = new QLabel(Theory);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 2, 1, 1, 1);

        pushButton_2 = new QPushButton(Theory);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 2, 1, 1);


        retranslateUi(Theory);

        QMetaObject::connectSlotsByName(Theory);
    } // setupUi

    void retranslateUi(QDialog *Theory)
    {
        Theory->setWindowTitle(QCoreApplication::translate("Theory", "\320\242\320\265\320\276\321\200\320\265\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273", nullptr));
        label_2->setText(QCoreApplication::translate("Theory", "\320\236\320\223\320\233\320\220\320\222\320\233\320\225\320\235\320\230\320\225", nullptr));
        pushButton->setText(QCoreApplication::translate("Theory", "<<", nullptr));
        label->setText(QCoreApplication::translate("Theory", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Theory", ">>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Theory: public Ui_Theory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THEORY_H
