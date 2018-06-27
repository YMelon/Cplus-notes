//虚析构函数

#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base();
};

Base::~Base() {
    cout << "Base destructor" << endl;
}

class Derived: public Base {
private:
    int *p;
public:
    Derived();
    ~Derived();
};

Derived::Derived() {
    p = new int(0);
}

Derived::~Derived() {
    delete p;
    cout << "Derived destructor" << endl;
}

void fun(Base *ptr) {
    delete ptr;    //有可能指向派生类
}


int main() {
    Base *b = new Derived();
    fun(b);

    return 0;
}
