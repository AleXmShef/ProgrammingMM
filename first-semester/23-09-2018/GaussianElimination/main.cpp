#include <iostream>
#include <string>
#include "AugmentedMatrix.h"
#include "MatrixUtils.h"
#include <cmath>

using namespace std;

int main() {

    unsigned int cols, rows;
    cout << "\nEnter number of linear equations: ";
    cin >> rows;
    cout << "\nEnter number of unknowns: ";
    cin >> cols;
    cout << "\nConsider a system of linear equation in form Ax=b";

    AugmentedMatrix matrix(rows, cols);
    matrix.printAll();
    matrix.print();
    double *roots = MatrixUtils::GaussianElimination(matrix);

    for (auto i = 0; i < cols; ++i) {
        if (std::isinf(roots[i])) {
            cout << "No solutions.\t";
            break;
        } else if (std::isnan(roots[i])) {
            cout << "Infinite number of solutions.\t";
            break;
        } else { cout << roots[i] << "  "; }
    }

    // TODO: fix case with infinite number of solutions
    return 0;
}
