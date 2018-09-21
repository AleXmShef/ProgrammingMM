#include <iostream>
#include "Quaternion.h"

using namespace std;

int main() {
    Quaternion a;
    cout << a.x << "  " << a.y << "  " << a.z << "  " << a.scal << endl;
    Quaternion b(-1, 2, 3, 1);
    cout << b.x << "  " << b.y << "  " << b.z << "  " << b.scal << endl;
    Quaternion c = a * b;
    return 0;
}

//TODO: 1) override operators without const stuff 2) make line 11 work