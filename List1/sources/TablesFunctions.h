//
// Created by jakub on 19.10.2021.
//

#ifndef LIST1_TABLESFUNCTIONS_H
#define LIST1_TABLESFUNCTIONS_H


class TablesFunctions {
public:
    static void v_alloc_table_add_5(int i_size);
    static bool b_alloc_table_2_dim(int ***pi_table, int i_size_x, int i_size_y);
    static bool b_dealloc_table_2_dim(int **pi_table, int i_size_x);

    static void v_insert_values_table_2_dim(int ***pi_table, int i_size_x, int i_size_y);
    static void v_print_table_2_dim(int ***pi_table, int i_size_x, int i_size_y);
private:
    static bool b_is_number_positive(int i_number);
};


#endif //LIST1_TABLESFUNCTIONS_H
