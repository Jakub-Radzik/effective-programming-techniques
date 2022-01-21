//
// Created by Jakub Radzik on 20/12/2021.
//

#ifndef MINIPROJECT_NODE_H
#define MINIPROJECT_NODE_H

#include <string>

class Node {
public:
    Node(int iVariable, bool bValue);
    ~Node();

    const int &iGetVariable() const;

    void vSetVariable(const int &iVariable);

    bool bGetValue() const;

    void vSetValue(bool bValue);

    void vIncrementRefCount();
    void vDecrementRefCount();
    int iGetRefCount() const;

private:
    int i_variable;
    int i_ref_count;
    bool b_value;
};


#endif //MINIPROJECT_NODE_H
