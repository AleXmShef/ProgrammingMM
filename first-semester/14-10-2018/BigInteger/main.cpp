#include <iostream>
#include "BigInteger.h"

int main() {
    BigInteger a("1122334455667788991010");
    a.print();
    std::cout<<std::endl<<a[0]<<std::endl<<a[1]<<std::endl<<a[2];
    return 0;
}