#ifndef LINKEDLISTWIDGET_H
#define LINKEDLISTWIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include "linkedList.h"

namespace Ui {
class LinkedListWidget;
}

class LinkedListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LinkedListWidget(QWidget *parent = nullptr);
    ~LinkedListWidget();
    void highlightNode(int data, QColor color);
    void updateUI();
    void onNodeFound(int data);
    void onNodeVisited(int data);

public slots:
    void onAddButtonClicked();
    void onDeleteButtonClicked();
    void onSearchButtonClicked();
    void onResetButtonClicked();
    void onNodeColorButtonClicked();

private:
    Ui::LinkedListWidget *ui;
    QGraphicsScene* scene;
    QColor nodeColor;
    Linked_List<int> myList;
};

#endif // LINKEDLISTWIDGET_H
