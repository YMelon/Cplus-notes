//数组模板类Array.h的应用

#include <iostream>
#include "Array.h"
using namespace std;


int main() {
    Array<int> a(10);

    cout << "Before resize: " << a.getSize() << endl;
    a.resize(6);
    cout << "After resize: " << a.getSize() << endl;

    return 0;
}
