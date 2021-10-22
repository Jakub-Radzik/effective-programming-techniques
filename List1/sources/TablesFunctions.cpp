//
// Created by jakub on 19.10.2021.
//

#include <iostream>
#include "TablesFunctions.h"

bool TablesFunctions::b_is_number_positive(int i_number) {
    return i_number > 0;
}

//1:
void TablesFunctions::v_alloc_table_add_5(int i_size) {
    if (b_is_number_positive(i_size)) {
        const int i_offset_additional_value = 5;

        int *pi_table;
        pi_table = new int[i_size];
        for (int i = 0; i < i_size; i++) {
            pi_table[i] = i + i_offset_additional_value;
        }

        for (int i = 0; i < i_size; i++) {
            std::cout << pi_table[i] << " ";
        }

        delete[] pi_table;

    } else {
        std::cout << "Number is not greater than 0 !!" << std::endl;
    }
}

// 2 :
bool TablesFunctions::b_alloc_table_2_dim(int ***pi_table, int i_size_x, int i_size_y) {
    if (b_is_number_positive(i_size_x) && b_is_number_positive(i_size_y)) {
        *pi_table = new int *[i_size_x];
        for (int i = 0; i < i_size_x; i++) {
            (*pi_table)[i] = new int[i_size_y];
        }
        return true;
    }
    return false;
}

// 3:
//Odpowiedź na pytanie: Tak, nie potrzebujemy wszystkich parametrów
bool TablesFunctions::b_dealloc_table_2_dim(int **pi_table, int i_size_x) {
    if (b_is_number_positive(i_size_x)) {
        for (int i = 0; i < i_size_x; i++) {
            delete pi_table[i];
        }
        delete pi_table;
        return true;
    }
    return false;
}

void TablesFunctions::v_insert_values_table_2_dim(int ***pi_table, int i_size_x, int i_size_y) {
    for (int i = 0; i < i_size_x; i++) {
        for (int j = 0; j < i_size_y; j++) {
            (*pi_table)[i][j] = i + j;
        }
    }
}

void TablesFunctions::v_print_table_2_dim(int ***pi_table, int i_size_x, int i_size_y) {
    for (int i = 0; i < i_size_x; i++) {
        for (int j = 0; j < i_size_y; j++) {
            std::cout << "[" << &(*pi_table)[i][j] << " : " << (*pi_table)[i][j] << "] ";
        }
        std::cout << std::endl;
    }
    std::cout << " " << std::endl;
}

//modyfikacja
bool TablesFunctions::b_alloc_table_2_dim_modification(int ** &pi_table, int i_size_x, int i_size_y) {
    if (b_is_number_positive(i_size_x) && b_is_number_positive(i_size_y)) {
        *pi_table = new int *[i_size_x];
        for (int i = 0; i < i_size_x; i++) {
            *(*pi_table + i) = new int[i_size_y];
        }

        int **pi_filler = *pi_table;

        for (int i = 0; i < i_size_x; i++) {
            for (int j = 0; j < i_size_y; j++) {
                *(*((*pi_table) + i) + j) = i+j;
            }
        }

        return true;
    }
    return false;
}
