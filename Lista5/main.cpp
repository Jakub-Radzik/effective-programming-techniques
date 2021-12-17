#include <iostream>
#include "sources/CTab.h"
#include "sources/CTable.h"
#include "sources/modyfikacja/VectorWrapper.h"

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
//    CTable c_table;
//    CTable c_other;
}

void vTestModifiction(){
    VectorWrapper v_wrapper(5);
    VectorWrapper v_other(5);

    v_wrapper.v_vector_add(0,1);
    v_wrapper.v_vector_add(1,2);
    v_wrapper.v_vector_add(2,3);
    v_wrapper.v_vector_add(3,4);
    v_wrapper.v_vector_add(4,5);

    v_other.v_vector_add(0, 10);
    v_other.v_vector_add(1, 10);
    v_other.v_vector_add(2, 10);
    v_other.v_vector_add(3, 10);
    v_other.v_vector_add(4, 10);

    v_wrapper.v_print_vector();
    v_other.v_print_vector();

    VectorWrapper v_result(v_wrapper);
    v_result.v_print_vector();

    VectorWrapper v_mover(std::move(v_other));
    v_mover.v_print_vector();

}

int main() {
//    vTestCTab();
//    vTestCTable();
    vTestModifiction();
    return 0;
}

