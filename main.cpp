#include <iostream>
#include "swap.h"
using namespace std;

int main() {
    int a = 4;
    int b = 5;
    cout << "before a===" << a << endl;
    cout << "before b===" << b << endl;
    // cout << "hello world" << endl;
    swap(a,b);
    cout << "after a===" << a << endl;
    cout << "after b===" << b << endl;
    return 0;
}
