//
// Created by ricnorr on 26.01.2021.
//

#include "string"
#ifndef CPP_TASKS_DEQUE_H
#define CPP_TASKS_DEQUE_H

class Node {
private:
    int data;
    Node *left;
    Node *right;
public:
    int getData() const;

    Node *getLeft() const;

    Node *getRight() const;

    void setData(int data);

    void setLeft(Node *left);

    void setRight(Node *right);
};

class Deque {
private:
    Node *head;
    Node *tail;
    int size;

    Node *getHead() const;

    Node *getTail() const;

public:
    int getSize() const;

    int popFront();

    void pushBack(int);

    void pushFront(int);

    int popBack();

    std::string getString();
};

#endif //CPP_TASKS_DEQUE_H
