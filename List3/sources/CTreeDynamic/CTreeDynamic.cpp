//
// Created by Jakub Radzik on 16/11/2021.
//

#include "CTreeDynamic.h"


CTreeDynamic::CTreeDynamic() {
    CNodeDynamic *root = new CNodeDynamic();
    pc_root = root;
}

CTreeDynamic::~CTreeDynamic() {
    delete pc_root;
}

void CTreeDynamic::vPrintTree() {
    pc_root->vPrintAllBelow();
}

CNodeDynamic *CTreeDynamic::pcGetRoot() { return pc_root; }
