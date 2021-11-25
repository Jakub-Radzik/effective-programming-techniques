//
// Created by Jakub Radzik on 09/11/2021.
//

#include <iostream>
#include "CNodeStatic.h"

CNodeStatic::CNodeStatic() {
    i_val = 0;
    pc_parent_node = nullptr;
}


CNodeStatic::~CNodeStatic() {
}

void CNodeStatic::vSetValue(int i_new_val) {
    i_val = i_new_val;
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

void CNodeStatic::vPrint() { std::cout << " " << i_val; };

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


CNodeStatic *CNodeStatic::getPcParentNode() const {
    return pc_parent_node;
}

void CNodeStatic::setPcParentNode(CNodeStatic *pc_new_parent_node) {
    pc_parent_node = pc_new_parent_node;
}

int CNodeStatic::getIVal() const {
    return i_val;
}

void CNodeStatic::removeChild(CNodeStatic *pc_child_to_remove) {
    for (int i = 0; i < iGetChildrenNumber(); i++) {
        if (&v_children[i] == pc_child_to_remove) {
            v_children.erase(v_children.begin() + i);
        }
    }
}

void CNodeStatic::removeAllChildren() {
    v_children.clear();
}

void vTreeTest() {
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
    std::cout << std::endl;
    c_root.pcGetChild(0)->pcGetChild(1)->vPrintUp();
}


