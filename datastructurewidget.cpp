#include "datastructurewidget.h"
#include "InfoGraphicRectItem.h"
#include <QColorDialog>
#include <QMessageBox>
#include <QCoreApplication>
#include <QGraphicsItem>

DataStructureWidget::DataStructureWidget(QWidget *parent)
    : QWidget(parent), scene(new QGraphicsScene(this)), nodeColor(Qt::lightGray) {
}

DataStructureWidget::~DataStructureWidget() {
    delete scene;
}

void DataStructureWidget::onNodeVisited(Node<int>* node)
{
    // Highlight the node with the 'nodeData' temporarily
    highlightNode(node, Qt::yellow);
    QCoreApplication::processEvents(); // Process events to update UI
}

void DataStructureWidget::onNodeFound(Node<int>* node)
{
    // Permanently highlight node with 'nodeData'
    if (node != nullptr) highlightNode(node, Qt::green);
    else QMessageBox::information(this, "Search Result", "Node not found");
}

void DataStructureWidget::onNodeComparing(Node<int>* node1, Node<int>* node2)
{
    // Highlight the nodes being compared
    highlightNode(node1, Qt::blue);
    highlightNode(node2, Qt::blue);
    QCoreApplication::processEvents(); // Process events to update UI
}

void DataStructureWidget::onNodeSwapped(Node<int>* node1, Node<int>* node2)
{
    // Swap the nodes in the UI
    for (QGraphicsItem* item : scene->items()) {
        InfoGraphicRectItem* rectItem = dynamic_cast<InfoGraphicRectItem*>(item);
        if (rectItem && rectItem->getNode() == node1) {
            rectItem->setNode(node2);
        }
        else if (rectItem && rectItem->getNode() == node2) {
            rectItem->setNode(node1);
        }
    }
    QCoreApplication::processEvents(); // Process events to update UI
}

void DataStructureWidget::highlightNode(Node<int>* node, const QColor& color) {
    for (QGraphicsItem* item : scene->items()) {
        InfoGraphicRectItem* rectItem = dynamic_cast<InfoGraphicRectItem*>(item);
        if (rectItem && rectItem->getNode() == node) {
            rectItem->setBrush(color);
            break;
        }
    }
}

void DataStructureWidget::onNodeColorButtonClicked() {
    QColor color = QColorDialog::getColor(Qt::white, this, "Select node color");
    if (color.isValid()) nodeColor = color;
}
