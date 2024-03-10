#include "visualization.h"
#include "ui_visualization.h"
#include<QTime>

int Generate_Rand(int start, int end)
{
    static QRandomGenerator *Gen =  QRandomGenerator::global();
    start = start < end ? start : end;
    return Gen->bounded(start,end);
}

void Visualization::delay(bool is_temp)
{
    double time = ui->doubleSpinBox->value() * 1000;
    QTime dieTime= QTime::currentTime().addMSecs(is_temp ? time/2 : time);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Visualization::Undirected_graph_init()
{
    Scene->Draw_scene->clear();
    Node_list.clear();
    Generate_Nodes();
    Scene->alg_started = false;
    Node_list[0]->setPos(250, 150);
    Node_list[1]->setPos(300, 150);
    Node_list[2]->setPos(350, 150);
    Node_list[3]->setPos(250, 200);
    Scene->centerNode->setPos(300, 200);
    Node_list[5]->setPos(350, 200);
    Node_list[6]->setPos(250, 250);
    Node_list[7]->setPos(400, 250);

    for (int i = 0;i<Node_list.size(); ++i )
    {
        Node_list[i]->edges().clear();
    }

    Scene->Draw_scene->addItem(new Edge(Node_list[0], Node_list[1],Generate_Rand(1,20)));
    Scene->Draw_scene->addItem(new Edge(Node_list[1], Node_list[2],Generate_Rand(1,20)));
    Scene->Draw_scene->addItem(new Edge(Node_list[1], Node_list[4],Generate_Rand(1,20)));
    Scene->Draw_scene->addItem(new Edge(Node_list[2], Node_list[5],Generate_Rand(1,20)));
    Scene->Draw_scene->addItem(new Edge(Node_list[3], Node_list[0],Generate_Rand(1,20)));
    Scene->Draw_scene->addItem(new Edge(Node_list[3], Node_list[4],Generate_Rand(1,20)));
    Scene->Draw_scene->addItem(new Edge(Node_list[4], Node_list[5],Generate_Rand(1,20)));
    Scene->Draw_scene->addItem(new Edge(Node_list[6], Node_list[3],Generate_Rand(1,20)));
    Scene->Draw_scene->addItem(new Edge(Node_list[7], Node_list[2],Generate_Rand(1,20)));
    Scene->finished_adjusting = false;
    Scene->timer_used_for = 0;
    Generate_weight();
}

void Visualization::Directed_graph_init()
{
    QVector <std::pair <int, int>> is_connected;

    Scene->Draw_scene->clear();
    Node_list.clear();
    Generate_Nodes();
    Scene->alg_started = false;
    Node_list[0]->setPos(250, 150);
    Node_list[1]->setPos(300, 150);
    Node_list[2]->setPos(350, 150);
    Node_list[3]->setPos(250, 200);
    Scene->centerNode->setPos(300, 200);
    Node_list[5]->setPos(350, 200);
    Node_list[6]->setPos(250, 250);
    Node_list[7]->setPos(400, 250);
    for (int i = 0;i<Node_list.size(); ++i )
    {
        Node_list[i]->edges().clear();
    }

    for (int i = 0;i <= ui->spinBox_2->value()+1; ++i)
    {
        int num_node1, num_node2;
        bool is_equal, contains;
        do
        {
            num_node1 = Generate_Rand(0,Node_list.size());
            num_node2 = Generate_Rand(0,Node_list.size());
            is_equal = num_node1 == num_node2;
            contains = is_connected.contains(std::make_pair(num_node1,num_node2));
            if(contains) --i;
        } while(is_equal || contains);
        Edge *new_temp = (new Edge(Node_list[num_node1], Node_list[num_node2],1));
        is_connected.push_back(std::make_pair(num_node1,num_node2));

        Scene->Draw_scene->addItem(new_temp);

    }
//    is_connected.erase( unique( is_connected.begin(), is_connected.end() ), is_connected.end() );
    Scene->finished_adjusting = false;
    Scene->timer_used_for = 0;
    Generate_weight();
    Node_list[0]->setPos(250, 150);
    Node_list[1]->setPos(300, 150);
    Node_list[2]->setPos(350, 150);
    Node_list[3]->setPos(250, 200);
    Scene->centerNode->setPos(300, 200);
    Node_list[5]->setPos(350, 200);
    Node_list[6]->setPos(250, 250);
    Node_list[7]->setPos(400, 250);
}

void Visualization::Hide_buttons()
{
    ui->checkBox_2->setEnabled(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
     ui->spinBox->setEnabled(false);
     ui->spinBox_2->setEnabled(false);
}

void Visualization::Show_buttons()
{
    ui->checkBox_2->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
     ui->spinBox->setEnabled(true);
      ui->spinBox_2->setEnabled(true);
}



void Visualization::Add_Element_table(int Row,int Col,QString Content)
{
    QTableWidgetItem* item = new QTableWidgetItem;
    item->setText(Content);
    item->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(Row,Col,item);
    ui->tableWidget->resizeColumnsToContents();
}

Visualization::Visualization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Visualization)
{
       ui->setupUi(this);

       Scene = new GraphWidget();
       ui->Draw_Layout->addWidget(Scene);
//       Generate_Nodes();
//       Scene->alg_started = false;
//       Node_list[0]->setPos(150, 150);
//       Node_list[1]->setPos(200, 150);
//       Node_list[2]->setPos(250, 150);
//       Node_list[3]->setPos(150, 200);
//       Scene->centerNode->setPos(200, 200);
//       Node_list[5]->setPos(250, 200);
//       Node_list[6]->setPos(150, 250);
//       Node_list[7]->setPos(300, 250);
       Undirected_graph_init();


       ui->Draw_Layout->addWidget(Scene);
       ui->spinBox->setMaximum(ui->spinBox_2->value());
       GraphWidget::is_oriented = ui->checkBox_2->checkState();
       prepare_table();
       ui->textBrowser->append("Можете нажимать на узлы для их перемещения, а также приближать изображение с помощью прокрутки колеса мыши или по нажатию '+' и '-'");
}


void Visualization::Generate_Nodes()
{
    for (int i = 0;i<4 ;++i )
    {
        Node_list.push_back(new Node(Scene,i));
    }
    Scene->centerNode = new Node(Scene,4);
    Node_list.push_back(Scene->centerNode);
    for (int i =5;i<ui->spinBox_2->value() ;++i )
    {
        Node_list.push_back(new Node(Scene,i));
    }
    for (int i = 0;i<Node_list.size() ;++i )
    {
        Scene->Draw_scene->addItem(Node_list[i]);
    }
}

void Visualization::Fill_weights()
{
    weight_list.clear();
     weight_list.reserve(16);
    for (int i = 0;i<Node_list.size() ;++i)
    {
        QVector < std::pair <int, int >> temp;
        for (int j = 0;j < Node_list[i]->edges().size() ;++j )
        {
           if(Node_list[i]->edges().at(j)->destNode()->Num_Node != Node_list[i]->Num_Node)
            temp.push_back(std::make_pair(Node_list[i]->edges().at(j)->destNode()->Num_Node, Node_list[i]->edges().at(j)->weight_to()));
           else if(!GraphWidget::is_oriented)
           {
                temp.push_back(std::make_pair(Node_list[i]->edges().at(j)->sourceNode()->Num_Node, Node_list[i]->edges().at(j)->weight_to()));
           }

        }
         weight_list.push_back(temp);
         temp.clear();
    }
}

Visualization::~Visualization()
{
    delete ui;
}

void Visualization::on_pushButton_clicked()
{
    for (int i = 0;i<Node_list.size() ;++i)
    {
       Node_list[i]->is_used = false;
       Node_list[i]->finished = false;
       Node_list[i]->update();
       Node_list[i]->shortest_weight = "∞";
       Scene->alg_started = false;
       Scene->viewport()->repaint();
    }

  ui->textBrowser->clear();
  Fill_weights();
  Scene->alg_started = true;
  Scene->finished = false;
  prepare_table();
  Hide_buttons();
  dijkstra_algorithm(ui->spinBox_2->value(),ui->spinBox->value()-1);

}

void Visualization::dijkstra_algorithm(int n,int start)
{

    const int INF = 1000000000;
    QVector <int> dist(n, INF);
    dist[start] = 0;
    QVector <int> prev_t(n, -1);
    QVector <bool> used(n);
    int min_dist = 0;
    int min_vertex = start;
    while (min_dist < INF)
    {
        int i = min_vertex;
        used[i] = true;
        Node_list[i]->is_used = true;
        Node_list[i]->update();
        Scene->viewport()->repaint();
        delay(false);
        for (auto edge: weight_list[i])
        {
            int j = edge.first;
            int wt = edge.second;
            if (dist[i] + wt < dist[j])
            {
                dist[j] = dist[i] + wt;
                prev_t[j] = i;
            }
            Node_list[j]->shortest_weight = QString::number(dist[j]);
            delay(true);
            Add_Element_table(j,2,QString::number(dist[j]));
//            Add_Element_table(i,1,"да");

            Node_list[j]->update();
            Scene->viewport()->repaint();
            delay(true);
        }
        min_dist = INF;
        for (int j = 0; j < n; ++j)
            if (!used[j] && dist[j] < min_dist)
            {
                min_dist = dist[j];
                min_vertex = j;
            }

         Node_list[i]->finished = true;
         Add_Element_table(i,1,"да");
         Node_list[i]->update();
         Scene->viewport()->repaint();
         delay(false);
    }
    Scene->viewport()->repaint();
    Scene->finished = true;
    prev = prev_t;
    for (int i = 0;i < dist.size() ;i++ )
    {
     Node_list[i]->shortest_weight = QString::number(dist[i]);
    }
     for (int i = 0;i < prev.size() ;i++ )
     {
         Restore_path(i);
         delay(true);
     }
     ui->textBrowser->append("Демонстрация завершена");
     Show_buttons();
}

void Visualization::Restore_path(int j)
{
    QVector <int> path;
    int temp_j = j;
    while (j != -1)
    {
        path.push_back(j);
        j = prev[j];
    }
    std::reverse(path.begin(), path.end());
    QString temp;
    for (int i = 0;i < path.size() ;i++ )
    {
        temp += QString::number(path[i]+1)+" ";
        Add_Element_table(temp_j,3,temp);

         delay(true);
    }



}

void Visualization::Generate_weight()
{
    for (int i = 0;i<Node_list.size() ;++i)
    {

        for (int j = 0;j < Node_list[i]->edges().size() ;++j )
        {

          Node_list[i]->edges()[j]->set_weight_to(Generate_Rand(1,20));

        }

    }
}

void Visualization::prepare_table()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setShowGrid(true);
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->setRowCount(ui->spinBox_2->value());
    QTableWidgetItem* item = new QTableWidgetItem;
    item->setText("Вершина");
    item->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setHorizontalHeaderItem(0,item);
    QTableWidgetItem* item1 = new QTableWidgetItem;
    item1->setText("Досягаемый");
    item1->setTextAlignment(Qt::AlignCenter);
      ui->tableWidget->setHorizontalHeaderItem(1,item1);
      QTableWidgetItem* item2 = new QTableWidgetItem;
      item2->setText("Цена");
       item2->setTextAlignment(Qt::AlignCenter);
       ui->tableWidget->setHorizontalHeaderItem(2,item2);
         QTableWidgetItem* item3 = new QTableWidgetItem;
        item3->setText("Путь");
        item3->setTextAlignment(Qt::AlignCenter);
         ui->tableWidget->setHorizontalHeaderItem(3,item3);
        for (int i=0;i<ui->spinBox_2->value();++i )
        {
            QTableWidgetItem* item4 = new QTableWidgetItem;
            QTableWidgetItem* item_h = new QTableWidgetItem;
            QTableWidgetItem *item_inf = new QTableWidgetItem;
            item_inf->setText("∞");
            item_inf->setTextAlignment(Qt::AlignCenter);
           item4->setText("нет");
           item4->setTextAlignment(Qt::AlignCenter);
           item_h->setText("№ "+QString::number(i+1));
           item_h->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(i, 1, item4);
            ui->tableWidget->setItem(i,0,item_h);
            ui->tableWidget->setItem(i,2,item_inf);
        }


        ui->tableWidget->resizeColumnsToContents();

}

void Visualization::on_spinBox_2_valueChanged(int arg1)
{
    for (int i = 0;i<Node_list.size() ;++i)
    {
       Node_list[i]->is_used = false;
       Node_list[i]->finished = false;
       Node_list[i]->update();
       Node_list[i]->shortest_weight = "∞";
       Scene->alg_started = false;
       Scene->viewport()->repaint();
    }

  ui->textBrowser->clear();
    Scene->finished_adjusting = false;
    Scene->timer_used_for = 0;
    if(Node_list.size()!= 12 && Node_list.size()<arg1)
    {
        ui->spinBox->setMaximum(ui->spinBox_2->value());
        Node *node = new Node(Scene,arg1-1);
        Node_list.push_back(node);
        int16_t temp = Generate_Rand(1,20);
        Scene->Draw_scene->addItem(node);
        int16_t temp1 =Generate_Rand(0,Node_list.size()-1);
        Node_list.back()->setPos(Node_list.at(temp1)->x()+30, Node_list.at(temp1)->y()+30);
        if(!ui->checkBox_2->isChecked())
        {
        Scene->Draw_scene->addItem(new Edge(Node_list.at(Node_list.size()-1), Node_list.at(temp1),temp));
        }
        else
        {
             Scene->Draw_scene->addItem(new Edge(Node_list.at(temp1), Node_list.at(Node_list.size()-1) ,temp));
        }

    }
    else
    {
        ui->spinBox->setMaximum(ui->spinBox_2->value());
        Scene->Draw_scene->removeItem(Node_list[arg1]);
        for (int i=0;i<Node_list[arg1]->edges().size() ;++i )
        {
             Scene->Draw_scene->removeItem(Node_list[arg1]->edges()[i]);
        }
        Node_list.erase(Node_list.begin()+arg1);
    }
    prepare_table();

}

void Visualization::on_pushButton_2_clicked()
{
    for (int i = 0;i<Node_list.size() ;++i)
    {
       Node_list[i]->is_used = false;
       Node_list[i]->finished = false;
       Node_list[i]->update();
       Node_list[i]->shortest_weight = "∞";
       Scene->alg_started = false;
       Generate_weight();
       Scene->viewport()->repaint();
    }
    ui->tableWidget->clear();
    ui->textBrowser->clear();
    ui->textBrowser->append("Можете нажимать на узлы для их перемещения, а также приближать изображение с помощью прокрутки колеса мыши или по нажатию '+' и '-'");
    prepare_table();
}

void Visualization::on_pushButton_3_clicked()
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
    Theory *Window = new Theory(this);
    Window->setAttribute(Qt::WA_DeleteOnClose);
    Window->setModal(false);
    Window->show();
    }
}

void Visualization::on_checkBox_2_stateChanged(int arg1)
{
    GraphWidget::is_oriented = arg1;
    if(arg1)
    {
    Directed_graph_init();
    }
    else
    {
        Undirected_graph_init();
    }
    ui->pushButton_2->click();
}




void Visualization::on_checkBox_stateChanged(int arg1)
{
    double time = 1000000000;
    QTime dieTime= QTime::currentTime().addMSecs(time);
    while (QTime::currentTime() < dieTime && arg1)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
