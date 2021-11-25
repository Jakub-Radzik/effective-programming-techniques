//
// Created by Jakub Radzik on 09/11/2021.
//

#ifndef LIST3_CNODESTATIC_H
#define LIST3_CNODESTATIC_H

#include <iostream>
#include <vector>

class CNodeStatic {
public:
    CNodeStatic();

    ~CNodeStatic();

    void vSetValue(int i_new_val);

    int iGetChildrenNumber();

    void vAddNewChild();

    CNodeStatic *pcGetChild(int i_child_offset);

    void vPrint();

    void vPrintAllBelow();

    void vPrintUp();

    void removeChild(CNodeStatic *pc_child_to_remove);

    CNodeStatic *getPcParentNode() const;

    void setPcParentNode(CNodeStatic *pc_new_parent_node);

    int getIVal() const;

    void removeAllChildren();

private:
    std::vector<CNodeStatic> v_children;
    CNodeStatic *pc_parent_node;
    int i_val;

};

void vTreeTest();

//class CNodeStatic


#endif //LIST3_CNODESTATIC_H
