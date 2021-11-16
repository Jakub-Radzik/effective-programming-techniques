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
            v_children[i]->~CNodeDynamic();
            delete v_children[i];
        }
    }
}

void CNodeDynamic::vSetValue(int iNewVal) {
    i_val = iNewVal;
}

int CNodeDynamic::iGetChildrenNumber() { return v_children.size(); }

void CNodeDynamic::vAddNewChild() {
    CNodeDynamic *newNode;
    newNode = new CNodeDynamic();
    v_children.push_back(newNode);
}

CNodeDynamic *CNodeDynamic::pcGetChild(int iChildOffset) {
    if (iChildOffset >= iGetChildrenNumber() || iChildOffset < 0)
        return nullptr;
    return v_children[iChildOffset];
}

void CNodeDynamic::vPrint() { std::cout << " " << i_val; }

void CNodeDynamic::vPrintAllBelow() {
    vPrint();

    for (int i = 0; i < iGetChildrenNumber(); i++) {
        v_children[i]->vPrintAllBelow();
    }
}

