//
// Created by Jakub Radzik on 16/11/2021.
//

#include "CTreeStatic.h"

CTreeStatic::CTreeStatic() {
//    std::cout << "Create static: " << std::endl;
    c_root = CNodeStatic();
}

CTreeStatic::~CTreeStatic() {
//    std::cout << "Delete static: " << std::endl;
}

void CTreeStatic::vPrintTree() {
    c_root.vPrintAllBelow();
}
//TODO: repair that
bool bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode) {
    if (!pcParentNode || !pcNewChildNode) {
        return false;
    }

    //Old parent lost child
    pcNewChildNode->getPcParentNode()->removeChild(pcNewChildNode);

    //New parent get new child
    pcParentNode->vAddNewChild();
    pcParentNode->pcGetChild(pcParentNode->iGetChildrenNumber() - 1)->vSetValue(pcNewChildNode->getIVal());

    //Child get new parent
    pcNewChildNode->setPcParentNode(pcParentNode);

    if (pcNewChildNode->iGetChildrenNumber() > 0) {
        for (int i = 0; i < pcNewChildNode->iGetChildrenNumber(); i++) {
            bMoveSubtree(pcParentNode->pcGetChild(pcParentNode->iGetChildrenNumber() - 1),
                         pcNewChildNode->pcGetChild(i));
        }
    }


    return true;
}

//IDK
void c_copy_tree_recursive(CNodeStatic *c_destination, CNodeStatic *c_source) {


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

