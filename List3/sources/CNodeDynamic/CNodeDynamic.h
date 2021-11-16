//
// Created by Jakub Radzik on 16/11/2021.
//

#ifndef LIST3_CNODEDYNAMIC_H
#define LIST3_CNODEDYNAMIC_H

#include <vector>
#include "../CTreeDynamic/CTreeDynamic.h"

class CNodeDynamic {
public:
    CNodeDynamic();

    ~CNodeDynamic();

    void vSetValue(int iNewVal);

    int iGetChildrenNumber();

    void vAddNewChild();

    CNodeDynamic *pcGetChild(int iChildOffset);

    void vPrint();

    void vPrintAllBelow();

private:
    std::vector<CNodeDynamic *> v_children;
    CNodeDynamic *pc_parent_node;
    int i_val;
};


#endif //LIST3_CNODEDYNAMIC_H
