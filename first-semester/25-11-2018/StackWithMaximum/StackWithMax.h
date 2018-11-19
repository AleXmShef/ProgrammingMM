//
// Created by yuna on 19.11.18.
//

#ifndef STACKWITHMAXIMUM_STACKWITHMAX_H
#define STACKWITHMAXIMUM_STACKWITHMAX_H


#include "Node.h"
#include "Stack.h"

class StackWithMax {
    Node *head;
    int count;
    Stack maxElStack;

public:
    StackWithMax();

    void push(int data);

    void pop();

    int top();

    bool isEmpty();

    int getMax();

    ~StackWithMax();
};


#endif //STACKWITHMAXIMUM_STACKWITHMAX_H
