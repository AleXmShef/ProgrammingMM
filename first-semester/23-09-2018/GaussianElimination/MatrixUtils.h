//
// Created by yuna on 15.09.18.
//

#ifndef GAUSS_MATRIXUTILS_H
#define GAUSS_MATRIXUTILS_H

#include "AugmentedMatrix.h"

struct MatrixUtils {
    static double * GaussianElimination(AugmentedMatrix matrix);
};


#endif //GAUSS_MATRIXUTILS_H
