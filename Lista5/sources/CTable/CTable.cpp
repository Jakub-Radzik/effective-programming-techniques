//
// Created by Jakub Radzik on 12/12/2021.
//

#include "CTable.h"

//CONSTANTS
const int CTable::i_default_size = 100;
const std::string CTable::s_default_name = "DEFAULT";

//CONSTRUCTORS
CTable::CTable() {
    s_name = s_default_name;
    i_size = i_default_size;

    i_array = new int[i_size];
    std::cout << "bezp: " << s_name << std::endl;
}

CTable::CTable(std::string sName, int iTableLen) {
    s_name = sName;
    i_size = iTableLen;

    i_array = new int[i_size];

    std::cout << "parametr: '" << s_name << "'" << std::endl;
}

CTable::CTable(CTable &pcOther) {
    s_name = pcOther.s_name + "_copy";
    i_size = pcOther.i_size;
    i_array = new int[i_size];

    for (int i = 0; i < i_size; i++) {
        i_array[i] = pcOther.i_array[i];
    }

    std::cout << "kopiuj: " << s_name << std::endl;
}

CTable::CTable(CTable &&pcOther) {
    s_name = pcOther.s_name + "_move";
    i_size = pcOther.i_size;
    i_array = pcOther.i_array;

    pcOther.s_name.erase();
    pcOther.i_size = 0;
    pcOther.i_array = nullptr;

    std::cout << "przenies: " << s_name << std::endl;
}

//DESTRUCTOR
CTable::~CTable() {
    std::cout << "usuwam: " << s_name << std::endl;

    delete[] i_array;
}

void CTable::v_set_name(std::string sName) {
    s_name = sName;
}

bool CTable::b_set_new_size(int i_table_length) {
    if (i_table_length <= 0) {
        return false;
    }
    int *i_new_array = new int[i_table_length];
    memcpy(i_new_array, i_array, sizeof(int) * std::min(i_table_length, i_size));
    delete[] i_array;
    i_array = i_new_array;
    i_size = i_table_length;
    return true;
}

void CTable::v_print_array() {
    std::cout << "{" << s_name << "} " << '[';
    for (int i = 0; i < i_size; i++) {
        std::cout << i_array[i] << ", ";
    }
    std::cout << "] LENGTH = " << i_size << std::endl;
}

CTable *CTable::pcClone() {
    CTable *tab = new CTable(*this);
    return tab;
}

//OPERATORS

CTable CTable::operator=(const CTable &c_assign_table) {
    if (&c_assign_table == this)
        return *this;

    if (i_array != NULL) delete i_array;

    s_name = c_assign_table.s_name;
    i_size = c_assign_table.i_size;
    i_array = new int[i_size];
    for (int i = 0; i < i_size; ++i)
        i_array[i] = c_assign_table.i_array[i];

    std::cout << "Copy " << std::endl;
    return (*this);
}

CTable CTable::operator=(CTable &&cOther) noexcept {
    if (&cOther == this)
        return *this;

    if (i_array != NULL) delete i_array;

    s_name = cOther.s_name;
    i_size = cOther.i_size;
    i_array = cOther.i_array;

    for (int i = 0; i < i_size; ++i)
        i_array[i] = cOther.i_array[i];

    cOther.i_array = NULL;
    cOther.i_size = 0;
    cOther.s_name.erase();

    std::cout << "MOVE OPR " << std::endl;

    return (*this);
}

CTable CTable::operator+(const CTable &c_added_table) {
    int i_oldSize = i_size;
    int i_newSize = i_oldSize + c_added_table.i_size;

    i_size = i_newSize;
    int *pi_newTable = new int[i_size];
    for (int i = 0; i < i_oldSize; ++i)
        pi_newTable[i] = i_array[i];

    delete i_array;
    i_array = pi_newTable;

    for (int i = i_oldSize; i < i_newSize; ++i)
        v_set_value_at(i, c_added_table.i_array[i - i_oldSize]);

    return *this;
}

void CTable::v_set_value_at(int iOffset, int iNewVal) {
    i_array[iOffset] = iNewVal;
}
