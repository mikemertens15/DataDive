#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#pragma once

template <typename T>
struct Node
{
    T data;
    Node *next;

    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class Linked_List
{
private:
    Node<T> *head;
    int length;

public:
    Linked_List() : head(nullptr) {}

    ~Linked_List()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
    }

    bool is_empty() { return head == nullptr; }

    Node<T>* getHead()
    {
        if (!is_empty()) {return head;}
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

    Node<T> *search(T data)
    {
        Node<T> *current = head;
        while (current->data != data && current != nullptr)
        {
            current = current->next;
        }
        return current;
    }

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
};

#endif // LINKEDLIST_H
