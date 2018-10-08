//
// Created by yuna on 7.10.18.
//

#ifndef ACKERMANNFUNCTION_BIGINTEGER_H
#define ACKERMANNFUNCTION_BIGINTEGER_H

#include <vector>
#include <string>

const int base = 1000 * 1000 * 1000;

struct BigInteger {
    BigInteger(BigInteger & other);

    explicit BigInteger(std::string str);

    void print();

    BigInteger &operator=(BigInteger &number);

    BigInteger operator+(BigInteger &number);

    BigInteger operator-(BigInteger &number);

    BigInteger operator*(BigInteger &number);

    bool operator==(BigInteger &number);

    std::vector<int> data;

};


#endif //ACKERMANNFUNCTION_BIGINTEGER_H
