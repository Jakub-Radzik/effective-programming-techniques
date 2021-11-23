//
// Created by Jakub Radzik on 16/11/2021.
//

#ifndef LIST3_CTREESTATIC_H
#define LIST3_CTREESTATIC_H


#include "../CNodeStatic/CNodeStatic.h"

class CTreeStatic {
public:
    CTreeStatic();

    ~CTreeStatic();

    CNodeStatic *pcGetRoot() { return (&c_root); }

    void vPrintTree();

private:
    CNodeStatic c_root;
};

bool bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode);
void c_copy_tree_recursive(CNodeStatic *c_destination, CNodeStatic *c_source);
void v_static_test_1();


#endif //LIST3_CTREESTATIC_H
