//
// Created by yuna on 15.09.18.
//

#ifndef GAUSS_MATRIX_H
#define GAUSS_MATRIX_H

struct AugmentedMatrix {
    explicit AugmentedMatrix(unsigned int rows);

    ~AugmentedMatrix();

    void print();

    double **data;
    unsigned int numberOfRows;
};

#endif //GAUSS_MATRIX_H
