#include "sorter.h"

Sorter::Sorter(QObject* parent) : QObject(parent), head(nullptr), current(nullptr), next(nullptr) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Sorter::performSortStep);
}

void Sorter::sort(Node<int>* head, NodeSignaler* signaler) {
    this->head = head;
    this->signaler = signaler;
    current = head;
    next = current ? current->next : nullptr;
    timer->start(1000);
}

void Sorter::performSortStep() {
    if (!current || !next) {
        timer->stop();
        emit sortingCompleted();
        return;
    }

    if (current->data > next->data) {
        std::swap(current->data, next->data);
        signaler->emitNodesSwapped(current, next);
    }

    next = next->next;
    if (!next) {
        current = current->next;
        next = current ? current->next : nullptr;
    }
}


