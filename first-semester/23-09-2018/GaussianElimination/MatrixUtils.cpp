//
// Created by yuna on 15.09.18.
//

#include "MatrixUtils.h"
#include <cmath>

double *MatrixUtils::GaussianElimination(AugmentedMatrix matrix) {
    unsigned int n = matrix.getSize();

    for (int i = 0; i < n; i++) {
        // Search for maximum in this column
        double maxElement = std::abs(matrix.data[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (std::abs(matrix.data[k][i]) > maxElement) {
                maxElement = std::abs(matrix.data[k][i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row (column by column)
        for (int k = i; k < n + 1; k++) {
            double tmp = matrix.data[maxRow][k];
            matrix.data[maxRow][k] = matrix.data[i][k];
            matrix.data[i][k] = tmp;
        }

        // Make all rows below this one 0 in current column
        for (int k = i + 1; k < n; k++) {
            double c = -matrix.data[k][i] / matrix.data[i][i];
            for (int j = i; j < n + 1; j++) {
                if (i == j) {
                    matrix.data[k][j] = 0;
                } else {
                    matrix.data[k][j] += c * matrix.data[i][j];
                }
            }
        }
    }

    // Solve equation Ax=b for an upper triangular data A
    double *results = new double[n];
    for (int i = n - 1; i >= 0; i--) {
        results[i] = matrix.data[i][n] / matrix.data[i][i];
        for (int k = i - 1; k >= 0; k--) {
            matrix.data[k][n] -= matrix.data[k][i] * results[i];
        }
    }
    return results;
}
