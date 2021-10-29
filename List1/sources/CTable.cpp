//
// Created by jakub on 15.10.2021.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include "CTable.h"

const int CTable::i_default_size = 100;
const std::string CTable::s_default_name = "DEFAULT";

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

CTable::~CTable() {
    std::cout << "usuwam: " << s_name << std::endl;

    delete[] i_array;
}

void CTable::v_set_name(std::string sName) {
    s_name = sName;
}

bool CTable::b_set_new_size(int iTableLen) {
    if (iTableLen <= 0) {
        return false;
    }
    int *i_new_array = new int[iTableLen];
    for (int i = 0; i < std::min(iTableLen, i_size); i++) {
        i_new_array[i] = i_array[i];
    }
    i_size = iTableLen;
    delete[] i_array;
    i_array = i_new_array;
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

CTable& CTable::operator=(const CTable& c_assign_table)
{
    i_size = c_assign_table.i_size;
    s_name = c_assign_table.s_name;

    delete[] i_array;
    i_array = new int[i_size];

    for (int i = 0; i < i_size; i++) {
        i_array[i] = c_assign_table.i_array[i];
    }

    return *this;
}

CTable CTable::operator+(const CTable& a_other)
{
    CTable t("Concat of: " + s_name + " & " + a_other.s_name, i_size + a_other.i_size);
    memcpy(t.i_array, i_array, i_size * sizeof(int));
    memcpy(t.i_array + t.i_size, a_other.i_array, a_other.i_size * sizeof(int));

    return t;
}

void CTable::v_set_value_at(int iOffset, int iNewVal) {
    i_array[iOffset] = iNewVal;
}


void v_mod_tab(CTable *pcTab, int iNewSize) {
    pcTab->b_set_new_size(iNewSize);
}

void v_mod_tab(CTable cTab, int iNewSize) {
    cTab.b_set_new_size(iNewSize);
}

