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

void CTreeDynamic::vPruneVal(int i_val) {
    if (pc_root->getIVal() != i_val) {
        for (int i = 0; i < pc_root->iGetChildrenNumber(); ++i) {
            vPrune(pc_root->getChild(i), i_val);
        }
    }
}

void CTreeDynamic::vPrune(CNodeDynamic *pc_node, int i_val) {
    for (int i = 0; i < pc_node->iGetChildrenNumber(); i++) {
        vPrune(pc_node->getChild(i), i_val);
    }

    if(pc_node->getIVal() == i_val) {
        for (int i = 0; i < pc_node->iGetChildrenNumber(); i++) {
            pc_node->getPcParentNode()->vAddNewChild(pc_node->getChild(i));
        }
        pc_node->getPcParentNode()->removeChild(pc_node);
        delete pc_node;
    }
}


bool bMoveSubtree(CNodeDynamic *pc_parent_node, CNodeDynamic *pc_new_child_node) {
    if (!pc_parent_node || !pc_new_child_node) {
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

    bMoveSubtree(c_tree_1->pcGetRoot(), c_tree_2->pcGetRoot()->pcGetChild(1));

    std::cout << std::endl << "c_tree_1 after move:" << std::endl;
    c_tree_1->vPrintTree();
    std::cout << std::endl << "c_tree_2 after move:" << std::endl;
    c_tree_2->vPrintTree();
    std::cout << std::endl;


    delete c_tree_1;
    delete c_tree_2;
}

void vDynamicPruneTest() {
    CTreeDynamic *c_tree_1;
    c_tree_1 = new CTreeDynamic();

    c_tree_1->pcGetRoot()->vSetValue(1);
    c_tree_1->pcGetRoot()->vAddNewChild(); // 1 - 2
    c_tree_1->pcGetRoot()->vAddNewChild(); // 1 - 3

    c_tree_1->pcGetRoot()->pcGetChild(0)->vSetValue(2); // 1 - 2
    c_tree_1->pcGetRoot()->pcGetChild(1)->vSetValue(3); // 1 - 3

    c_tree_1->pcGetRoot()->pcGetChild(0)->vAddNewChild(); // 1 - 2 - 48
    c_tree_1->pcGetRoot()->pcGetChild(0)->vAddNewChild(); // 1 - 2 - 3

    c_tree_1->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(48); // 1 - 2 - 48
    c_tree_1->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(3); // 1 - 2 - 3

    c_tree_1->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vAddNewChild(); // 1 - 2 - 3 - 5
    c_tree_1->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->pcGetChild(0)->vSetValue(5);

    c_tree_1->pcGetRoot()->getChild(1)->vAddNewChild(); // 1 - 3 - 6
    c_tree_1->pcGetRoot()->getChild(1)->vAddNewChild(); // 1 - 3 - 7

    c_tree_1->pcGetRoot()->getChild(1)->pcGetChild(0)->vSetValue(6);
    c_tree_1->pcGetRoot()->getChild(1)->pcGetChild(1)->vSetValue(7);

    c_tree_1->vPrintTree();
    std::cout << std::endl;
    c_tree_1->vPruneVal(3);
    std::cout << std::endl;
    c_tree_1->vPrintTree();

    delete c_tree_1;
}


