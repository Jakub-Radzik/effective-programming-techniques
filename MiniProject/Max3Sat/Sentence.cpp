//
// Created by Jakub Radzik on 21/12/2021.
//

#include "Sentence.h"

//Flagged Variable

FlaggedVariable::FlaggedVariable(Node *node, bool bShouldBeNegated) {
    this->node = node;
    this->b_should_be_negated = bShouldBeNegated;
}

FlaggedVariable::~FlaggedVariable() {
    if (node->iGetRefCount() == 1) {
        delete node;
    }
    node->vDecrementRefCount();
}

bool FlaggedVariable::bResolveNode() {
    return b_should_be_negated ? !this->node->bGetValue() : this->node->bGetValue();
}

void FlaggedVariable::vReplaceNode(Node *node) {
    if(this->node->iGetRefCount() == 1) {
        delete this->node;
    }else{
        this->node->vDecrementRefCount();
    }

    node->vIncrementRefCount();
    this->node = node;
}

Node *FlaggedVariable::getNode() const {
    return node;
}

//Sentence

Sentence::Sentence(int iVariablesCount) {
    i_variables_count = iVariablesCount;
    v_flagged_variables = std::vector<FlaggedVariable *>();
}

Sentence::~Sentence() {
    for (FlaggedVariable *flagged_variable: v_flagged_variables) {
        delete flagged_variable;
    }
}

void Sentence::vAddVariable(Node *node, bool bShouldBeNegated) {
    v_flagged_variables.push_back(new FlaggedVariable(node, bShouldBeNegated));
}

bool Sentence::bResolveSentence() {
    for (int i = 0; i < i_variables_count; ++i) {
        if (v_flagged_variables[i]->bResolveNode()) {
            return true;
        }
    }
    return false;
}

int Sentence::iGetVariable(int iIndex) {
    return v_flagged_variables[iIndex]->getNode()->iGetVariable();
}

void Sentence::vReplaceNodeAt(int iIndex, Node *node) {
    v_flagged_variables[iIndex]->vReplaceNode(node);
}

Node *Sentence::nGetNodeAt(int iIndex) {
    return v_flagged_variables[iIndex]->getNode();
}

