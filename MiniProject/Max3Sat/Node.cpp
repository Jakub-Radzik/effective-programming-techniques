//
// Created by Jakub Radzik on 20/12/2021.
//

#include <iostream>
#include "Node.h"

Node::Node(int iVariable, bool bValue) {
    this->i_variable = iVariable;
    this->b_value = bValue;
    i_ref_count = 1;
}

Node::~Node() = default;

const int &Node::iGetVariable() const {
    return i_variable;
}

void Node::vSetVariable(const int &iVariable) {
    i_variable = iVariable;
}

bool Node::bGetValue() const {
    return b_value;
}

void Node::vSetValue(bool bValue) {
    b_value = bValue;
}

void Node::vIncrementRefCount() {
    i_ref_count++;
}

void Node::vDecrementRefCount() {
    i_ref_count--;
}

int Node::iGetRefCount() const {
    return i_ref_count;
}

int Node::getIIndex() const {
    return i_index;
}

void Node::setIIndex(int iIndex) {
    i_index = iIndex;
}
