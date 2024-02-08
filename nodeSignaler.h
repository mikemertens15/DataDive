#ifndef NODESIGNALER_H
#define NODESIGNALER_H

#include <QObject>
#include "node.h"

class NodeSignaler: public QObject {
    Q_OBJECT

public:
    void emitNodeVisited(Node<int>* node) { emit nodeVisited(node); }
    void emitNodeFound(Node<int>* node) { emit nodeFound(node); }
    void emitNodesComparing(Node<int>* node1, Node<int>* node2) { emit nodesComparing(node1, node2); }
    void emitNodesSwapped(Node<int>* node1, Node<int>* node2) {emit nodesSwapped(node1, node2);}

signals:
    void nodeVisited(Node<int>* node);
    void nodeFound(Node<int>* node);
    void nodesComparing(Node<int>* node1, Node<int>* node2);
    void nodesSwapped(Node<int>* node1, Node<int>* node2);
};

#endif // NODESIGNALER_H
