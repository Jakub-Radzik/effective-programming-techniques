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
    std::cout << "deleted node: " << this->i_val << std::endl;
    if (iGetChildrenNumber() == 0) {
        return;
    } else {
        for (int i = 0; i < iGetChildrenNumber(); i++) {
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
    newNode->setPcParentNode(this);
    v_children.push_back(newNode);
    newNode = nullptr;
}

void CNodeDynamic::vAddNewChild(CNodeDynamic *c_node_to_append) {
    v_children.push_back(c_node_to_append);
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

CNodeDynamic *CNodeDynamic::getPcParentNode() {
    return pc_parent_node;
}

void CNodeDynamic::setPcParentNode(CNodeDynamic *pcParentNode) {
    pc_parent_node = pcParentNode;
}

void CNodeDynamic::removeChild(CNodeDynamic *oldChild) {
    for (int i = 0; i < iGetChildrenNumber(); i++) {
        if ((*v_children[i]).i_val == oldChild->i_val) {
            v_children.erase(v_children.begin() + i);
        }
    }
}

int CNodeDynamic::getIVal() const {
    return i_val;
}


