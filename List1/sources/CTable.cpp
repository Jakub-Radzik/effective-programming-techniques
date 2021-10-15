//
// Created by jakub on 15.10.2021.
//

#include <iostream>
#include <cstring>
#include "CTable.h"

CTable::CTable() : s_name("DEFAULT"), i_size(10) {
    s_array = new int[i_size];
    std::cout << "bezp: " << s_name << std::endl;
}

CTable::CTable(std::string sName, int iTableLen) : s_name(sName), i_size(iTableLen) {
    //TODO: what if length <=0
    s_array = new int[i_size];
    std::cout << "parametr: '" << s_name << "'" << std::endl;
}

CTable::CTable(CTable &pcOther) : s_name(pcOther.s_name + "_copy"), i_size(pcOther.i_size) {
    s_array = new int[i_size];
    for (int i = 0; i < i_size; i++) {
        s_array[i] = pcOther.s_array[i];
    }
    std::cout << "kopiuj: " << s_name << endl;
}

const std::string &CTable::getSName() const {
    return s_name;
}

void CTable::setSName(const std::string &sName) {
    s_name = sName;
}

int CTable::getISize() const {
    return i_size;
}

void CTable::setISize(int iSize) {
    i_size = iSize;
}

int *CTable::getSArray() const {
    return s_array;
}

void CTable::setSArray(int *sArray) {
    s_array = sArray;
}
