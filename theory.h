#ifndef THEORY_H
#define THEORY_H

#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QListWidget>
namespace Ui {
class Theory;
}

class Theory : public QDialog
{
    Q_OBJECT

public:
    explicit Theory(QWidget *parent = nullptr);
    ~Theory();
    void Fill_vector(QString Theory_Name);
    void ListTheory(QVector<QString> words);//Вывод теории
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);
private:
    Ui::Theory *ui;
    QVector<QVector<QString>> Pages;//Хранение страниц
    int page_number = 0;
};

#endif // THEORY_H
