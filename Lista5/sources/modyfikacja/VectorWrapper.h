//
// Created by Jakub Radzik on 17/12/2021.
//

#ifndef LISTA5_VECTORWRAPPER_H
#define LISTA5_VECTORWRAPPER_H
#include <iostream>
#include <vector>

class VectorWrapper {
public:
    VectorWrapper(int size);
    VectorWrapper(const VectorWrapper &vectorWrapper);
    VectorWrapper(VectorWrapper &&vectorWrapper) noexcept ;
    ~VectorWrapper();
    void v_vector_add(int iOffset, int iValue);
    void v_print_vector();

private:
    std::vector<int*> vector;
    int sizeOfVector;
};


#endif //LISTA5_VECTORWRAPPER_H
