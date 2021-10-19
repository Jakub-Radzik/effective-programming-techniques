//
// Created by jakub on 15.10.2021.
//

#ifndef LIST1_CTABLE_H
#define LIST1_CTABLE_H

class CTable {
public:
    CTable();
    CTable(std::string sName, int iTableLen);
    CTable(CTable &pcOther);
    ~CTable();
    void v_set_name(std::string sName);
    bool b_set_new_size(int iTableLen);
    void v_print_array();
    CTable *pcClone();


private:
    static const int i_default_size;
    static const std::string s_default_name;

    std::string s_name;
    int i_size;
    int *i_array;
};

#endif //LIST1_CTABLE_H
