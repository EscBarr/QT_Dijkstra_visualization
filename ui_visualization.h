/********************************************************************************
** Form generated from reading UI file 'visualization.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALIZATION_H
#define UI_VISUALIZATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Visualization
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label;
    QTableWidget *tableWidget;
    QLabel *label_3;
    QSpinBox *spinBox_2;
    QTextBrowser *textBrowser;
    QDoubleSpinBox *doubleSpinBox;
    QSpinBox *spinBox;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QCheckBox *checkBox_2;
    QLabel *label_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QFormLayout *Draw_Layout;

    void setupUi(QDialog *Visualization)
    {
        if (Visualization->objectName().isEmpty())
            Visualization->setObjectName(QString::fromUtf8("Visualization"));
        Visualization->resize(880, 663);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(11);
        Visualization->setFont(font);
        Visualization->setAutoFillBackground(true);
        gridLayout_2 = new QGridLayout(Visualization);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(Visualization);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        tableWidget = new QTableWidget(Visualization);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setBaseSize(QSize(5, 5));

        gridLayout_2->addWidget(tableWidget, 3, 0, 2, 3);

        label_3 = new QLabel(Visualization);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 2, 1, 1);

        spinBox_2 = new QSpinBox(Visualization);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMinimum(8);
        spinBox_2->setMaximum(12);
        spinBox_2->setValue(8);

        gridLayout_2->addWidget(spinBox_2, 0, 3, 1, 1);

        textBrowser = new QTextBrowser(Visualization);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout_2->addWidget(textBrowser, 5, 0, 1, 8);

        doubleSpinBox = new QDoubleSpinBox(Visualization);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMinimum(0.500000000000000);
        doubleSpinBox->setMaximum(1.500000000000000);
        doubleSpinBox->setSingleStep(0.100000000000000);
        doubleSpinBox->setValue(1.000000000000000);

        gridLayout_2->addWidget(doubleSpinBox, 2, 6, 1, 1);

        spinBox = new QSpinBox(Visualization);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(8);

        gridLayout_2->addWidget(spinBox, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(Visualization);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 0, 5, 2, 1);

        label_2 = new QLabel(Visualization);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMidLineWidth(0);

        gridLayout_2->addWidget(label_2, 2, 0, 1, 3);

        checkBox_2 = new QCheckBox(Visualization);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        gridLayout_2->addWidget(checkBox_2, 0, 4, 1, 1);

        label_4 = new QLabel(Visualization);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 6, 1, 1);

        pushButton_3 = new QPushButton(Visualization);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_2->addWidget(pushButton_3, 2, 5, 1, 1);

        pushButton = new QPushButton(Visualization);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_2->addWidget(pushButton, 2, 3, 2, 2);

        Draw_Layout = new QFormLayout();
        Draw_Layout->setObjectName(QString::fromUtf8("Draw_Layout"));
        Draw_Layout->setSizeConstraint(QLayout::SetFixedSize);

        gridLayout_2->addLayout(Draw_Layout, 4, 4, 1, 3);


        retranslateUi(Visualization);

        QMetaObject::connectSlotsByName(Visualization);
    } // setupUi

    void retranslateUi(QDialog *Visualization)
    {
        Visualization->setWindowTitle(QCoreApplication::translate("Visualization", "\320\224\320\265\320\274\320\276\320\275\321\201\321\202\321\200\320\260\321\206\320\270\321\217 \321\200\320\260\320\261\320\276\321\202\321\213", nullptr));
        label->setText(QCoreApplication::translate("Visualization", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\260\321\217 \320\262\320\265\321\200\321\210\320\270\320\275\320\260:", nullptr));
        label_3->setText(QCoreApplication::translate("Visualization", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\262\320\265\321\200\321\210\320\270\320\275:", nullptr));
        doubleSpinBox->setSuffix(QCoreApplication::translate("Visualization", " \321\201", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Visualization", "\320\223\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\262\320\265\321\201", nullptr));
        label_2->setText(QCoreApplication::translate("Visualization", " \320\242\320\260\320\261\320\273\320\270\321\206\320\260 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\276\320\262 \320\277\320\276\320\270\321\201\320\272\320\260", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Visualization", "\320\236\321\200\320\270\320\265\320\275\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271", nullptr));
        label_4->setText(QCoreApplication::translate("Visualization", "\320\227\320\260\320\264\320\265\321\200\320\266\320\272\320\260 \320\276\321\202\321\200\320\270\321\201\320\276\320\262\320\272\320\270 ", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Visualization", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\202\320\265\320\276\321\200\320\270\321\216", nullptr));
        pushButton->setText(QCoreApplication::translate("Visualization", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Visualization: public Ui_Visualization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALIZATION_H
