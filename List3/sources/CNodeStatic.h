//
// Created by Jakub Radzik on 09/11/2021.
//

#ifndef LIST3_CNODESTATIC_H
#define LIST3_CNODESTATIC_H


class CNodeStatic {
public:
    CNodeStatic();

    ~CNodeStatic();

    void vSetValue(int iNewVal);

    int iGetChildrenNumber();

    void vAddNewChild();

    CNodeStatic *pcGetChild(int iChildOffset);

    void vPrint();

    void vPrintAllBelow();

private:
    vector <CNodeStatic> v_children;
    CNodeStatic *pc_parent_node;
    int i_val;
}//class CNodeStatic


#endif //LIST3_CNODESTATIC_H
