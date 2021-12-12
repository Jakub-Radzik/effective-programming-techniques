#include <iostream>
#include "sources/CTab/CTab.h"
#include "sources/CTable/CTable.h"

void vTestCTab() {
    CTab c_tab;
    CTab c_other;
    std::cout << "c_tab: " << &c_tab << std::endl;
    std::cout << "C_other: " << &c_other << std::endl;
    c_tab = std::move(c_other);
}

void vTestCTable() {
//    CTable c_table;
//    CTable c_other;
//    std::cout << "c_table: " << &c_table << std::endl;
//    std::cout << "C_other: " << &c_other << std::endl;
//    c_table = std::move(c_other);

    CTable c_table;
    CTable c_other;
}

int main() {
    vTestCTab();
//    vTestCTable();

    return 0;
}

