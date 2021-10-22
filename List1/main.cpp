#include <iostream>
#include "sources/CTable.h"
#include "sources/TablesFunctions.h"

int main() {

    //Test data
    int i_size = 10;
    int i_size_x = 5;
    int i_size_y = 3;


    // MODYFIKACJA NA ZAJĘCIACH:
    int **pi_table_modification;
    std::cout << "Alokacja [1- OK]: " << TablesFunctions::b_alloc_table_2_dim_modification(&pi_table_modification, i_size_x, i_size_y)
              << std::endl;
    TablesFunctions::v_print_table_2_dim(&pi_table_modification, i_size_x, i_size_y);
    std::cout << "Dealokacja [1- OK]: " << TablesFunctions::b_dealloc_table_2_dim(pi_table_modification, i_size_x) << std::endl;



    // 1:
    std::cout << std::endl << "Execution: v_alloc_table_add_5(i_size);" << std::endl;
    TablesFunctions::v_alloc_table_add_5(i_size);

    // 2:
    std::cout << std::endl << "Execution: b_alloc_table_2_dim(&pi_table, i_size_x, i_size_y);" << std::endl;
    int **pi_table;
    std::cout << "Alokacja [1- OK]: " << TablesFunctions::b_alloc_table_2_dim(&pi_table, i_size_x, i_size_y)
              << std::endl;
    TablesFunctions::v_insert_values_table_2_dim(&pi_table, i_size_x, i_size_y);
    TablesFunctions::v_print_table_2_dim(&pi_table, i_size_x, i_size_y);

    // 3:
    std::cout << "Dealokacja [1- OK]: " << TablesFunctions::b_dealloc_table_2_dim(pi_table, i_size_x) << std::endl;

    // 4:
    std::cout << std::endl << "KONSTRUKTOR BEZPARAMETROWY" << std::endl;
    CTable c_table_1;

    std::cout << std::endl << "KONSTRUKTOR PARAMETROWY" << std::endl;
    CTable c_table_2("c_table_2", 5);

    std::cout << std::endl << "KONSTRUKTOR KOPIUJACY" << std::endl;
    CTable c_table_3(c_table_1);
    CTable c_table_4(c_table_2);

    std::cout << std::endl << "Print c_table_2: " << std::endl;
    c_table_2.v_print_array();
    std::cout << "Set new name: " << std::endl;
    c_table_2.v_set_name("NOWE");
    c_table_2.v_print_array();
    std::cout << "Set new size: " << std::endl;
    c_table_2.b_set_new_size(3);
    c_table_2.v_print_array();

    std::cout << std::endl << "KLONOWANIE" << std::endl;
    CTable c_tab("S", 10);

    CTable *pc_new_tab;
    pc_new_tab = c_tab.pcClone();
    pc_new_tab->v_print_array();

    std::cout << std::endl << "TESTOWANIE PROCEDUR" << std::endl;
    CTable c_tab_5("c_tab_5", 5);
    c_tab_5.v_print_array();

    std::cout << std::endl << "void v_mod_tab(CTable cTab, 3) " << std::endl;
    v_mod_tab(c_tab_5, 3);
    c_tab_5.v_print_array();
    std::cout << std::endl << "void v_mod_tab(CTable *pcTab, 4) " << std::endl;
    v_mod_tab(&c_tab_5, 4);
    c_tab_5.v_print_array();


    std::cout << std::endl << "ALOKACJA STATYCZNA" << std::endl;
    CTable c_static_1;
    CTable c_static_2("static", 5);
    CTable c_static_3(c_static_2);
    std::cout << std::endl << "ALOKACJA DYNAMICZNA" << std::endl;
    CTable *c_dynamic_1 = new CTable();
    CTable *c_dynamic_2 = new CTable("dynamic", 5);
    CTable *c_dynamic_3 = new CTable(*c_dynamic_2);

    std::cout << std::endl << "DESTRUKTORY" << std::endl;
    delete c_dynamic_1;
    delete c_dynamic_2;
    delete c_dynamic_3;


    return 0;
}

