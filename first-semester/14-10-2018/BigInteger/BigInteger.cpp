//
// Created by yuna on 7.10.18.
//

#include "BigInteger.h"
#include <iostream>
#include <algorithm>
#include <string>

BigInteger::BigInteger(std::string str) {
    for (int i = (int) str.length(); i > 0; i -= lgBase)
        if (i < lgBase) {
            int temp = atoi(str.substr(0, i).c_str());
            data.push_back(char(temp));
        } else {
            int temp = atoi(str.substr(i - lgBase, lgBase).c_str());
            data.push_back(char(temp));
        }
    normalize();
}

BigInteger::BigInteger(BigInteger const &other) {
    data = other.data;
}

BigInteger::BigInteger(long long n) {
    std::string str = std::to_string(n);
    for (int i = (int) str.length(); i > 0; i -= lgBase)
        if (i < lgBase) {
            int temp = atoi(str.substr(0, i).c_str());
            data.push_back(char(temp));
        } else {
            int temp = atoi(str.substr(i - lgBase, lgBase).c_str());
            data.push_back(char(temp));
        }
    normalize();
}

BigInteger::BigInteger(std::vector<char> vec) {
    data = vec;
}

BigInteger::BigInteger() = default;

void BigInteger::print() const {
    std::cout << std::endl;
    printf("%d", data.empty() ? 0 : data.back());
    for (int i = (int) data.size() - 2; i >= 0; --i) {
        printf(("%0" + std::to_string(lgBase) + "d").c_str(), data[i]);
    }
}

void BigInteger::normalize() {
    while (data.size() > 1 && data.back() == 0)
        data.pop_back();
}

bool BigInteger::operator==(BigInteger const &other) const {
    if (data.size() != other.data.size()) {
        return false;
    }
    for (auto i = 0; i < data.size(); ++i) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}

BigInteger &BigInteger::operator=(BigInteger const &other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

BigInteger &BigInteger::operator+=(BigInteger const &other) {
    int carry = 0;
    for (size_t i = 0; i < std::max(data.size(), other.data.size()) || carry; ++i) {
        if (i == data.size())
            data.push_back(0);
        data[i] += carry + (i < other.data.size() ? other.data[i] : 0);
        carry = data[i] >= base;
        if (carry) data[i] -= base;
    }
    return *this;
}

BigInteger &BigInteger::operator-=(BigInteger const &other) {
    normalize();
    int carry = 0;
    for (size_t i = 0; i < other.data.size() || carry; ++i) {
        data[i] -= carry + (i < other.data.size() ? other.data[i] : 0);
        carry = data[i] < 0;
        if (carry) data[i] += base;
    }
    normalize();
    return *this;
}

BigInteger &BigInteger::operator*=(BigInteger const &other) {
    BigInteger temp;
    temp.data = std::vector<char>(data.size() + other.data.size(), 0);
    for (auto i = 0; i < data.size(); ++i) {
        for (int j = 0, carry = 0; j < (int) other.data.size() || carry; ++j) {
            long long cur =
                    temp.data[i + j] + data[i] * 1ll * (j < (int) other.data.size() ? other.data[j] : 0) + carry;
            temp.data[i + j] = char(cur % base);
            carry = int(cur / base);
        }
    }
    temp.normalize();
    *this = temp;
    return *this;
}

BigInteger operator+(BigInteger const &a, BigInteger const &b) {
    BigInteger temp = a;
    int carry = 0;
    for (size_t i = 0; i < std::max(temp.data.size(), b.data.size()) || carry; ++i) {
        if (i == temp.data.size())
            temp.data.push_back(0);
        temp.data[i] += carry + (i < b.data.size() ? b.data[i] : 0);
        carry = temp.data[i] >= base;
        if (carry) temp.data[i] -= base;
    }
    return temp;
}

BigInteger operator-(BigInteger const &a, BigInteger const &b) {
    BigInteger temp = a;
    int carry = 0;
    for (size_t i = 0; i < b.data.size() || carry; ++i) {
        temp.data[i] -= carry + (i < b.data.size() ? b.data[i] : 0);
        carry = temp.data[i] < 0;
        if (carry) temp.data[i] += base;
    }
    temp.normalize();
    return temp;
}

BigInteger operator*(BigInteger const &a, BigInteger const &b) {
    BigInteger c;
    c.data = std::vector<char>(a.data.size() + b.data.size(), 0);
    for (size_t i = 0; i < a.data.size(); ++i)
        for (int j = 0, carry = 0; j < (int) b.data.size() || carry; ++j) {
            long long cur = c.data[i + j] + a.data[i] * 1ll * (j < (int) b.data.size() ? b.data[j] : 0) + carry;
            c.data[i + j] = char(cur % base);
            carry = int(cur / base);
        }
    c.normalize();
    return c;
}

BigInteger karatsubaMultiplication(BigInteger const &a, BigInteger const &b) {
    BigInteger maxArg;
    BigInteger minArg;
    if (a.data.size() > b.data.size()) {
        maxArg = a;
        minArg = b;
    } else {
        maxArg = b;
        minArg = a;
    }
    unsigned long minLen = minArg.data.size();
    unsigned long maxLen = maxArg.data.size();

    //trivial case
    if (minLen < 2 || maxLen < 2) {
        BigInteger res(a * b);
        res.normalize();
        return res;
    }

    unsigned long halfLength = (maxLen % 2 == 0 ? maxLen / 2 : (maxLen + 1) / 2);

    //split numbers into 3
    if (minLen <= halfLength) { // length of a is less then half of b
        BigInteger b1;
        for (auto i = 0; i < halfLength; ++i) {
            b1.data.push_back(b.data[i]);
        }
        BigInteger b2;
        for (auto i = halfLength; i < b.data.size(); ++i) {
            b2.data.push_back(b.data[i]);
        }

        BigInteger q = karatsubaMultiplication(a, b1);
        BigInteger p = karatsubaMultiplication(a, b2);
        for (auto i = 0; i < halfLength; ++i) { // ~ *10^(halfsize)
            p.data.insert(p.data.begin(), 0);
        }
        BigInteger res(q + p);
        res.normalize();
        return res;
    }
        //split numbers into 4
    else {
        BigInteger b1;
        for (auto i = 0; i < halfLength; ++i) {
            b1.data.push_back(b.data[i]);
        }
        BigInteger b2;
        for (auto i = halfLength; i < b.data.size(); ++i) {
            b2.data.push_back(b.data[i]);
        }
        BigInteger a1;
        for (auto i = 0; i < halfLength; ++i) {
            a1.data.push_back(a.data[i]);
        }
        BigInteger a2;
        for (auto i = halfLength; i < a.data.size(); ++i) {
            a2.data.push_back(a.data[i]);
        }
        BigInteger q = karatsubaMultiplication(a1, b1);
        BigInteger p = karatsubaMultiplication(a2, b2);
        BigInteger g = karatsubaMultiplication(a1 + a2, b1 + b2);
        g -= (p + q);
        for (auto i = 0; i < maxLen; ++i) { // ~ *10^(maxLength)
            p.data.insert(p.data.begin(), 0);
        }
        for (auto i = 0; i < halfLength; ++i) { // ~ *10^(halfsize)
            g.data.insert(g.data.begin(), 0);
        }
        BigInteger res(q + p + g);
        res.normalize();
        return res;
    }
}
