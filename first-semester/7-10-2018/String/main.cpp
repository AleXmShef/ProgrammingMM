#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;

int main() {
    char * a  = "Hello, ";
    String str(a);
    str.print();

    char * b  = "world ";
    String str2(b);
    str += str2;
    str.print();

    char * c  = "of programming!";
    str += c;
    str.print();

    return 0;
}