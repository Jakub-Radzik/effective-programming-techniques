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

Node::~Node() {
    std::cout << "Node " << i_variable << " deleted" << std::endl;
}

const int &Node::getIVariable() const {
    return i_variable;
}

void Node::setIVariable(const int &iVariable) {
    i_variable = iVariable;
}

bool Node::isBValue() const {
    return b_value;
}

void Node::setBValue(bool bValue) {
    b_value = bValue;
}

void Node::incrementRefCount() {
    i_ref_count++;
}

void Node::decrementRefCount() {
    i_ref_count--;
}

int Node::getIRefCount() const {
    return i_ref_count;
}
