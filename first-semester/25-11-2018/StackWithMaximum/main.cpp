#include <iostream>
#import "StackWithMax.h"

using namespace std;

int main() {
    StackWithMax s;
    cout << s.getMax();
    s.push(2);
    cout << s.getMax();
    s.push(3);
    cout << s.getMax();
    s.push(2);
    cout << s.getMax();
    s.push(4);
    cout << s.getMax();
    s.pop();
    cout << s.getMax();
    s.pop();
    cout << s.getMax();
    s.pop();
    cout << s.getMax();
    s.pop();
    cout << s.getMax();
    return 0;
}