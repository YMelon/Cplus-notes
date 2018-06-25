//类型兼容规则，仔细理解

#include <iostream>
using namespace std;

class Base1 {
public:
    void display() const {
        cout << "Base1::display()" << endl;
    }
};

class Base2: public Base1 {
public:
    void display() const {
        cout << "Base2::display()" << endl;
    }
};

class Derived: public Base2 {
public:
    void display() const {
        cout << "Derived::display()" << endl;
    }
};


void func(Base1 *ptr) {
    ptr -> display();
}


int main() {
    Base1 b1;
    Base2 b2;
    Derived d;

    func(&b1);
    func(&b2);
    func(&d);

    return 0;
}
