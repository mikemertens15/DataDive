#ifndef INFOGRAPHICRECTITEM_H
#define INFOGRAPHICRECTITEM_H

#include "node.h"
#include <QGraphicsRectItem>
#include <QGraphicsSceneHoverEvent>
#include <QToolTip>

class InfoGraphicRectItem : public QGraphicsRectItem
{
public:
    InfoGraphicRectItem(Node<int>* node, qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent = nullptr);
    Node<int>* getNode();
    void setNode(Node<int>* node);

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;

private:
    Node<int>* node;
};

#endif // INFOGRAPHICRECTITEM_H
