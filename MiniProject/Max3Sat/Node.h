//
// Created by Jakub Radzik on 20/12/2021.
//

#ifndef MINIPROJECT_NODE_H
#define MINIPROJECT_NODE_H

#include <string>

class Node {
public:
    Node(std::string iVariable, bool bValue);
    ~Node();

    const std::string &getIVariable() const;

    void setIVariable(const std::string &iVariable);

    bool isBValue() const;

    void setBValue(bool bValue);

private:
    std::string i_variable;
    bool b_value;
};


#endif //MINIPROJECT_NODE_H
