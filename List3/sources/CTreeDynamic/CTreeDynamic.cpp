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
//    std::cout << "DELETE TREE" << std::endl;
    delete pc_root;
}

void CTreeDynamic::vPrintTree() {
    pc_root->vPrintAllBelow();
}

CNodeDynamic *CTreeDynamic::pcGetRoot() { return pc_root; }


bool bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode) {
    if (!pcParentNode || !pcNewChildNode) {
        return false;
    }

    pcParentNode->vAddNewChild(pcNewChildNode);
    if (pcNewChildNode->getPcParentNode()) {
        pcNewChildNode->getPcParentNode()->removeChild(pcNewChildNode);
    }
    pcNewChildNode->setPcParentNode(pcParentNode);

    return true;
}

void v_dynamic_test_1() {
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

void v_test_dynamic_tree() {
    //Create trees
    CTreeDynamic *c_tree_1;
    CTreeDynamic *c_tree_2;

    c_tree_1 = new CTreeDynamic();
    c_tree_2 = new CTreeDynamic();

    //Set values to roots
    c_tree_1->pcGetRoot()->vSetValue(1);
    c_tree_2->pcGetRoot()->vSetValue(2);

    //Add two childs for roots
    c_tree_1->pcGetRoot()->vAddNewChild();
    c_tree_1->pcGetRoot()->vAddNewChild();
    c_tree_2->pcGetRoot()->vAddNewChild();
    c_tree_2->pcGetRoot()->vAddNewChild();

    //Set values to root children
    c_tree_1->pcGetRoot()->pcGetChild(0)->vSetValue(3);
    c_tree_1->pcGetRoot()->pcGetChild(1)->vSetValue(5);
    c_tree_2->pcGetRoot()->pcGetChild(0)->vSetValue(4);
    c_tree_2->pcGetRoot()->pcGetChild(1)->vSetValue(6);


    //Set parent for children
    c_tree_1->pcGetRoot()->pcGetChild(0)->setPcParentNode(c_tree_1->pcGetRoot());
    c_tree_1->pcGetRoot()->pcGetChild(1)->setPcParentNode(c_tree_1->pcGetRoot());
    c_tree_2->pcGetRoot()->pcGetChild(0)->setPcParentNode(c_tree_2->pcGetRoot());
    c_tree_2->pcGetRoot()->pcGetChild(1)->setPcParentNode(c_tree_2->pcGetRoot());

    //Add level 2 in c_tree_2
    c_tree_2->pcGetRoot()->pcGetChild(1)->vAddNewChild();

    //Create node to move
    CNodeDynamic *c_node_to_move = c_tree_2->pcGetRoot()->pcGetChild(1)->pcGetChild(0);
    c_node_to_move->vSetValue(8);
    c_node_to_move->setPcParentNode(c_tree_2->pcGetRoot()->pcGetChild(1));

    c_node_to_move->vAddNewChild();
    c_node_to_move->vAddNewChild();
    c_node_to_move->pcGetChild(0)->vSetValue(20);
    c_node_to_move->pcGetChild(1)->vSetValue(40);
    c_node_to_move->pcGetChild(0)->setPcParentNode(c_node_to_move);
    c_node_to_move->pcGetChild(1)->setPcParentNode(c_node_to_move);

    std::cout << "c_tree_1 before move:" << std::endl;
    c_tree_1->vPrintTree();
    std::cout << std::endl;
    std::cout << "c_tree_2 before move:" << std::endl;
    c_tree_2->vPrintTree();
    std::cout << std::endl;

    bMoveSubtree(c_tree_1->pcGetRoot()->pcGetChild(1), c_node_to_move);

    std::cout << "c_tree_1 after move:" << std::endl;
    c_tree_1->vPrintTree();
    std::cout << std::endl;
    std::cout << "c_tree_2 after move:" << std::endl;
    c_tree_2->vPrintTree();
    std::cout << std::endl;

}
