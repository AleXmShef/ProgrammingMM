//
// Created by yuna on 19.11.18.
//

#include "Node.h"

Node *Node::copy() const {
    return new Node(data, prev, next);
}

Node::Node(float const data, Node *const prev, Node *const next) : data(data), prev(prev), next(next) {}
