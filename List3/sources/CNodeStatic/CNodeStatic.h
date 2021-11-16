//
// Created by Jakub Radzik on 09/11/2021.
//

#ifndef LIST3_CNODESTATIC_H
#define LIST3_CNODESTATIC_H

#include <iostream>
#include <vector>

class CNodeStatic {
public:
    CNodeStatic() {
        i_val = 0;
        pc_parent_node = nullptr;
    }

    ~CNodeStatic();

    void vSetValue(int iNewVal);

    int iGetChildrenNumber();

    void vAddNewChild();

    CNodeStatic *pcGetChild(int i_child_offset);

    void vPrint() {std::cout << " " << i_val;};
    void vPrintAllBelow();
    void vPrintUp();

private:
    std::vector<CNodeStatic> v_children;
    CNodeStatic *pc_parent_node;
    int i_val;
};

void v_tree_test();

//class CNodeStatic


#endif //LIST3_CNODESTATIC_H
