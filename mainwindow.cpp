#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    user_name = "";

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Receive_Name(QString temp)
{
    user_name = temp;
}


void MainWindow::on_start_visualization_clicked()
{
    Visualization Window;
    Window.setModal(true);
    Window.exec();

}

void MainWindow::on_start_test_clicked()
{

     Authorize Auth;
     QObject::connect( &Auth, SIGNAL(Name_changed(QString)),this, SLOT(Receive_Name(QString)));
     Auth.exec();
     if(user_name.size() != 0)
     {
     QFile Theory_File("Test.txt");

     if(!Theory_File.open((QIODevice::ReadOnly | QIODevice::Text)))
     {
        QMessageBox::information(this, "Ошибка", "Файл не найден или его не удалось открыть");
        Theory_File.close();
        return;
     }
        Theory_File.close();
        test Window(nullptr,user_name);
        Window.setModal(true);
        Window.exec();
     }

}

void MainWindow::on_start_theory_clicked()
{
    QFile Theory_File("Theory.txt");
    if(!Theory_File.open((QIODevice::ReadOnly | QIODevice::Text)))
    {
        QMessageBox::information(this, "Ошибка", "Файл не найден или его не удалось открыть");
        Theory_File.close();
    }
    else
    {
        Theory_File.close();
        Theory Window;
        Window.setModal(true);
        Window.exec();
    }

}
