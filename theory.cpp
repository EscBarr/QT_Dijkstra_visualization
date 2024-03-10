#include "theory.h"
#include "ui_theory.h"

Theory::Theory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Theory)
{
    ui->setupUi(this);
    Fill_vector("Theory.txt");
    ListTheory(Pages[0]);
    ui->label->setText(QString( "%1" ).arg( page_number+1));
}

Theory::~Theory()
{
    delete ui;
}



void Theory::Fill_vector(QString Theory_Name)
{
    QFile Theory_File(Theory_Name);
    Theory_File.open((QIODevice::ReadOnly | QIODevice::Text));
    QVector<QString> Read_Page;
    QTextStream in(&Theory_File);
    QString header("Header");
    int Page_header = 0;
    while (!in.atEnd())
    {
        while (true)
        {
         QString temp = in.readLine();
         if (temp == "stop")
         {
             break;
         }
         else if (temp.contains(header))
         {
            temp.remove(header);
            ui->listWidget->addItem(QString::number(Page_header+1)+". " + temp);
            Read_Page.push_back(temp);

         }
         else
         {
             Read_Page.push_back(temp);
         }
        }
        Pages.push_back(Read_Page);
        Page_header++;
        Read_Page.clear();
    }
    Theory_File.close();
}

void Theory::ListTheory(QVector<QString> words)
{
    QFont myfont ("Consolas");
    myfont.setPixelSize(18);
     ui->textBrowser->setFont(myfont);
     ui->textBrowser->setText(words[0]);
     ui->textBrowser->setAlignment(Qt::AlignJustify);
     for(int i = 1; i < words.size(); ++i)
        {
            ui->textBrowser->append(words[i]);
        }
}

void Theory::on_pushButton_clicked()
{
    if(page_number > 0)
            page_number -= 1;
        ui->label->setText(QString::number(page_number+1));
        ListTheory(Pages[page_number]);
}

void Theory::on_pushButton_2_clicked()
{
    if(page_number < Pages.size()-1)
            page_number += 1;
        ui->label->setText(QString::number(page_number+1));
        ListTheory(Pages[page_number]);
}

void Theory::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QString temp = item->text();
    page_number = temp.split(".")[0].toInt();
    ui->label->setText(QString::number(page_number));
    ListTheory(Pages[page_number-1]);
}
