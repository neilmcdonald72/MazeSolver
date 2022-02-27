#ifndef _STACK_H
#define _STACK_H

#include "coordinate.h"
#include <iostream>

class Node {
public:
    Coordinate m_data {-1, -1};
    Node* m_next {nullptr};
};

class Stack {
private:
    Node* m_top {nullptr};

public:
    Stack() = default;
    virtual ~Stack();

    void push(Coordinate num);
    Coordinate peek();
    void pop();
    int count();

    friend std::ostream& operator<<(std::ostream& output, Stack& stack);
};

std::ostream& operator<<(std::ostream& output, Stack& stack);

#endif