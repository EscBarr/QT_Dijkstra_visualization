#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "theory.h"
#include "visualization.h"
#include "test.h"
#include "authorize.h"
#include "ui_authorize.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void Receive_Name(QString temp);
private slots:
    void on_start_visualization_clicked();

    void on_start_test_clicked();

    void on_start_theory_clicked();

private:
    Ui::MainWindow *ui;
    QString user_name;
};
#endif // MAINWINDOW_H
