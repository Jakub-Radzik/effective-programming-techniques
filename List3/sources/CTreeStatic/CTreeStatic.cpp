//
// Created by Jakub Radzik on 16/11/2021.
//

#include "CTreeStatic.h"

CTreeStatic::CTreeStatic() {
    c_root = CNodeStatic();
}

CTreeStatic::~CTreeStatic() {
}

void CTreeStatic::vPrintTree() {
    c_root.vPrintAllBelow();
}




