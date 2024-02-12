#ifndef DATASTRUCTUREWIDGET_H
#define DATASTRUCTUREWIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QColor>
#include <QGraphicsRectItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QColorDialog>
#include <QMessageBox>
#include "sorter.h"
#include "node.h"

class DataStructureWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DataStructureWidget(QWidget *parent = nullptr);
    virtual ~DataStructureWidget();
    void onNodeFound(Node<int>* node);
    void onNodeVisited(Node<int>* node);
    void onNodeComparing(Node<int>* node1, Node<int>* node2);
    void onNodeSwapped(Node<int>* node1, Node<int>* node2);
    void startSorting();

protected:
    QGraphicsScene *scene;
    QColor nodeColor;
    Sorter* sorter;

    virtual void updateUI() = 0; // Pure structures update their UI
    virtual void onAddButtonClicked() = 0; // All structures should add nodes
    virtual void onDeleteButtonClicked() = 0; // All structures should delete nodes
    virtual void onSearchButtonClicked() = 0; // All structures should have a basic search
    virtual void onResetButtonClicked() = 0; // All structures should clear their widgets

    void highlightNode(Node<int>* node, const QColor& color);


public slots:
    void onNodeColorButtonClicked();
    void onSortingCompleted();
};

#endif // DATASTRUCTUREWIDGET_H
