//
// Created by Jakub Radzik on 29/11/2021.
//

#ifndef LISTA4_CTREEDYNAMIC_H
#define LISTA4_CTREEDYNAMIC_H


#include "CNodeDynamic.h"

template<typename T>
class CTreeDynamic {
public:
    CTreeDynamic();

    ~CTreeDynamic();

    CNodeDynamic<T> *pcGetRoot();

    void vPrintTree();

private:
    CNodeDynamic<T> *pc_root;
};

template<typename T>
bool bNodesAreInTheSameTree(CNodeDynamic<T> *pc_node_1, CNodeDynamic<T> *pc_node_2);

template<typename T>
bool bMoveSubtree(CNodeDynamic<T> *pc_parent_node, CNodeDynamic<T> *pc_new_child_node);

// ---------------------------------------------------------------------------------------------------------------------

template<typename T>
CTreeDynamic<T>::CTreeDynamic() {
    CNodeDynamic<T> *root;
    root = new CNodeDynamic<T>();
    pc_root = root;
}

template<typename T>
CTreeDynamic<T>::~CTreeDynamic() {
    delete pc_root;
}

template<typename T>
CNodeDynamic<T> *CTreeDynamic<T>::pcGetRoot() { return pc_root; }

template<typename T>
void CTreeDynamic<T>::vPrintTree() {
    pc_root->vPrintAllBelow();
}

template<typename T>
bool bMoveSubtree(CNodeDynamic<T> *pc_parent_node, CNodeDynamic<T> *pc_new_child_node) {
    if (!pc_parent_node || !pc_new_child_node || bNodesAreInTheSameTree(pc_new_child_node, pc_parent_node)) {
        return false;
    }

    if (pc_new_child_node->getPcParentNode()) {
        pc_new_child_node->getPcParentNode()->removeChild(pc_new_child_node);
    }

    pc_parent_node->vAddNewChild(pc_new_child_node);

    return true;
}

template<typename T>
bool bNodesAreInTheSameTree(CNodeDynamic<T> *pc_node_1, CNodeDynamic<T> *pc_node_2) {
    if (!pc_node_1 || !pc_node_2) {
        return false;
    }

    CNodeDynamic<T> *pc_node_1_parent;
    CNodeDynamic<T> *pc_node_2_parent;

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

    while (pc_node_1_parent->getPcParentNode()) {
        pc_node_1_parent = pc_node_1_parent->getPcParentNode();
    }

    while (pc_node_2_parent->getPcParentNode()) {
        pc_node_2_parent = pc_node_2_parent->getPcParentNode();
    }

    return pc_node_1_parent == pc_node_2_parent;
}

// Tests

void vIntDynamicTest1() {
    std::cout << "Dynamic Tree Test" << std::endl;
    CTreeDynamic<int> *c_tree_1;
    c_tree_1 = new CTreeDynamic<int>();

    CTreeDynamic<int> *c_tree_2;
    c_tree_2 = new CTreeDynamic<int>();

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

    bMoveSubtree(c_tree_1->pcGetRoot(), c_tree_2->pcGetRoot()->pcGetChild(0));

    std::cout << std::endl << "c_tree_1 after move:" << std::endl;
    c_tree_1->vPrintTree();
    std::cout << std::endl << "c_tree_2 after move:" << std::endl;
    c_tree_2->vPrintTree();
    std::cout << std::endl;


    delete c_tree_1;
    delete c_tree_2;
}
void vStringDynamicTest1() {
    std::cout << "Dynamic Tree Test" << std::endl;
    CTreeDynamic<std::string> *c_tree_1;
    c_tree_1 = new CTreeDynamic<std::string>();

    CTreeDynamic<std::string> *c_tree_2;
    c_tree_2 = new CTreeDynamic<std::string>();

    c_tree_1->pcGetRoot()->vSetValue("c_tree_1_root");
    c_tree_2->pcGetRoot()->vSetValue("c_tree_2_root");

    c_tree_1->pcGetRoot()->vAddNewChild();
    c_tree_1->pcGetRoot()->vAddNewChild();
    c_tree_1->pcGetRoot()->pcGetChild(0)->vSetValue("c_tree_1_child_1");
    c_tree_1->pcGetRoot()->pcGetChild(1)->vSetValue("c_tree_1_child_2");

    c_tree_2->pcGetRoot()->vAddNewChild();
    c_tree_2->pcGetRoot()->vAddNewChild();
    c_tree_2->pcGetRoot()->pcGetChild(0)->vSetValue("c_tree_2_child_1");
    c_tree_2->pcGetRoot()->pcGetChild(1)->vSetValue("c_tree_2_child_2");

    c_tree_2->pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree_2->pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue("c_tree_2_child_1_child_0");

    std::cout << "c_tree_1 before move:" << std::endl;
    c_tree_1->vPrintTree();
    std::cout << std::endl << "c_tree_2 before move:" << std::endl;
    c_tree_2->vPrintTree();

    bMoveSubtree(c_tree_1->pcGetRoot(), c_tree_2->pcGetRoot()->pcGetChild(0));

    std::cout << std::endl << "c_tree_1 after move:" << std::endl;
    c_tree_1->vPrintTree();
    std::cout << std::endl << "c_tree_2 after move:" << std::endl;
    c_tree_2->vPrintTree();
    std::cout << std::endl;


    delete c_tree_1;
    delete c_tree_2;
}
void vDoublePointerDynamicTest1() {
    std::cout << "Dynamic Tree Test" << std::endl;
    CTreeDynamic<double*> *c_tree_1;
    c_tree_1 = new CTreeDynamic<double*>();

    CTreeDynamic<double*> *c_tree_2;
    c_tree_2 = new CTreeDynamic<double*>();

    double d_root_1 = 10;
    double d_root_2 = 20;
    c_tree_1->pcGetRoot()->vSetValue(&d_root_1);
    c_tree_2->pcGetRoot()->vSetValue(&d_root_2);

    c_tree_1->pcGetRoot()->vAddNewChild();
    c_tree_1->pcGetRoot()->vAddNewChild();

    double d_tree_1_child_0 = 11;
    double d_child_1 = 22;
    c_tree_1->pcGetRoot()->pcGetChild(0)->vSetValue(&d_tree_1_child_0);
    c_tree_1->pcGetRoot()->pcGetChild(1)->vSetValue(&d_child_1);

    c_tree_2->pcGetRoot()->vAddNewChild();
    c_tree_2->pcGetRoot()->vAddNewChild();

    double d_tree_2_child_0 = 11;
    double d_tree_2_child_1 = 22;
    c_tree_2->pcGetRoot()->pcGetChild(0)->vSetValue(&d_tree_2_child_0);
    c_tree_2->pcGetRoot()->pcGetChild(1)->vSetValue(&d_tree_2_child_1);

    c_tree_2->pcGetRoot()->pcGetChild(1)->vAddNewChild();
    double d_tree_2_child_1_child_0 = 23;
    c_tree_2->pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(&d_tree_2_child_1_child_0);


    std::cout << "c_tree_1 before move:" << std::endl;
    c_tree_1->vPrintTree();
    std::cout << std::endl << "c_tree_2 before move:" << std::endl;
    c_tree_2->vPrintTree();

    bMoveSubtree(c_tree_1->pcGetRoot(), c_tree_2->pcGetRoot()->pcGetChild(0));

    std::cout << std::endl << "c_tree_1 after move:" << std::endl;
    c_tree_1->vPrintTree();
    std::cout << std::endl << "c_tree_2 after move:" << std::endl;
    c_tree_2->vPrintTree();
    std::cout << std::endl;


    delete c_tree_1;
    delete c_tree_2;
}
void vIntAddChildTest(){
    CTreeDynamic<int> *c_tree_1;
    c_tree_1 = new CTreeDynamic<int>();

    c_tree_1->pcGetRoot()->vSetValue(5);
    c_tree_1->pcGetRoot()->vAddNewChild();
    c_tree_1->pcGetRoot()->vAddNewChild();
    c_tree_1->pcGetRoot()->vAddNewChild();
    c_tree_1->pcGetRoot()->vAddNewChild();
    c_tree_1->pcGetRoot()->vAddNewChild();
    c_tree_1->pcGetRoot()->vAddNewChild();
    c_tree_1->vPrintTree();
}

#endif //LISTA4_CTREEDYNAMIC_H
