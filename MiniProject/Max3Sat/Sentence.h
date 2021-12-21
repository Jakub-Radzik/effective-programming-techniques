//
// Created by Jakub Radzik on 21/12/2021.
//

#ifndef MINIPROJECT_SENTENCE_H
#define MINIPROJECT_SENTENCE_H


#include <vector>
#include "Node.h"


class FlaggedVariable {
public:
    FlaggedVariable(Node *node, bool bShouldBeNegated);
    ~FlaggedVariable();
    void replaceNode(Node *node);
    bool resolveNode();
    Node *getNode() const;

    bool isBShouldBeNegated() const;

private:
    Node *node;
    bool b_should_be_negated;
};


class Sentence {
public:
    Sentence(int iVariablesCount);
    ~Sentence();
    void addVariable(Node *node, bool bShouldBeNegated);
    bool resolveSentence();
    void replaceNodeAt(int iIndex, Node *node);
    Node *getNodeAt(int iIndex);
    int getVariable(int iIndex);
    bool isVariableNegated(int iIndex);

private:
    int i_variables_count;
    std::vector<FlaggedVariable *> flagged_variables;
};

#endif //MINIPROJECT_SENTENCE_H
