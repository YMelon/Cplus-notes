//派生类的构造和析构
//分析程序的输出

#include <iostream>
using namespace std;

class Base1 {
public:
    Base1(int i) { cout << "Constructing Base1 " << i << endl; }
    ~Base1() { cout << "Destructing Base1 " << endl; }
};

class Base2 {
public:
    Base2(int j) { cout << "Constructing Base2 " << j << endl; }
    ~Base2() { cout << "Destructing Base2 " << endl; }
};

class Base3 {
public:
    Base3() { cout << "Constructing Base3* " << endl; }
    ~Base3() { cout << "Destructing Base3 " << endl; }
};

class Derived: public Base2, public Base1, public Base3 {
private:
    Base1 mb1;
    Base2 mb2;
    Base3 mb3;

public:
    Derived(int a, int b, int c, int d)
	:Base2(a), Base1(b), mb1(c), mb2(d) {
       cout << "Constructing Derived " << endl; 
    }
    ~Derived() { cout << "Destructing Derived " << endl; }
};


int main() {
    Derived obj(1, 2, 3, 4);

    return 0;
}
