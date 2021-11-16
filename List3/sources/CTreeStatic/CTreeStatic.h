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


#endif //LIST3_CTREESTATIC_H
