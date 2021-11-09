//
// Created by Jakub Radzik on 09/11/2021.
//

#include <iostream>
#include "CNodeStatic.h"


CNodeStatic::~CNodeStatic() {}

void CNodeStatic::vSetValue(int iNewVal) {
    i_val = iNewVal;
}

int CNodeStatic::iGetChildrenNumber() {
    return v_children.size();
}

void CNodeStatic::vAddNewChild() {
    CNodeStatic toAdd = CNodeStatic();
    toAdd.pc_parent_node = this;
    v_children.push_back(toAdd);
}

CNodeStatic *CNodeStatic::pcGetChild(int iChildOffset) {
    if ((iChildOffset < 0) || (iChildOffset >= v_children.size())) {
        return nullptr;
    }

    return &v_children[iChildOffset];
}

void CNodeStatic::vPrintAllBelow() {
    std::cout << " " << i_val;

    for (int i = 0; i < v_children.size(); i++)
        this->pcGetChild(i)->vPrintAllBelow();

}

void CNodeStatic::vPrintUp() {
    std::cout << " " << i_val;

    if (pc_parent_node != nullptr)
        pc_parent_node->vPrintUp();
}


