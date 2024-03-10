#include "test.h"
#include "ui_test.h"


test::test(QWidget *parent,QString name) :
    QDialog(parent),
    ui(new Ui::test)
{
    ui->setupUi(this);
    Fill_Test("Test.txt");
    Fill_Content_Table();
    ListQuestion(0);
    ui->label_4->setText(name);
}

test::~test()
{
    delete ui;
}
//QString encodeStr(const QString& str)
//{
//    QByteArray arr(str.toUtf8());
//    for(int i =0; i<arr.size(); i++)
//        arr[i] = arr[i] ^ key;

//    return QString::fromAscii(arr.toBase64());
//}

//QString decodeStr(const QString &str)
//{
//    QByteArray arr = QByteArray::fromBase64(str.toAscii());
//    for(int i =0; i<arr.size(); i++)
//        arr[i] =arr[i] ^ key;

//    return QString::fromUtf8(arr);
//}
void test::decrypt(QString &Question)
{

    std::string temp = Question.toStdString();
     QByteArray arr = QByteArray::fromStdString(temp);
    char key = '3';
    for(int i =0; i<arr.size(); i++)
            arr[i] =arr[i] ^ key;

    Question = Question.fromUtf8(arr);
}

void test::Fill_Question(QTextStream &in,QVector <QString> &temp)
{
     QString temp_for_test_filling = in.readLine();
    //  decrypt(temp_for_test_filling);
     if(!in.atEnd())
     while (temp_for_test_filling != "answers" )
     {
        temp.push_back(temp_for_test_filling);
        temp_for_test_filling = in.readLine();
       //  decrypt(temp_for_test_filling);
     }
}

void test::Fill_Answer(QTextStream &in, QVector<QString> &temp,int& cost)
{
    QString temp_for_test_filling = in.readLine();
//    decrypt(temp_for_test_filling);
    if (!in.atEnd())
    while (temp_for_test_filling != "stop")
    {
       temp.push_back(temp_for_test_filling);
       temp_for_test_filling = in.readLine();
//       decrypt(temp_for_test_filling);
    }
     temp_for_test_filling = in.readLine();
    // decrypt(temp_for_test_filling);
     cost = temp_for_test_filling.toInt();//Записываем стоимость вопроса
}
QVector <int> Randomize_which_question_fill()
{
    QVector<int> Question_for_display = { 1,2,3,4,5,6,7,8,9,10 };
    for (int i = 9; i > 4; i--)//Взятие только вопросов со случайным номером
    {
        int index = QRandomGenerator::global()->bounded(i);
        std::swap(Question_for_display[i], Question_for_display[index]);
    }
    Question_for_display.resize(5);
    return Question_for_display;
}
bool Check_is_in_range_of_questions(QVector<int>Rand_index_for_writing,int count_num_filled_quest)//Проверка нужно ли данный вопрос добавлять в тест
{
    return std::find(Rand_index_for_writing.begin(), Rand_index_for_writing.end(), count_num_filled_quest) != Rand_index_for_writing.end();
}
void Randomize_answers(QVector<QString>Answers)
{
    for (int i = 1; i < Answers.size()-1; i++)//перемешиваем варианты ответов все кроме 1 позиции
    {
        for (int j = i+1; j < Answers.size(); j++)
        {
            if (rand() % 2)
            {
                swap(Answers[i], Answers[j]);
            }
        }
    }
}
void test::Fill_Test(QString Test_Name)
{
    srand((unsigned)time(NULL));
    QFile Test_File(Test_Name);
    Test_File.open((QIODevice::ReadOnly | QIODevice::Text));
    int count_num_filled_quest=0;
    QVector<int> Question_for_display = Randomize_which_question_fill();//Выбор вопросов со случайным номером пока 10
    QString temp_for_test_filling;
    QTextStream in(&Test_File);
    int count_saved_questions = 0;
    while (!in.atEnd() && count_saved_questions != 5)
    {
     Question buffer;
     QVector <QString> temp_Questions;
     QVector <QString> temp_Answers;
     int cost = 0;
     Fill_Question(in,temp_Questions);
     Fill_Answer(in,temp_Answers,cost);
     count_num_filled_quest++;
     if(Check_is_in_range_of_questions(Question_for_display,count_num_filled_quest))
     {
        count_saved_questions++;
        Randomize_answers(temp_Answers);
        QString Correct_answ = temp_Answers[0];
        int Num_question;
        if(temp_Answers.size() > 1)
        {
             Num_question =  QRandomGenerator::global()->bounded(temp_Answers.size()-1);
        }
        else
        {
            Num_question =  QRandomGenerator::global()->bounded(temp_Answers.size());
        }
        qSwap(temp_Answers[0],temp_Answers[Num_question]);
        if (temp_Answers.size()==1)
        {
          buffer.correct_anwser = Correct_answ;//если вопрос открытый то ответ строчка иначе номер ответа
        }
        else
        {
            buffer.correct_anwser = QString::number(Num_question);
        }
        buffer.Questions = temp_Questions;
        buffer.ANSW = temp_Answers;
        buffer.Price = cost;

        Storage.push_back(buffer);

     }
    }
    Test_File.close();
}

void test::Fill_Content_Table()
{
    for (int i = 0;i < 5;++i )
    {
     ui->listWidget->addItem("Вопрос №" + QString::number(i+1));
    }

}

void test::ListQuestion(int num)
{
    QFont myfont ("Times New Roman");
    myfont.setPixelSize(16);
     ui->textBrowser->setFont(myfont);
    ui->textBrowser->setText(Storage[num].Questions[0]);
//    ui->textBrowser->setAlignment(Qt::AlignCenter);
    for(int i = 1; i < Storage[num].Questions.size(); ++i)
        {
            ui->textBrowser->append(Storage[num].Questions[i]);
        }
    ui->textBrowser->setAlignment(Qt::AlignJustify);
    if (Storage[num].ANSW.size() != 1)//вывести ответы если их больше чем 1, иначе вопрос открытый
    {
    for (int i = 0; i < Storage[num].ANSW.size(); ++i)
    {
        ui->textBrowser->append(QString::number(i+1) + ")" + Storage[num].ANSW[i]);
    }
    }
    ui->textBrowser->append("Стоимость вопроса: " + QString::number(Storage[num].Price));
}

void test::on_pushButton_clicked()
{
    Storage[page_number].chosen_anwser = ui->textEdit->toPlainText();
    if(page_number > 0)
            page_number -= 1;
        ui->label_3->setText(QString::number(page_number+1));
        ui->textEdit->setText(Storage[page_number].chosen_anwser);
        ListQuestion(page_number);
}

void test::on_pushButton_2_clicked()
{
    Storage[page_number].chosen_anwser = ui->textEdit->toPlainText();
    if(page_number < Storage.size()-1)
            page_number += 1;
         ui->label_3->setText(QString::number(page_number+1));
         ui->textEdit->setText(Storage[page_number].chosen_anwser);
        ListQuestion(page_number);
}

void test::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString temp = item->text();
    page_number = temp.rightRef(1).toInt()-1;
    ui->label_3->setText(QString::number(page_number+1));
    ui->textEdit->setText(Storage[page_number].chosen_anwser);
   ListQuestion(page_number);
}


