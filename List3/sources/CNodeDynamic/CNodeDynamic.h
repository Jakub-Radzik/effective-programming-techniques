//
// Created by Jakub Radzik on 16/11/2021.
//

#ifndef LIST3_CNODEDYNAMIC_H
#define LIST3_CNODEDYNAMIC_H

#include <vector>

class CNodeDynamic {
public:
    CNodeDynamic();

    ~CNodeDynamic();

    void vSetValue(int iNewVal);

    int iGetChildrenNumber();

    void vAddNewChild();

    void vAddNewChild(CNodeDynamic *c_node_to_append);

    CNodeDynamic *pcGetChild(int iChildOffset);

    void vPrint();

    void vPrintAllBelow();

    CNodeDynamic *getPcParentNode();

    void setPcParentNode(CNodeDynamic *pcParentNode);

    void removeChild(CNodeDynamic *oldChild);

    int getIVal() const;

private:
    std::vector<CNodeDynamic *> v_children;
    CNodeDynamic *pc_parent_node;
    int i_val;
};


#endif //LIST3_CNODEDYNAMIC_H
