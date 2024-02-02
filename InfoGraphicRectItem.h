#ifndef INFOGRAPHICRECTITEM_H
#define INFOGRAPHICRECTITEM_H

#include "linkedList.h"
#include <QGraphicsRectItem>
#include <QGraphicsSceneHoverEvent>
#include <QToolTip>

class InfoGraphicRectItem : public QGraphicsRectItem
{
public:
    InfoGraphicRectItem(Node<int>* node, qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent = nullptr);
    Node<int>* getNode();

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;

private:
    Node<int>* node;
};

#endif // INFOGRAPHICRECTITEM_H
