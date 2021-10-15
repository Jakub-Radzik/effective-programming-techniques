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