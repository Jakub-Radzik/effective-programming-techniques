//
// Created by Jakub Radzik on 21/12/2021.
//

#include <iostream>
#include "Sentence.h"

//Flagged Variable

FlaggedVariable::FlaggedVariable(Node *node, bool bShouldBeNegated) {
    this->node = node;
    this->b_should_be_negated = bShouldBeNegated;
}

FlaggedVariable::~FlaggedVariable() {
    std::cout << "Deleting FlaggedVariable" << std::endl;
    if (node->getIRefCount() == 1) {
        delete node;
    }
    node->decrementRefCount();
}

bool FlaggedVariable::resolveNode() {
    return b_should_be_negated ? !this->node->isBValue() : this->node->isBValue();
}

void FlaggedVariable::replaceNode(Node *node) {
    if(this->node->getIRefCount() == 1) {
        delete this->node;
    }else{
        this->node->decrementRefCount();
    }

    node->incrementRefCount();
    this->node = node;
}

Node *FlaggedVariable::getNode() const {
    return node;
}

bool FlaggedVariable::isBShouldBeNegated() const {
    return b_should_be_negated;
}

//Sentence

Sentence::Sentence(int iVariablesCount) {
    i_variables_count = iVariablesCount;
    flagged_variables = std::vector<FlaggedVariable *>();
}

Sentence::~Sentence() {
    std::cout << "Deleting Sentence" << std::endl;
    for (FlaggedVariable *flagged_variable: flagged_variables) {
        delete flagged_variable;
    }
}

void Sentence::addVariable(Node *node, bool bShouldBeNegated) {
    flagged_variables.push_back(new FlaggedVariable(node, bShouldBeNegated));
}

bool Sentence::resolveSentence() {
    for (int i = 0; i < i_variables_count; ++i) {
        if (flagged_variables[i]->resolveNode()) {
            return true;
        }
    }
    return false;
}

int Sentence::getVariable(int iIndex) {
    return flagged_variables[iIndex]->getNode()->getIVariable();
}

void Sentence::replaceNodeAt(int iIndex, Node *node) {
    flagged_variables[iIndex]->replaceNode(node);
}

Node *Sentence::getNodeAt(int iIndex) {
    return flagged_variables[iIndex]->getNode();
}

bool Sentence::isVariableNegated(int iIndex) {
    return flagged_variables[iIndex]->isBShouldBeNegated();
}

