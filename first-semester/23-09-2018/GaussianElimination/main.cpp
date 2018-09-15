#include <iostream>
#include <string>
#include "AugmentedMatrix.h"
#include "MatrixUtils.h"
#include <cmath>

using namespace std;


int main() {
    cout << "Enter the number of linear equations:";
    unsigned int n;
    cin >> n;
    AugmentedMatrix matrix(n);
    matrix.print();

    double *roots = MatrixUtils::GaussianElimination(matrix);

    for (auto i = 0; i < n; ++i) {
        if (std::isinf(roots[i])) {
            cout << "No solutions.\t";
            break;
        } else if (std::isnan(roots[i])) {
            cout << "Infinite number of solutions.\t";
            break;
        } else { cout << roots[i] << "  "; }
    }

    return 0;
}