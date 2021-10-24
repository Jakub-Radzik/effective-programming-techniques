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

    void operator=(CTable &pcOther);
    CTable operator+(const CTable &c_tab_1);
    void v_set_value_at(int iOffset, int iNewVal);

private:
    static const int i_default_size;
    static const std::string s_default_name;

    std::string s_name;
    int i_size;
    int *i_array;
};

void v_mod_tab(CTable *pcTab, int iNewSize);
void v_mod_tab(CTable cTab, int iNewSize);

#endif //LIST1_CTABLE_H
