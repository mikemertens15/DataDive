#include "InfoGraphicRectItem.h"

InfoGraphicRectItem::InfoGraphicRectItem(Node<int>* node, qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent)
    : QGraphicsRectItem(x, y, width, height, parent), node(node)
{
    setAcceptHoverEvents(true);
}

void InfoGraphicRectItem::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
    QString tooltipText = QString("Data: %1\nNext Node: 0x%2").arg(node->data).arg(reinterpret_cast<quintptr>(node->next), 0, 16); // Display pointer in hex
    QToolTip::showText(event->screenPos(), tooltipText);
}

void InfoGraphicRectItem::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
    QToolTip::hideText();
}

void InfoGraphicRectItem::setNode(Node<int>* node) { this->node = node; }

Node<int>* InfoGraphicRectItem::getNode() { return node; }
