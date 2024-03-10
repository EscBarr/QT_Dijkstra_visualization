#include "authorize.h"
#include "ui_authorize.h"
#include "mainwindow.h"

Authorize::Authorize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Authorize)
{
    ui->setupUi(this);

}

Authorize::~Authorize()
{
    delete ui;
}


void Authorize::on_pushButton_clicked()
{
    if(ui->lineEdit->text().size() > 30 || ui->lineEdit->text().size() < 3)
    {
        QMessageBox::information(this, "Неверный ввод", "Имя должно содержать не более 30 символов или менее 3");

    }
    else
    {
        emit Name_changed(ui->lineEdit->text());
        this->close();
    }
}

void Authorize::on_pushButton_2_clicked()
{
    this->close();
}

void Authorize::on_lineEdit_textChanged(const QString &arg1)
{
    QPalette palette;
    palette.setColor(QPalette::Text,Qt::red);
    if(arg1.size() > 30 || arg1.size() < 3)
    {
        ui->lineEdit->setPalette(palette);

    }
    else
    {
        palette.setColor(QPalette::Text,Qt::black);
        ui->lineEdit->setPalette(palette);
    }
}
