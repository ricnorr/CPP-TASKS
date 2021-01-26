//
// Created by ricnorr on 26.01.2021.
//
#include "iostream"
#include <iostream>
#include "string"

class Node {
private:
    int data = 0;
    Node *left = nullptr;
    Node *right = nullptr;
public:
    Node(Node *left, Node *right, int data) : left(left), right(right), data(data) {}

    explicit Node(int data) : data(data) {}

    int getData() const {
        return data;
    }

    Node *getLeft() const {
        return left;
    }

    Node *getRight() const {
        return right;
    }

    void setData(int data) {
        Node::data = data;
    }

    void setLeft(Node *left) {
        Node::left = left;
    }

    void setRight(Node *right) {
        Node::right = right;
    }
};


class Deque {
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;

    Node *getHead() const {
        return head;
    }

    Node *getTail() const {
        return tail;
    }

public:
    Deque(const Node &node) {
        size = 1;
        head = new Node(node.getData());
    }

    Deque() {}

    Deque(const Deque &deque) {
        Node *cur = deque.getHead();
        while (cur != nullptr) {
            pushBack(cur->getData());
            cur = cur->getRight();
        }
    }

    ~Deque() {
        while (getSize() > 0) {
            popFront();
        }
    }

    Deque operator=(const Deque &deque) { //
        if (this == &deque) {
            return *this;
        }
        while (getSize() > 0) {
            popFront();
        }
        Node *cur = deque.getHead();
        while (cur != nullptr) {
            pushBack(cur->getData());
            cur = cur->getRight();
        }
        return *this;
    }

    Deque &operator+=(const int value) {
        pushBack(value);
        return *this;
    }

    Deque &operator+=(const Deque &deque) {
        if (deque.getSize() != 0) {
            const Deque copyDeque = deque;
            tail->setRight(copyDeque.getHead());
            tail = copyDeque.getTail();
        }
        return *this;
    }

    Deque operator+(const Deque &deque) {
        Deque copy = *this;
        copy += deque;
        return (copy += deque);
    }

    int getSize() const {
        return size;
    }

    int popFront() {
        if (size == 0) {
            return -1;
        }
        int result = getHead()->getData();
        Node * prev = head;
        head = head->getRight();
        delete prev;
        size--;
        if (getSize() == 0) {
            tail = nullptr;
        } else {
            head->setLeft(nullptr);
        }
        return result;
    }

    void pushBack(const int value) {
        if (tail == nullptr) {
            head = new Node(value);
            tail = head;
        } else {
            tail = new Node(tail, nullptr, value);
            tail->getLeft()->setRight(tail);
        }
        size++;
    }

    void pushFront(const int value) {
        if (getSize() == 0) {
            pushBack(value);
        } else {
            head = new Node(nullptr, head, value);
            head->getRight()->setLeft(head);
            size++;
        }
    }

    int popBack() {
        if (getSize() == 0) {
            return -1;
        } else {
            int result = tail->getData();
            Node * prev = tail;
            tail = tail->getLeft();
            delete prev;
            size--;
            if (getSize() == 0) {
                head = nullptr;
            } else {
                tail->setRight(nullptr);
            }
            return result;
        }
    }

    std::string getString() {
        std::string s;
        Node *cur = head;
        while (cur != nullptr) {
            s += std::to_string(cur->getData());
            s += " ";
            cur = cur->getRight();
        }
        return s;
    }
};


int main() {
    Deque deque = Deque();
    for (int i = 0; i < 5; i++) {
        deque+=i;
    }
    for (int i = 0; i < 1; i++) {
        deque.popFront();
        deque.popBack();
    }
    deque = deque;
    for (int i = 0; i < 5; i++) {
        deque+=i;
    }
    Deque deque1 = Deque();
    deque1 = deque;
    for (
            int i = 0; i < 10; i++) {
        deque1.pushFront(0);
    }
    std::cout << deque1.getString();
}
