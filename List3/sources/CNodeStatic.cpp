//
// Created by Jakub Radzik on 09/11/2021.
//

#include "CNodeStatic.h"

CNodeStatic::CNodeStatic() {
    i_val = 0;
    pc_parent_node = NULL;
}

CNodeStatic::~CNodeStatic() {

}

void CNodeStatic::vSetValue(int iNewVal) {
    i_val = iNewVal;
}

int CNodeStatic::iGetChildrenNumber() {
    return v_children.size();
}

void CNodeStatic::vAddNewChild() {

}

CNodeStatic CNodeStatic::pcGetChild(int iChildOffset) {

}

void CNodeStatic::vPrint() {
    cout << " " << i_val;
}

void CNodeStatic::vPrintAllBelow() {

}
