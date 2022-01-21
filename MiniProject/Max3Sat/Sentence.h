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
    void vReplaceNode(Node *node);
    bool bResolveNode();
    Node *getNode() const;

    bool bShouldBeNegated() const;

private:
    Node *node;
    bool b_should_be_negated;
};


class Sentence {
public:
    Sentence(int iVariablesCount);
    ~Sentence();
    void vAddVariable(Node *node, bool bShouldBeNegated);
    bool bResolveSentence();
    void vReplaceNodeAt(int iIndex, Node *node);
    Node *nGetNodeAt(int iIndex);
    int iGetVariable(int iIndex);

private:
    int i_variables_count;
    std::vector<FlaggedVariable *> v_flagged_variables;
};

#endif //MINIPROJECT_SENTENCE_H
