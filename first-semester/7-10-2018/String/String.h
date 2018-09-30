//
// Created by yuna on 27.09.18.
//

#ifndef TASK2_STRING_H
#define TASK2_STRING_H

struct String {

    String(char *cstr);

    ~String();

    char &operator[](unsigned int index) const;

    void print() const;

    unsigned int getLength() const;

    String &operator+=(String const &other);

    String &operator+=(char * cstr);

private:
    unsigned int length;
    char *data;

};


#endif //TASK2_STRING_H
