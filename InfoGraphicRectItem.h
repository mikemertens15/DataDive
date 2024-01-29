#ifndef INFOGRAPHICRECTITEM_H
#define INFOGRAPHICRECTITEM_H

#include "linkedList.h"
#include <QGraphicsRectItem>
#include <QGraphicsSceneHoverEvent>
#include <QToolTip>

class InfoGraphicRectItem : public QGraphicsRectItem
{
public:
    InfoGraphicRectItem(int data, Node<int>* nextNode, qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent = nullptr);
    int getData();

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;

private:
    int nodeData;
    Node<int>* nextNodeAddress;
};

#endif // INFOGRAPHICRECTITEM_H
