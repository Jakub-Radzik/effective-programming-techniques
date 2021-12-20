//
// Created by Jakub Radzik on 12/12/2021.
//

#ifndef LISTA5_CMYSMARTPOINTER_H
#define LISTA5_CMYSMARTPOINTER_H

#include <cstddef>
#include <iostream>
#include "CRefCounter.h"

template<typename T>
class CMySmartPointer {
public:
    CMySmartPointer() {
        pc_pointer = NULL;
        pc_counter = NULL;
    }

    CMySmartPointer(const CMySmartPoint
            er<T> &pc_other) {
        pc_pointer = pc_other.pc_pointer;
        pc_counter = pc_other.pc_counter;

        pc_counter->iAdd();
        std::cout << "Skopiowano! Ref count: " << pc_counter->iGet() << std::endl;
    }

    ~CMySmartPointer() {
        if (pc_counter->iDec() == 0) {
            delete pc_counter;
            delete pc_pointer;
            std::cout << "Destruktor" << std::endl;
        }
    }

    T &operator*() { return *pc_pointer; }

    T *operator->() { return pc_pointer; }

    CMySmartPointer<T> &operator=(const CMySmartPointer<T> &c_other) {
        if (this != &c_other) {
            if (pc_counter && pc_counter->iDec() == 0) {
                delete pc_counter;
                delete pc_pointer;
            }
            pc_pointer = c_other.pc_pointer;
            pc_counter = c_other.pc_counter;
            pc_counter->iAdd();
        }
        std::cout << "Przypisanie smart pointera! Ref count: " << pc_counter->iGet() << std::endl;

        return *this;
    }
private:
    T *pc_pointer;
    CRefCounter *pc_counter;

};

#endif //LISTA5_CMYSMARTPOINTER_H
