#include <iostream>
#include "BigInteger.h"

using namespace std;
int main() {
    BigInteger a(123456789);
    BigInteger b(2);
    BigInteger c;
    c = a*b;
    c.print();
    c *= b;
    c.print();
    return 0;
}
