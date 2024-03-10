#ifndef AUTHORIZE_H
#define AUTHORIZE_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
namespace Ui {
class Authorize;
}

class Authorize : public QDialog
{
    Q_OBJECT

public:
    explicit Authorize(QWidget *parent = nullptr);

    ~Authorize();

private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

signals:
    void Name_changed(QString name);

private:
    Ui::Authorize *ui;
};

#endif // AUTHORIZE_H
