#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <QThread>
#include "nodeSignaler.h"

#pragma once

template <typename T>
class Linked_List
{
private:
    Node<T> *head;
    int length;
    NodeSignaler* signaler;

public:
    Linked_List() : head(nullptr), length(0), signaler(new NodeSignaler()) {}

    ~Linked_List()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
        delete signaler;
    }

    bool is_empty() { return head == nullptr; }

    void clear() {
        Node<T> *current = head;
        while (current != nullptr)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    Node<T>* getHead()
    {
        if (!is_empty()) {return head;}
        else return nullptr;
    }

    void insert_at_front(T data)
    {
        Node<T> *new_node = new Node<T>(data);
        new_node->next = head;
        head = new_node;
        length++;
    }

    void insert_at_back(T data)
    {
        Node<T> *new_node = new Node<T>(data);
        if (head == nullptr)
        {
            head = new_node;
            return;
        }
        Node<T> *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new_node;
        length++;
    }

    void delete_front()
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }

    void delete_back()
    {
        Node<T> *current = head;
        while (current->next->next != nullptr)
        {
            current = current->next;
        }
        Node<T> *temp = current->next;
        current->next = nullptr;
        delete temp;
    }
    void delete_value(T data)
    {
        // if list is empty
        if (this->is_empty())
        {
            return;
        }

        // if head is the value
        if (head->data == data)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T> *current = head;
        while (current->next != nullptr && current->next->data != data)
        {
            current = current->next;
        }

        if (current->next != nullptr)
        {
            Node<T> *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    void search(T data)
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            signaler->emitNodeVisited(current);
            QThread::sleep(1); // Slow down the search for visualization
            if (current->data == data) {
                signaler->emitNodeFound(current);
                return;
            }
            current = current->next;
        }
        signaler->emitNodeFound(nullptr); // Indicate node was not found
    }

    NodeSignaler* getSignaler() { return signaler; }

    T peek_front() { return head->data; }

    T peek_back()
    {
        Node<T> *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        return current->data;
    }

    int size() { return length; }

    Node<T> *sort()
    {
        Node<T> *current = head;
        Node<T> *next = nullptr;
        T temp;
        while (current != nullptr)
        {
            next = current->next;
            while (next != nullptr)
            {
                if (current->data > next->data)
                {
                    temp = current->data;
                    current->data = next->data;
                    next->data = temp;
                }
                next = next->next;
            }
            current = current->next;
        }
        return head;
    }
};

#endif // LINKEDLIST_H
