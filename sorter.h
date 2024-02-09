#ifndef SORTER_H
#define SORTER_H

#include <QObject>
#include <QTimer>
#include "node.h"
#include "nodeSignaler.h"

class Sorter : public QObject
{
    Q_OBJECT
public:
    Sorter(QObject* parent = nullptr);
    void sort(Node<int>* head, NodeSignaler* signaler);


private slots:
    void performSortStep();

signals:
    void sortingCompleted();

private:
    Node<int>* head;
    Node<int>* current;
    Node<int>* next;
    QTimer* timer;
    NodeSignaler* signaler;
};

#endif // SORTER_H
