//
// Created by yuna on 19.11.18.
//

#ifndef STACKWITHMAXIMUM_STACK_H
#define STACKWITHMAXIMUM_STACK_H

#include "Node.h"

struct Stack {
    Node *head;
    int count;

    Stack();

    void push(int data);

    void pop();

    int top();

    bool isEmpty();

    ~Stack();
};



#endif //STACKWITHMAXIMUM_STACK_H
