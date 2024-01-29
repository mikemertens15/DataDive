#ifndef NODESIGNALER_H
#define NODESIGNALER_H

#include <QObject>

class NodeSignaler: public QObject {
    Q_OBJECT

public:
    void emitNodeVisited(int nodeData) { emit nodeVisited(nodeData); }
    void emitNodeFound(int nodeData) { emit nodeFound(nodeData); }

signals:
    void nodeVisited(int nodeData);
    void nodeFound(int nodeData);
};

#endif // NODESIGNALER_H
