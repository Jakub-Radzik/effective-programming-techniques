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

//implementacja

CTab::CTab() {
    pi_tab = new int[DEF_TAB_SIZE];
    i_size = DEF_TAB_SIZE;
}

CTab::CTab(const CTab &cOther) {
    v_copy(cOther);
    std::cout << "Copy ";
}

CTab::CTab(CTab &&cOther) {
    pi_tab = cOther.pi_tab;
    i_size = cOther.i_size;

    cOther.pi_tab = NULL;
    cOther.i_size = 0;

    std::cout << "Move Constructor worked " << std::endl;
}

CTab::~CTab() {
    if (pi_tab != NULL) delete pi_tab;
    std::cout << std::endl << "Destr " << this;
}

CTab CTab::operator=(const CTab &cOther) {
    if (pi_tab != NULL) delete pi_tab;
    v_copy(cOther);
    std::cout << "op= ";
    return (*this);
}

CTab CTab::operator=(CTab &&cOther) noexcept {
    if (&cOther == this)
        return *this;

    if (pi_tab != NULL) delete pi_tab;

    pi_tab = cOther.pi_tab;
    i_size = cOther.i_size;
    cOther.pi_tab = NULL;
    cOther.i_size = 0;

    std::cout << "MOVE " << std::endl;

    return *this;
}


void CTab::v_copy(const CTab &cOther) {
    pi_tab = new int[cOther.i_size];
    i_size = cOther.i_size;
    for (int ii = 0; ii < cOther.i_size; ii++)
        pi_tab[ii] = cOther.pi_tab[ii];
}

bool CTab::bSetSize(int iNewSize) {
    if (iNewSize > 0) {
        int *pi_newTable = new int[iNewSize];
        for (int i = 0; i < i_size; ++i)
            pi_newTable[i] = pi_tab[i];
        i_size = iNewSize;
        delete pi_tab;
        pi_tab = pi_newTable;

        return true;
    }
    return false;
}

int CTab::iGetSize() { return (i_size); }

CTab cCreateTab() {
    CTab c_result;
    c_result.bSetSize(5);
    return (std::move(c_result));
}

#endif //LISTA5_CTAB_H
