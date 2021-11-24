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

bool bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode) {
    if (!pcParentNode || !pcNewChildNode) {
        return false;
    }

    c_copy_tree_recursive(pcParentNode, pcNewChildNode);

    //Old parent lost child
    if (pcNewChildNode->getPcParentNode()) {
        //Node is not a root
        pcNewChildNode->getPcParentNode()->removeChild(pcNewChildNode);
    } else {
        //Node is tree root
        pcNewChildNode->removeAllChildren();
    }

    return true;
}

void c_copy_tree_recursive(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode) {
    //New parent get new child
    pcParentNode->vAddNewChild();
    pcParentNode->pcGetChild(pcParentNode->iGetChildrenNumber() - 1)->vSetValue(pcNewChildNode->getIVal());

    if (pcNewChildNode->iGetChildrenNumber() > 0) {
        for (int i = 0; i < pcNewChildNode->iGetChildrenNumber(); i++) {
            c_copy_tree_recursive(pcParentNode->pcGetChild(pcParentNode->iGetChildrenNumber() - 1),
                                  pcNewChildNode->pcGetChild(i));
        }
    }
}


void v_static_test_1() {
    CTreeStatic c_tree_1;
    CTreeStatic c_tree_2;

    c_tree_1.pcGetRoot()->vSetValue(1);
    c_tree_2.pcGetRoot()->vSetValue(10);

    c_tree_1.pcGetRoot()->vAddNewChild();
    c_tree_1.pcGetRoot()->vAddNewChild();
    c_tree_1.pcGetRoot()->vAddNewChild();
    c_tree_1.pcGetRoot()->pcGetChild(0)->vSetValue(2);
    c_tree_1.pcGetRoot()->pcGetChild(1)->vSetValue(3);
    c_tree_1.pcGetRoot()->pcGetChild(2)->vSetValue(4);

    c_tree_2.pcGetRoot()->vAddNewChild();
    c_tree_2.pcGetRoot()->pcGetChild(0)->vSetValue(20);

    c_tree_1.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_1.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_1.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(5);
    c_tree_1.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(6);

    std::cout << "c_tree_1 before move: " << std::endl;
    c_tree_1.vPrintTree();
    std::cout << std::endl << "c_tree_2 before move: " << std::endl;
    c_tree_2.vPrintTree();
    std::cout << std::endl;
    bMoveSubtree(c_tree_2.pcGetRoot(), c_tree_1.pcGetRoot()->pcGetChild(0));

    std::cout << "c_tree_1 after move: " << std::endl;
    c_tree_1.vPrintTree();
    std::cout << std::endl << "c_tree_2 after move: " << std::endl;
    c_tree_2.vPrintTree();


}

