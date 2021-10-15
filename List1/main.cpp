#include <iostream>
#include <string>
#include "sources/CTable.h"

using namespace std;

const int i_offset_additional_value = 5;

// 1 :
bool b_is_number_positive(int i_number) {
    return i_number > 0;
}

void v_alloc_table_add_5(int i_size) {
    if (b_is_number_positive(i_size)) {

        int *pi_table;
        pi_table = new int[i_size];
        for (int i = 0; i < i_size; i++) {
            pi_table[i] = i + i_offset_additional_value;
        }

        for (int i = 0; i < i_size; i++) {
            cout << pi_table[i] << " ";
        }

        delete[] pi_table;

    } else {
        cout << "Number is not greater than 0 !!" << endl;
    }
}

// 2 :
bool b_alloc_table_2_dim(int ***pi_table, int i_size_x, int i_size_y) {
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
bool b_dealloc_table_2_dim(int ***pi_table, int i_size_x, int i_size_y) {
    if (b_is_number_positive(i_size_x) && b_is_number_positive(i_size_y)) {
        for (int i = 0; i < i_size_x; i++) {
            delete (*pi_table)[i];
        }
        delete[] *pi_table;
        return true;
    }
    return false;
}

bool b_dealloc_table_2_dim(int ***pi_table, int i_size_x) {
    if (b_is_number_positive(i_size_x)) {
        for (int i = 0; i < i_size_x; i++) {
            delete[] pi_table[i];
        }
        delete[] *pi_table;
        return true;
    }
    return false;
}

int main() {
    //Test data
    int i_size = 10;
    int i_size_x = 5;
    int i_size_y = 3;

    // 1:
    cout << endl << "Execution: v_alloc_table_add_5(i_size);" << endl;
    v_alloc_table_add_5(i_size);

    // 2:
    cout << endl << "Execution: b_alloc_table_2_dim(&pi_table, i_size_x, i_size_y);" << endl;
    int **pi_table;
    b_alloc_table_2_dim(&pi_table, i_size_x, i_size_y);
    for (int i = 0; i < i_size_x; i++) {
        for (int j = 0; j < i_size_y; j++) {
            pi_table[i][j] = i + j;
        }
    }

    for (int i = 0; i < i_size_x; i++) {
        for (int j = 0; j < i_size_y; j++) {
            cout << "[" << &pi_table[i][j] << " : " << pi_table[i][j] << "] ";
        }
        cout << endl;
    }
    cout << " " << endl;


    // 3:
    b_dealloc_table_2_dim(&pi_table, i_size_x, i_size_y);

    cout << "after" << endl;
    cout << "after" << endl;

    CTable table;

    return 0;
}


