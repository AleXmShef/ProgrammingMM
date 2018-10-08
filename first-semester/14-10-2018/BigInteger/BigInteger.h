//
// Created by yuna on 7.10.18.
//

#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <vector>
#include <string>

const int base = 1000 * 1000 * 1000;

struct BigInteger {
    BigInteger(BigInteger &other);

    explicit BigInteger(std::string str);

    explicit BigInteger(int n = 0);

    void print();

    int &operator[](unsigned int index);

    bool operator==(BigInteger &number);

    BigInteger &operator=(BigInteger &number);

    BigInteger operator+=(BigInteger &number);

    BigInteger operator-=(BigInteger &number);

    BigInteger operator*=(BigInteger &number);

    std::vector<int> data;
};

BigInteger operator+(BigInteger &a, BigInteger &b);

BigInteger operator-(BigInteger &a, BigInteger &b);

BigInteger operator*(BigInteger &a, BigInteger &b);

#endif //BIGINTEGER_H
