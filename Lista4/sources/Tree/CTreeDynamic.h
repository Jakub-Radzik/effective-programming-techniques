//
// Created by Jakub Radzik on 29/11/2021.
//

#ifndef LISTA4_CTREEDYNAMIC_H
#define LISTA4_CTREEDYNAMIC_H


#include "../Node/CNodeDynamic.h"

class CTreeDynamic {
public:
    CTreeDynamic();

    ~CTreeDynamic();

    CNodeDynamic *pcGetRoot();

    void vPruneVal(int i_val);

    void vPrintTree();

private:
    CNodeDynamic *pc_root;
    void vPrune(CNodeDynamic *pc_node, int i_val);

};

bool bNodesAreInTheSameTree(CNodeDynamic *pc_node_1, CNodeDynamic *pc_node_2);
bool bMoveSubtree(CNodeDynamic *pc_parent_node, CNodeDynamic *pc_new_child_node);

void vDynamicTest1();
void vDynamicPruneTest();


#endif //LISTA4_CTREEDYNAMIC_H
