//
// Created by Jakub Radzik on 17/12/2021.
//

#include "VectorWrapper.h"

VectorWrapper::VectorWrapper(int size) {
    this->sizeOfVector = size;
    this->vector = std::vector<int*>(size);
}

VectorWrapper::VectorWrapper(const VectorWrapper &vectorWrapper) {
    this->sizeOfVector = vectorWrapper.sizeOfVector;
    this->vector = std::vector<int*>(sizeOfVector);

    for (int i = 0; i < sizeOfVector; ++i) {
        this->vector[i] = new int(*vectorWrapper.vector[i]);
    }

    std::cout << "Copy constructor" << std::endl;
}

VectorWrapper::VectorWrapper(VectorWrapper &&vectorWrapper) noexcept {
    this->sizeOfVector = vectorWrapper.sizeOfVector;
    this->vector = std::move(vectorWrapper.vector);

    vectorWrapper.sizeOfVector = 0;

    std::cout<< "Move constructor" << std::endl;
}

VectorWrapper::~VectorWrapper() {
    for (int i = 0; i < sizeOfVector; ++i) {
        delete vector[i];
    }
}

void VectorWrapper::v_vector_add(int iOffset, int iValue) {
    vector.at(iOffset) = new int(iValue);
}

void VectorWrapper::v_print_vector() {
    for (int i = 0; i < sizeOfVector; ++i) {
        std::cout << *vector[i] << " ";
    }
    std::cout << std::endl;
}

