//
// Created by Jakub Radzik on 12/12/2021.
//

#ifndef LISTA5_CTABLE_H
#define LISTA5_CTABLE_H

#define DEF_SIZE 0
#define  NAME "Name"

#include <iostream>
#include <string>

class CTable {
public:
    CTable();

    CTable(std::string sName, int iTableLen);

    CTable(CTable &pcOther);

    CTable(CTable &&pcOther);

    ~CTable();

    void v_set_name(std::string sName);

    bool b_set_new_size(int i_table_length);

    void v_print_array();

    CTable *pcClone();

    CTable operator=(const CTable &c_assign_table);

    CTable operator=(CTable &&cOther) noexcept;;

    CTable operator+(const CTable &c_added_table);

    void v_set_value_at(int iOffset, int iNewVal);

private:
    static const int i_default_size;
    static const std::string s_default_name;

    std::string s_name;
    int i_size;
    int *i_array;
};

#endif //LISTA5_CTABLE_H
