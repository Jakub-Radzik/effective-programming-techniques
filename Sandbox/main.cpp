#include <iostream>

using namespace std;


void v_proc_test() {
    int i_table_size = 4;
    double *pd_table;
    pd_table = new double[i_table_size];
    pd_table[2] = 9;
    pd_table[0] = 11;
    for (int i = 0; i < i_table_size; i++) {
        cout << "Iteration: " << i << endl;
        cout << pd_table[i] << endl;
        cout << *(pd_table + i) << endl;
    }
    cout << pd_table << endl;
    cout << *pd_table << endl;
    delete pd_table;
    cout << pd_table << endl;
    cout << *pd_table << endl;
}

void v_proc_test_2() {
    int i_value = 58;
    int *pi_val;
    char *pc_val;
    void *pv_val;

    pi_val = &i_value;
    pc_val = (char *) &i_value;
    pv_val = (void *) &i_value;

    cout << "Wartosc zmiennej zaalokowanej statycznie: " << i_value << endl;
    cout << "Adres zmiennej zaalokowanej statycznie: " << &i_value << endl;
    cout << "Adres na jaki wskazuje wskaznik p_val: " << pi_val << endl;
    cout << "Wartosc na jaka wskazuje wskaznik p_val: " << *pi_val << endl;
    cout << "===================================================" << endl;
    cout << *pc_val << endl;
    cout << *pc_val << endl;
    cout << *(int *) pv_val << endl;
}

void v_proc_test_3() {
    int i_value = 69;

    int *pi_l1, **pi_l2, ***pi_l3;
    pi_l1 = &i_value;
    pi_l2 = &pi_l1;
    pi_l3 = &pi_l2;

    cout << i_value << " " << &i_value << endl;
    cout << pi_l1 << " " << pi_l2 << " " << pi_l3 << endl;
    cout << *pi_l1 << " " << *pi_l2 << " " << *pi_l3 << endl;
    cout << *pi_l1 << " " << **pi_l2 << " " << **pi_l3 << endl;
    cout << *pi_l1 << " " << **pi_l2 << " " << ***pi_l3 << endl;

}

void vSet5(int iVal) {
    iVal = 5;
}

void vSet5(int *piVal) {
    *piVal = 5;
}

void v_proc_test_4() {
    int i = 2;
    int *p = &i;
    cout << i << " " << *p << endl;
    vSet5(i);
    cout << i << " " << *p << endl;
    vSet5(&i);
    cout << i << " " << *p << endl;
}

void v_proc_test_5() {
    double **pd_two_dimensional_table;
    int i_tab_size = 3;

    pd_two_dimensional_table = new double *[i_tab_size];

    for (int ii = 0; ii < i_tab_size; ii++) {
        pd_two_dimensional_table[ii] = new double[ii + 2];
    }

    for (int i = 0; i < i_tab_size; i++) {
        cout << pd_two_dimensional_table[i] << endl;
    }

    for (int i = 0; i < i_tab_size; i++) {
        delete pd_two_dimensional_table[i];
    }
    delete pd_two_dimensional_table;
}

void v_proc_test_6() {
    int i_static_int = 5;
    int *pi_dynamic_copy;

    pi_dynamic_copy = new int(i_static_int);
    int i_static_copy(i_static_int);

    cout << &i_static_int << " " << pi_dynamic_copy << " " << &i_static_int << endl;
    cout << i_static_int << " " << *pi_dynamic_copy << " " << i_static_int << endl;
    i_static_int = 6;
    cout << i_static_int << " " << *pi_dynamic_copy << " " << i_static_int << endl;

}

int main() {
    int *pi_var;
    pi_var = new int;
    cout << pi_var << endl;
    cout << &pi_var << endl;
    cout << *pi_var << endl;

    v_proc_test();
    v_proc_test_2();
    v_proc_test_3();
    v_proc_test_4();
    v_proc_test_5();
    v_proc_test_6();


    return 0;
}
