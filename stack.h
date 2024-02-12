#ifndef STACK_H
#define STACK_H

#pragma once
#include <stdexcept>
#include "node.h"

template <typename T>
class Stack
{
private:
    Node<T> *head;
    int stack_size;

public:
    // Default Constructor
    Stack() : head(nullptr) {}

    // Constructor with initial value
    Stack(T data)
    {
        head = new Node<T>(data);
        stack_size = 1;
    }

    // Copy Constructor
    Stack(const Stack &stack)
    {
        this->head = stack.head;
        this->stack_size = stack.stack_size;
    }

    // Move Constructor
    Stack(Stack &&stack)
    {
        this->head = stack.head;
        this->stack_size = stack.stack_size;
        stack.head = nullptr;
        stack.stack_size = 0;
    }

    // Destructor
    ~Stack()
    {
        while (head != nullptr)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }

    int size() { return stack_size; }

    bool is_empty() { return head == nullptr; }

    void push(T data)
    {
        Node<T> *new_node = new Node<T>(data);
        new_node->next = head;
        head = new_node;
        stack_size++;
    }

    T peek()
    {
        if (is_empty())
        {
            throw std::out_of_range("Stack is empty");
        }
        return head->data;
    }

    void pop()
    {
        if (is_empty())
        {
            throw std::out_of_range("Stack is empty");
        }
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        stack_size--;
    }
};

#endif // STACK_H
