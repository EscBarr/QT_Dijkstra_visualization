#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include <QDialog>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include "graphwidget.h"
#include "node.h"
#include "edge.h"
#include "theory.h"
namespace Ui {
class Visualization;
}

class Visualization : public QDialog
{
    Q_OBJECT

public:
    explicit Visualization(QWidget *parent = nullptr);
    GraphWidget *Scene;//отрисовка узлов
    QVector<Node *> Node_list;
    QVector <QVector <std::pair <int, int > > > weight_list; //Список смежности
    QVector <int> prev;//Для восстановления пути
    void Generate_Nodes();
    void Fill_weights();
    ~Visualization();
    void dijkstra_algorithm(int n,int start);
    void Restore_path(int j);
    void Generate_weight();
    void prepare_table();
    void Add_Element_table(int Row,int Col,QString Content);
    void delay(bool is_temp);
    void Undirected_graph_init();
    void Directed_graph_init();
    void Hide_buttons();
    void Show_buttons();
private slots:
    void on_pushButton_clicked();

    void on_spinBox_2_valueChanged(int arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_checkBox_2_stateChanged(int arg1);

    void on_pushButton_4_clicked();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::Visualization *ui;
};

#endif // VISUALIZATION_H
