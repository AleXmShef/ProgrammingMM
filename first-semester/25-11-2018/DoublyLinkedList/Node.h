//
// Created by yuna on 19.11.18.
//

#ifndef DOUBLYLINKEDLIST_NODE_H
#define DOUBLYLINKEDLIST_NODE_H


struct Node {
    explicit Node(float const data, Node *const prev, Node *const next);

    Node *copy() const;

    float data;
    Node *prev;
    Node *next;
};


#endif //DOUBLYLINKEDLIST_NODE_H
