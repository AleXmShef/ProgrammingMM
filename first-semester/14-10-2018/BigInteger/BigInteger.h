//
// Created by yuna on 7.10.18.
//

#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <vector>
#include <string>

struct BigInteger {

    BigInteger();

    BigInteger(BigInteger const &other);

    explicit BigInteger(std::string str);

    explicit BigInteger(long long n);

    explicit BigInteger(std::vector<char> vec);

    void print() const;

    void normalize();

    bool operator==(BigInteger const &number) const;

    BigInteger &operator=(BigInteger const &number);

    BigInteger &operator+=(BigInteger const &number);

    BigInteger &operator-=(BigInteger const &number);

    BigInteger &operator*=(BigInteger const &number);

    std::vector<char> data;
};

BigInteger operator+(BigInteger const &a, BigInteger const &b);

BigInteger operator-(BigInteger const &a, BigInteger const &b);

BigInteger operator*(BigInteger const &a, BigInteger const &b);

BigInteger karatsubaMultiplication(BigInteger const &a, BigInteger const &b);

#endif //BIGINTEGER_H
