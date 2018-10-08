//
// Created by yuna on 7.10.18.
//

#include "BigInteger.h"
#include <iostream>
#include <algorithm>

BigInteger::BigInteger(std::string str) {
    for (int i = (int) str.length(); i > 0; i -= 9)
        if (i < 9) {
            int temp = atoi(str.substr(0, i).c_str());
            data.push_back(temp);
        } else {
            int temp = atoi(str.substr(i - 9, 9).c_str());
            data.push_back(temp);
        }
    while (data.size() > 1 && data.back() == 0)
        data.pop_back();
}

void BigInteger::print() {
    printf("%d", data.empty() ? 0 : data.back());
    for (int i = (int) data.size() - 2; i >= 0; --i)
        printf("%09d", data[i]);
}

BigInteger &BigInteger::operator=(BigInteger &number) {
    if (this != &number) {
        data = number.data;
    }
    return *this;
}

BigInteger BigInteger::operator+(BigInteger &number) {
    BigInteger temp = *this;
    int carry = 0;
    for (size_t i = 0; i < std::max(temp.data.size(), number.data.size()) || carry; ++i) {
        if (i == temp.data.size())
            temp.data.push_back(0);
        temp.data[i] += carry + (i < number.data.size() ? number.data[i] : 0);
        carry = temp.data[i] >= base;
        if (carry) temp.data[i] -= base;
    }
    return temp;
}

BigInteger BigInteger::operator-(BigInteger &number) {
    BigInteger temp = *this;
    int carry = 0;
    for (size_t i = 0; i < number.data.size() || carry; ++i) {
        temp.data[i] -= carry + (i < number.data.size() ? number.data[i] : 0);
        carry = temp.data[i] < 0;
        if (carry) temp.data[i] += base;
    }
    while (temp.data.size() > 1 && temp.data.back() == 0)
        temp.data.pop_back();
    return temp;
}

bool BigInteger::operator==(BigInteger &number) {
    if (data.size() != number.data.size()) {
        return false;
    }
    for (auto i = 0; i < data.size(); ++i) {
        if (data[i] != number.data[i]) {
            return false;
        }
    }
    return true;
}

BigInteger::BigInteger(BigInteger &other) {
    data = other.data;
}
