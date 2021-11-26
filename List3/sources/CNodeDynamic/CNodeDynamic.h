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

    void vSetValue(int i_new_val);

    int iGetChildrenNumber();

    void vAddNewChild();

    void vAddNewChild(CNodeDynamic *c_node_to_append);

    CNodeDynamic *pcGetChild(int i_child_offset);

    void vPrint();

    void vPrintAllBelow();

    CNodeDynamic *getPcParentNode();

    void setPcParentNode(CNodeDynamic *pc_parent_node);

    void removeChild(CNodeDynamic *pc_child_to_remove);

    int getIVal() const;

    CNodeDynamic *getChild(int i_child_offset);

private:
    std::vector<CNodeDynamic *> v_children;
    CNodeDynamic *pc_parent_node;
    int i_val;
};


#endif //LIST3_CNODEDYNAMIC_H
