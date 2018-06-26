//多继承同名隐藏，及二义性问题，例程1

#include <iostream>
using namespace std;

class Base1 {
public:
    int var;
    void func() { cout << "Member of Base1" << endl; }
};

class Base2 {
public:
    int var;
    void func() { cout << "Member of Base2" << endl; }
};

/*
class Derived: public Base1, public Base2 {
public:
    int var;
    void func() { cout << "Member of Derived" << endl; }
};
*/


//演示二义性问题
//派生类中不增加同名新成员,访问产生错误
class Derived: public Base1, public Base2 { };


/*
//使用using关键字
class Derived: public Base1, public Base2 {
public:
    using Base1::var;
    using Base1::func;
};
*/

int main() {
    Derived d;
    Derived *p = &d;
    
    //访问Derived类成员
    d.var = 1;
    d.func();
    
    //访问Base1类成员
    d.Base1::var = 2;
    d.Base1::func();

    p -> Base2::var = 3;
    p -> Base2::func();

    return 0;
}
