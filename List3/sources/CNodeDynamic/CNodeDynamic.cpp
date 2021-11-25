//
// Created by Jakub Radzik on 16/11/2021.
//

#include <iostream>
#include "CNodeDynamic.h"

CNodeDynamic::CNodeDynamic() {
    i_val = 0;
    pc_parent_node = nullptr;
}

CNodeDynamic::~CNodeDynamic() {
    if (iGetChildrenNumber() == 0) {
        return;
    } else {
        for (int i = 0; i < iGetChildrenNumber(); i++) {
            delete v_children[i];
        }
    }
}

void CNodeDynamic::vSetValue(int i_new_val) {
    i_val = i_new_val;
}

int CNodeDynamic::iGetChildrenNumber() { return v_children.size(); }

void CNodeDynamic::vAddNewChild() {
    CNodeDynamic *newNode;
    newNode = new CNodeDynamic();
    newNode->setPcParentNode(this);
    v_children.push_back(newNode);
    newNode = nullptr;
}

void CNodeDynamic::vAddNewChild(CNodeDynamic *c_node_to_append) {
    v_children.push_back(c_node_to_append);
}

CNodeDynamic *CNodeDynamic::pcGetChild(int i_child_offset) {
    if (i_child_offset >= iGetChildrenNumber() || i_child_offset < 0)
        return nullptr;
    return v_children[i_child_offset];
}

void CNodeDynamic::vPrint() { std::cout << " " << i_val; }

void CNodeDynamic::vPrintAllBelow() {
    vPrint();

    for (int i = 0; i < iGetChildrenNumber(); i++) {
        v_children[i]->vPrintAllBelow();
    }
}

CNodeDynamic *CNodeDynamic::getPcParentNode() {
    return pc_parent_node;
}

void CNodeDynamic::setPcParentNode(CNodeDynamic *pc_new_parent_node) {
    pc_parent_node = pc_new_parent_node;
}

void CNodeDynamic::removeChild(CNodeDynamic *pc_child_to_remove) {
    for (int i = 0; i < iGetChildrenNumber(); i++) {
        if ((*v_children[i]).i_val == pc_child_to_remove->i_val) {
            v_children.erase(v_children.begin() + i);
        }
    }
}