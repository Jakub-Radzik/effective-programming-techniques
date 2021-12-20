//
// Created by Jakub Radzik on 20/12/2021.
//

#include "Node.h"

Node::Node(std::string iVariable, bool bValue) {
    this->i_variable = std::move(iVariable);
    this->b_value = bValue;
}

Node::~Node() = default;

const std::string &Node::getIVariable() const {
    return i_variable;
}

void Node::setIVariable(const std::string &iVariable) {
    i_variable = iVariable;
}

bool Node::isBValue() const {
    return b_value;
}

void Node::setBValue(bool bValue) {
    b_value = bValue;
}
