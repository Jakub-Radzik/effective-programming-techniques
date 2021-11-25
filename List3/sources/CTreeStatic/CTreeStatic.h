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

    CNodeStatic *pcGetRoot();

    void vPrintTree();

private:
    CNodeStatic c_root;
};

bool bMoveSubtree(CNodeStatic *pc_parent_node, CNodeStatic *pc_new_child_node);
void vCopyTreeRecursive(CNodeStatic *c_destination, CNodeStatic *c_source);
void vStaticTest1();


#endif //LIST3_CTREESTATIC_H
