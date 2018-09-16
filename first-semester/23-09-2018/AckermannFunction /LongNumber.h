//
// Created by yuna on 16.09.18.
//

#ifndef ACKERMANNFUNCTION_LONGNUMBER_H
#define ACKERMANNFUNCTION_LONGNUMBER_H

#include <vector>
#include <string>

const int base = 1000 * 1000 * 1000;

struct LongNumber {
    LongNumber(LongNumber & other);

    explicit LongNumber(std::string str);

    void print();

    LongNumber &operator=(LongNumber &number);

    LongNumber operator+(LongNumber &number);

    LongNumber operator-(LongNumber &number);

    bool operator==(LongNumber &number);

    std::vector<int> data;

};


#endif //ACKERMANNFUNCTION_LONGNUMBER_H
