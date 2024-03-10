#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    MainWindow w;
    QFont font("Consolas",11,50,false);
    QApplication::setFont(font);
    w.show();
    return a.exec();
}
