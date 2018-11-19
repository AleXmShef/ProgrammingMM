//
// Created by yuna on 16.11.18.
//

#ifndef SEQUENCEOFBRACKETS_STACK_H
#define SEQUENCEOFBRACKETS_STACK_H


#include "Node.h"

class Stack {
    Node *head;
    int count;
public:
    Stack();

    void push(int data);

    int pop();

    bool isEmpty();

    ~Stack();
};

#endif //SEQUENCEOFBRACKETS_STACK_H

