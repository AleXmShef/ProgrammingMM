//
// Created by yuna on 15.09.18.
//

#include "AugmentedMatrix.h"
#include <iostream>

AugmentedMatrix::AugmentedMatrix(unsigned int rows) : numberOfRows(rows) {
    data = new double *[rows];
    data[0] = new double[(rows + 1) * rows];
    for (auto i = 1; i < rows; ++i) {
        data[i] = data[i - 1] + rows + 1;
    }
    std::cout << "Enter the coefficients:";
    // Read input data
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            std::cin >> data[i][j];
        }
    }

    std::cout << "Enter the constant terms:";
    for (int i = 0; i < rows; i++) {
        std::cin >> data[i][rows];
    }
}

AugmentedMatrix::~AugmentedMatrix() {
    delete[] data[0];
    delete[] data;
}

void AugmentedMatrix::print() {
    std::cout <<std::endl;
    for (int i=0; i<numberOfRows; i++) {
        for (int j=0; j<numberOfRows+1; j++) {
            std::cout << data[i][j] << "\t";
            if (j == numberOfRows-1) {
                std::cout << "| ";
            }
        }
        std::cout << "\n";
    }
}

