//
// Created by Jakub Radzik on 16/11/2021.
//

#include "CTreeStatic.h"

CTreeStatic::CTreeStatic() {
    c_root = CNodeStatic();
}

CTreeStatic::~CTreeStatic() {
}

CNodeStatic *CTreeStatic::pcGetRoot() { return (&c_root); }

void CTreeStatic::vPrintTree() {
    c_root.vPrintAllBelow();
}

bool bMoveSubtree(CNodeStatic *pc_parent_node, CNodeStatic *pc_new_child_node) {
    if (!pc_parent_node || !pc_new_child_node) {
        return false;
    }

    vCopyTreeRecursive(pc_parent_node, pc_new_child_node);

    //Old parent lost child
    if (pc_new_child_node->getPcParentNode()) {
        //Node is not a root
        pc_new_child_node->getPcParentNode()->removeChild(pc_new_child_node);
    } else {
        //Node is tree root
        pc_new_child_node->removeAllChildren();
    }

    return true;
}

void vCopyTreeRecursive(CNodeStatic *c_destination, CNodeStatic *c_source) {
    //New parent get new child
    c_destination->vAddNewChild();
    c_destination->pcGetChild(c_destination->iGetChildrenNumber() - 1)->vSetValue(c_source->getIVal());

    if (c_source->iGetChildrenNumber() > 0) {
        for (int i = 0; i < c_source->iGetChildrenNumber(); i++) {
            vCopyTreeRecursive(c_destination->pcGetChild(c_destination->iGetChildrenNumber() - 1),
                               c_source->pcGetChild(i));
        }
    }
}


void vStaticTest1() {
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

