//
// Created by yuna on 15.09.18.
//

#ifndef GAUSS_MATRIX_H
#define GAUSS_MATRIX_H

struct AugmentedMatrix {
    explicit AugmentedMatrix(unsigned int rows, unsigned int cols);

    ~AugmentedMatrix();

    void print();

    void printAll();

    unsigned int getSize();

    double **data;
private:
    unsigned int size;
    unsigned int rows;
    unsigned int cols;
};

#endif //GAUSS_MATRIX_H
