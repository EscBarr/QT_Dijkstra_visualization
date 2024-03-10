#ifndef TEST_H
#define TEST_H

#include <QDialog>
#include <QTextStream>
#include <QRandomGenerator>
#include <QFile>
#include <QMessageBox>
#include <QListWidget>

namespace Ui
{
class test;
}

class test : public QDialog
{
    Q_OBJECT

public:
    class Question
    {
     public:
        QVector <QString> Questions;
        QVector <QString> ANSW;
        QString correct_anwser;
        QString chosen_anwser = "";
        int Price;
    };
    explicit test(QWidget *parent = nullptr,QString name = "err");
    ~test();
    void decrypt(QString& Question);
    void Fill_Question(QTextStream &stream,QVector <QString> &temp);
    void Fill_Answer(QTextStream &stream, QVector <QString> &temp, int &cost);
    void Fill_Test(QString Test_Name);
    void Fill_Content_Table();
    void ListQuestion(int i);//вывод вопроса
    void Give_Grade();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_label_5_linkActivated(const QString &link);

private:
    Ui::test *ui;
    QVector<QString> User_answers;//Хранение ответов пользователя
    QVector<Question> Storage;//Хранение вопросов всех ответов, правильного и стоимости вопроса
    int page_number;
};

#endif // TEST_H
