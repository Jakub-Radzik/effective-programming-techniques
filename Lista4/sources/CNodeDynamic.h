//
// Created by Jakub Radzik on 29/11/2021.
//

#ifndef LISTA4_CNODEDYNAMIC_H
#define LISTA4_CNODEDYNAMIC_H

#include <vector>

template<typename T>
class CNodeDynamic {
public:
    CNodeDynamic();

    CNodeDynamic(T t_init_val);

    ~CNodeDynamic();

    void vSetValue(T t_new_val);

    int iGetChildrenNumber();

    void vAddNewChild();

    void vAddNewChild(CNodeDynamic *c_node_to_append);

    CNodeDynamic *pcGetChild(int i_child_offset);

    void vPrint();

    void vPrintAllBelow();

    CNodeDynamic *getPcParentNode();

    void setPcParentNode(CNodeDynamic *pc_parent_node);

    void removeChild(CNodeDynamic *pc_child_to_remove);

    T getTVal() const;

    CNodeDynamic *getChild(int i_child_offset);

private:
    std::vector<CNodeDynamic *> v_children;
    CNodeDynamic *pc_parent_node;
    T t_val;
};

// ----------------------------------------------------------------------------------------------------------------------

template<typename T>
CNodeDynamic<T>::CNodeDynamic() {
    pc_parent_node = nullptr;
}

template<typename T>
CNodeDynamic<T>::CNodeDynamic(T t_init_val) {
    t_val = t_init_val;
    pc_parent_node = nullptr;
}

template<typename T>
CNodeDynamic<T>::~CNodeDynamic() {
    if (iGetChildrenNumber() == 0) {
        return;
    } else {
        for (int i = 0; i < iGetChildrenNumber(); i++) {
            delete v_children[i];
        }
    }
}

template<typename T>
void CNodeDynamic<T>::vSetValue(T t_new_val) {
    t_val = t_new_val;
}

template<typename T>
int CNodeDynamic<T>::iGetChildrenNumber() { return v_children.size(); }

template<typename T>
void CNodeDynamic<T>::vAddNewChild() {
    CNodeDynamic *newNode;
    newNode = new CNodeDynamic();
    newNode->setPcParentNode(this);
    v_children.push_back(newNode);
    newNode = nullptr;
}

template<typename T>
void CNodeDynamic<T>::vAddNewChild(CNodeDynamic *c_node_to_append) {
    c_node_to_append->setPcParentNode(this);
    v_children.push_back(c_node_to_append);
}

template<typename T>
CNodeDynamic<T> *CNodeDynamic<T>::pcGetChild(int i_child_offset) {
    if (i_child_offset >= iGetChildrenNumber() || i_child_offset < 0)
        return nullptr;
    return v_children[i_child_offset];
}

template<typename T>
void CNodeDynamic<T>::vPrint() { std::cout << " " << t_val; }

template<typename T>
void CNodeDynamic<T>::vPrintAllBelow() {
    vPrint();

    for (int i = 0; i < iGetChildrenNumber(); i++) {
        v_children[i]->vPrintAllBelow();
    }
}

template<typename T>
CNodeDynamic<T> *CNodeDynamic<T>::getPcParentNode() {
    return pc_parent_node;
}

template<typename T>
void CNodeDynamic<T>::setPcParentNode(CNodeDynamic *pc_new_parent_node) {
    pc_parent_node = pc_new_parent_node;
}

template<typename T>
void CNodeDynamic<T>::removeChild(CNodeDynamic *pc_child_to_remove) {
    for (int i = 0; i < iGetChildrenNumber(); i++) {
        if ((*v_children[i]).t_val == pc_child_to_remove->t_val) {
            v_children.erase(v_children.begin() + i);
        }
    }
}

template<typename T>
CNodeDynamic<T> *CNodeDynamic<T>::getChild(int i_child_offset) {
    return v_children[i_child_offset];
}

template<typename T>
T CNodeDynamic<T>::getTVal() const {
    return t_val;
}


#endif //LISTA4_CNODEDYNAMIC_H
