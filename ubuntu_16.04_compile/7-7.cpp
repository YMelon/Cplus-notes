//多继承同名隐藏，例程2
//二义性和冗余

#include <iostream>
using namespace std;

class Base0 {
public:
    int var0;
    void fun0() { cout << "Member of Base0 " << endl; }
};

class Base1: public Base0 {
public:
    int var1;
};

class Base2: public Base0 {
public:
    int var2;
};

class Derived: public Base1, public Base2 {
public:
    int var;
    void fun() { cout << "Member of Derived " << endl; }
};


int main() {
    Derived d;
    d.Base1::var0 = 2;  //引用直接基类
    d.Base1::fun0();
    d.Base2::var0 = 3;  //引用直接基类, 存在两个副本，冗余,解决虚基类
    d.Base2::fun0();

    return 0;
}
