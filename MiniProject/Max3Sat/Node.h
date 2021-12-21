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

    const int &getIVariable() const;

    void setIVariable(const int &iVariable);

    bool isBValue() const;

    void setBValue(bool bValue);

    void incrementRefCount();
    void decrementRefCount();
    int getIRefCount() const;

private:
    int i_variable;
    int i_ref_count;
    bool b_value;
};


#endif //MINIPROJECT_NODE_H
