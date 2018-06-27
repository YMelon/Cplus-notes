//纯虚函数和抽象类

#include <iostream>
using namespace std;

class Base1 {
public:
    virtual void display() const=0;
};

class Base2: public Base1 {
public:
    virtual void display() const;
};

void Base2::display() const{
    cout << "Base2::display()" << endl;
}

class Derived: public Base2 {
public:
    virtual void display() const;
};

void Derived::display() const{
    cout << "Derived::display()" << endl;
}

void fun(Base1 *ptr) {
    ptr -> display();
}


int main() {
    Base2 b2;
    Derived d;
    fun(&b2);
    fun(&d);

    return 0;
}
