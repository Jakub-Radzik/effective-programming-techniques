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
    if (!pc_parent_node || !pc_new_child_node || bNodesAreInTheSameTree(pc_parent_node, pc_new_child_node)) {
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

void vCopyTreeRecursive(CNodeStatic *pc_destination, CNodeStatic *pc_source) {
    //New parent get new child
    pc_destination->vAddNewChild();
    pc_destination->pcGetChild(pc_destination->iGetChildrenNumber() - 1)->vSetValue(pc_source->getIVal());

    if (pc_source->iGetChildrenNumber() > 0) {
        for (int i = 0; i < pc_source->iGetChildrenNumber(); i++) {
            vCopyTreeRecursive(pc_destination->pcGetChild(pc_destination->iGetChildrenNumber() - 1),
                               pc_source->pcGetChild(i));
        }
    }
}


bool bNodesAreInTheSameTree(CNodeStatic *pc_node_1, CNodeStatic *pc_node_2) {
    if (!pc_node_1 || !pc_node_2) {
        return false;
    }

    CNodeStatic *pc_node_1_parent;
    CNodeStatic *pc_node_2_parent;

    if (pc_node_1->getPcParentNode()) {
        pc_node_1_parent = pc_node_1->getPcParentNode();
    } else {
        pc_node_1_parent = pc_node_1;
    }

    if (pc_node_2->getPcParentNode()) {
        pc_node_2_parent = pc_node_2->getPcParentNode();
    } else {
        pc_node_2_parent = pc_node_2;
    }

    while (pc_node_1_parent) {
        pc_node_1_parent = pc_node_1_parent->getPcParentNode();
    }

    while (pc_node_2_parent) {
        pc_node_2_parent = pc_node_2_parent->getPcParentNode();
    }

    return pc_node_1_parent == pc_node_2_parent;
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
    bMoveSubtree(c_tree_1.pcGetRoot(), c_tree_1.pcGetRoot()->pcGetChild(0));

    std::cout << "c_tree_1 after move: " << std::endl;
    c_tree_1.vPrintTree();
    std::cout << std::endl << "c_tree_2 after move: " << std::endl;
    c_tree_2.vPrintTree();


}

