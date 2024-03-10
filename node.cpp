/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "edge.h"
#include "node.h"
#include "graphwidget.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOption>

//! [0]
Node::Node(GraphWidget *graphWidget,int Num)
    : graph(graphWidget)
{
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
    setCacheMode(DeviceCoordinateCache);
    setZValue(-1);
    Num_Node = Num;
    shortest_weight = "∞";
    is_used = false;
    finished = false;
}
//! [0]

//! [1]
void Node::addEdge(Edge *edge)
{
    edgeList << edge;
    edge->adjust();
}

QVector<Edge *> Node::edges() const
{
    return edgeList;
}
//! [1]

//! [2]
void Node::calculateForces()
{
    if (!scene() || scene()->mouseGrabberItem() == this) {
        newPos = pos();
        return;
    }
//! [2]

//! [3]
    // Sum up all forces pushing this item away
    qreal xvel = 0;
    qreal yvel = 0;
    const QList<QGraphicsItem *> items = scene()->items();
    for (QGraphicsItem *item : items)
    {
        Node *node = qgraphicsitem_cast<Node *>(item);
        if (!node)
            continue;

        QPointF vec = mapToItem(node, 0, 0);
        qreal dx = vec.x();
        qreal dy = vec.y();
        double l = 2.0 * (dx * dx + dy * dy);
        if (l > 0)
        {
            xvel += (dx * 250.0) / l;
            yvel += (dy * 250.0) / l;
        }
    }
//! [3]

//! [4]
    // Now subtract all forces pulling items together
    double weight = (edgeList.size() + 1) * 10;
    for (const Edge *edge : qAsConst(edgeList))
    {
        QPointF vec;
        if (edge->sourceNode() == this)
            vec = mapToItem(edge->destNode(), 0, 0);
        else
            vec = mapToItem(edge->sourceNode(), 0, 0);
        xvel -= vec.x() / weight;
        yvel -= vec.y() / weight;
    }
//! [4]

//! [5]
    if (qAbs(xvel) < 0.1 && qAbs(yvel) < 0.1)
        xvel = yvel = 0;
//! [5]

//! [6]
    QRectF sceneRect = scene()->sceneRect();
    newPos = pos() + QPointF(xvel, yvel);
    newPos.setX(qMin(qMax(newPos.x(), sceneRect.left() + 20), sceneRect.right() - 20));
    newPos.setY(qMin(qMax(newPos.y(), sceneRect.top() + 20), sceneRect.bottom() - 20));
}
//! [6]

//! [7]
bool Node::advancePosition()
{
    if (newPos == pos())
        return false;

    setPos(newPos);
    return true;
}

bool Node::check_is_connected(int num)
{
    for (int i = 0;i<edgeList.size() ;++i )
    {
        if(edgeList[i]->destNode()->Num_Node == num)
        {
            return true;
        }
    }
    return false;
}
//! [7]

//! [8]
QRectF Node::boundingRect() const
{
    return QRectF( -20, -20, 60, 60);
}
//! [8]

//! [9]
QPainterPath Node::shape() const
{
    QPainterPath path;
    path.addEllipse(-20, -20, 40, 40);
    return path;
}
//! [9]

//! [10]
void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    painter->setBrush(Qt::green);
    painter->setPen(QPen(Qt::black,1));
    QRect Initial_pos(-20,-20,40,40);
    if (option->state & QStyle::State_Sunken)
    {
         painter->setBrush(Qt::darkGreen);
    }
    if (option->state & QStyle::State_Sunken && is_used)
    {
         painter->setBrush(Qt::darkRed);
    }
    if (is_used)
    {
         painter->setBrush(Qt::red);
    }
    if (finished)
    {
         painter->setBrush(Qt::cyan);
    }
    if (option->state & QStyle::State_Sunken && finished)
    {
         painter->setBrush(Qt::darkCyan);
    }
    painter->drawEllipse(Initial_pos);

    painter->drawText(-5,3,QString::number(Num_Node+1));
    painter->drawText(25,10,shortest_weight);


}





QPointF Node::get_Pos()
{
    return newPos;
}


//! [10]

//! [11]
QVariant Node::itemChange(GraphicsItemChange change, const QVariant &value)
{

    switch (change)
    {
    case ItemPositionHasChanged:
        for (Edge *edge : qAsConst(edgeList))
            edge->adjust();
        graph->itemMoved();
        //если после перетаскивания узла его вытащили за границу - включить таймер
        if (this->x() > 600 || this->x()< 0 || this->y() > 600 || this->y()< 0)
        {
            graph->timer_used_for = 0;
        }
        break;
    default:
        break;
    };

    return QGraphicsItem::itemChange(change, value);
}
//! [11]

//! [12]
void Node::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    for (Edge *edge : qAsConst(edgeList))
        edge->adjust();
    graph->itemMoved();

    graph->repaint();
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Node::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    for (Edge *edge : qAsConst(edgeList))
        edge->adjust();
    graph->itemMoved();

    graph->repaint();
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
//! [12]

