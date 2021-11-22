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

bool bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode);

void v_test_dynamic_tree();
void v_dynamic_test_1();


#endif //LIST3_CTREEDYNAMIC_H
