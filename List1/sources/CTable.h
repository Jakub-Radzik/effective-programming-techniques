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


    //GETTERS
    std::string &getSName() const;
    int getISize() const;
    int *getSArray() const;

    //SETTERS
    void setSName(const std::string &sName);
    void setISize(int iSize);
    void setSArray(int *sArray);

private:
    std::string s_name;
    int i_size;
    int *s_array;
};

#endif //LIST1_CTABLE_H
