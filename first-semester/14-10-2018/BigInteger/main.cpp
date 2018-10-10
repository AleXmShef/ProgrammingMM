#include <iostream>
#include "BigInteger.h"

using namespace std;

int main() {
    BigInteger a(1234);
    BigInteger b(2);
    BigInteger c;
    c = a * b;
    c *= b;

    auto res = karatsubaMultiplication(a, c);
    res.print();
    res = a * c;
    res.print();
    return 0;
}
