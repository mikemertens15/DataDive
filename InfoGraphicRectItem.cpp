#include "InfoGraphicRectItem.h"

InfoGraphicRectItem::InfoGraphicRectItem(int data, Node<int>* nextNode, qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent)
    : QGraphicsRectItem(x, y, width, height, parent), nodeData(data), nextNodeAddress(nextNode)
{
    setAcceptHoverEvents(true);
}

void InfoGraphicRectItem::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
    QString tooltipText = QString("Data: %1\nNext Node: 0x%2").arg(nodeData).arg(reinterpret_cast<quintptr>(nextNodeAddress), 0, 16); // Display pointer in hex
    QToolTip::showText(event->screenPos(), tooltipText);
}

void InfoGraphicRectItem::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
    QToolTip::hideText();
}

int InfoGraphicRectItem::getData() { return nodeData; }
