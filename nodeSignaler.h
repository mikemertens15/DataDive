#ifndef NODESIGNALER_H
#define NODESIGNALER_H

#include <QObject>
#include "node.h"

class NodeSignaler: public QObject {
    Q_OBJECT

public:
    void emitNodeVisited(Node<int>* node) { emit nodeVisited(node); }
    void emitNodeFound(Node<int>* node) { emit nodeFound(node); }

signals:
    void nodeVisited(Node<int>* node);
    void nodeFound(Node<int>* node);
};

#endif // NODESIGNALER_H
