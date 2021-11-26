//
// Created by Jakub Radzik on 16/11/2021.
//

#ifndef LIST3_CTREEDYNAMIC_H
#define LIST3_CTREEDYNAMIC_H


#include "../CNodeDynamic/CNodeDynamic.h"

class CTreeDynamic {
public:
    CTreeDynamic();

    ~CTreeDynamic();

    CNodeDynamic *pcGetRoot();

    void vPrintTree();

private:
    CNodeDynamic *pc_root;

};

bool bNodesAreInTheSameTree(CNodeDynamic *pc_node_1, CNodeDynamic *pc_node_2);
bool bMoveSubtree(CNodeDynamic *pc_parent_node, CNodeDynamic *pc_new_child_node);

void vDynamicTest1();


#endif //LIST3_CTREEDYNAMIC_H
