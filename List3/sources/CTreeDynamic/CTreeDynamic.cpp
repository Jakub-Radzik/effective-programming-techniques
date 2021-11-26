//
// Created by Jakub Radzik on 16/11/2021.
//

#include <iostream>
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


bool bMoveSubtree(CNodeDynamic *pc_parent_node, CNodeDynamic *pc_new_child_node) {
    if (!pc_parent_node || !pc_new_child_node || bNodesAreInTheSameTree(pc_parent_node, pc_new_child_node)) {
        return false;
    }

    pc_parent_node->vAddNewChild(pc_new_child_node);
    if (pc_new_child_node->getPcParentNode()) {
        pc_new_child_node->getPcParentNode()->removeChild(pc_new_child_node);
    }
    pc_new_child_node->setPcParentNode(pc_parent_node);

    return true;
}

bool bNodesAreInTheSameTree(CNodeDynamic *pc_node_1, CNodeDynamic *pc_node_2) {
    if (!pc_node_1 || !pc_node_2) {
        return false;
    }

    CNodeDynamic *pc_node_1_parent;
    CNodeDynamic *pc_node_2_parent;

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

void vDynamicTest1() {
    std::cout << "Dynamic Tree Test" << std::endl;
    CTreeDynamic *c_tree_1;
    c_tree_1 = new CTreeDynamic();

    CTreeDynamic *c_tree_2;
    c_tree_2 = new CTreeDynamic();

    c_tree_1->pcGetRoot()->vSetValue(1);
    c_tree_2->pcGetRoot()->vSetValue(2);

    c_tree_1->pcGetRoot()->vAddNewChild();
    c_tree_1->pcGetRoot()->vAddNewChild();
    c_tree_1->pcGetRoot()->pcGetChild(0)->vSetValue(3);
    c_tree_1->pcGetRoot()->pcGetChild(1)->vSetValue(4);

    c_tree_2->pcGetRoot()->vAddNewChild();
    c_tree_2->pcGetRoot()->vAddNewChild();
    c_tree_2->pcGetRoot()->pcGetChild(0)->vSetValue(5);
    c_tree_2->pcGetRoot()->pcGetChild(1)->vSetValue(6);

    c_tree_2->pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree_2->pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(7);
    c_tree_2->pcGetRoot()->pcGetChild(1)->pcGetChild(0)->setPcParentNode(c_tree_2->pcGetRoot()->pcGetChild(1));


    std::cout << "c_tree_1 before move:" << std::endl;
    c_tree_1->vPrintTree();
    std::cout << std::endl << "c_tree_2 before move:" << std::endl;
    c_tree_2->vPrintTree();

    bMoveSubtree(c_tree_1->pcGetRoot()->pcGetChild(1), c_tree_2->pcGetRoot()->pcGetChild(1));

    std::cout << std::endl << "c_tree_1 after move:" << std::endl;
    c_tree_1->vPrintTree();
    std::cout << std::endl << "c_tree_2 after move:" << std::endl;
    c_tree_2->vPrintTree();
    std::cout << std::endl;


    delete c_tree_1;
    delete c_tree_2;
}