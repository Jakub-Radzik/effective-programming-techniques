//
// Created by Jakub Radzik on 09/11/2021.
//

#include <iostream>
#include "CNodeStatic.h"


CNodeStatic::~CNodeStatic() {
//    std::cout << "deleted node: " << i_val << std::endl;
}

void CNodeStatic::vSetValue(int iNewVal) {
    i_val = iNewVal;
}

int CNodeStatic::iGetChildrenNumber() {
    return v_children.size();
}

void CNodeStatic::vAddNewChild() {
    CNodeStatic c_node_to_add = CNodeStatic();
    c_node_to_add.pc_parent_node = this;
    v_children.push_back(c_node_to_add);
}

CNodeStatic *CNodeStatic::pcGetChild(int i_child_offset) {
    if ((i_child_offset < 0) || (i_child_offset >= v_children.size())) {
        return nullptr;
    }

    return &v_children[i_child_offset];
}

void CNodeStatic::vPrintAllBelow() {
    vPrint();

    for (int i = 0; i < v_children.size(); i++)
        this->pcGetChild(i)->vPrintAllBelow();

}

void CNodeStatic::vPrintUp() {
    vPrint();

    if (pc_parent_node != nullptr)
        pc_parent_node->vPrintUp();
}

void v_tree_test() {
    CNodeStatic c_root;
    c_root.vAddNewChild();
    c_root.vAddNewChild();
    c_root.pcGetChild(0)->vSetValue(1);
    c_root.pcGetChild(1)->vSetValue(2);
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->vAddNewChild();
    c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->vAddNewChild();
    c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    c_root.vPrintAllBelow();
    std::cout<<std::endl;
    c_root.pcGetChild(0)->pcGetChild(1)->vPrintUp();

}


