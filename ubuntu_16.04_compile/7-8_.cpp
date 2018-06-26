//虚基类，及构造函数编写举例

#include <iostream>
using namespace std;

class Base0 {
public:
    Base0(int var) :var0(var) { //添加构造函数
	cout << "Calling Base0 constructor" << endl;
    }
    int var0;
    void fun0() { cout << "Member of Base0" << endl; }
};

class Base1: virtual public Base0 {
public:
    Base1(int var) :Base0(var) {  //add constructor
	cout << "Calling Base1 constructor" << endl;
    }
    int var1;
};

class Base2: virtual public Base0 {
public:
    Base2(int var) :Base0(var) {  //add constructor
	cout << "Calling Base2 constructor" << endl;
    }
    int var2;
};

class Derived: public Base1, public Base2 {
public:
    //派生类构造函数，初始化规则
    //构造一个派生类对象的顺序
    Derived(int var) :Base0(var), Base1(var), Base2(var) { 
	cout << "Calling Derived constructor" << endl;
    }
    int var;
    void fun() { cout << "Member of Derived" << endl; }
};


int main() {
    Derived d(1);
    d.var0 = 2;  //直接访问虚基类的成员
    d.fun0();

    return 0;
}
