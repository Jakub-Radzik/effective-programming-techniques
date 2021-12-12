//
// Created by Jakub Radzik on 12/12/2021.
//

#ifndef LISTA5_CTAB_H
#define LISTA5_CTAB_H


#define DEF_TAB_SIZE 10

class CTab {
public:
    CTab();

    CTab(const CTab &cOther);

    CTab(CTab &&cOther);

    ~CTab();

    CTab operator=(const CTab &cOther);

    CTab operator=(CTab &&cOther) noexcept;

    bool bSetSize(int iNewSize);

    int iGetSize();

private:
    void v_copy(const CTab &cOther);

    int *pi_tab;
    int i_size;
};//class CTab

CTab cCreateTab();

#endif //LISTA5_CTAB_H
