// virtual-destructor.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


class Base {
public:
	virtual ~Base();
};

Base::~Base() {
	cout << "Base destructor!" << endl;
}

class Derived : public Base {
public:
	Derived();
	~Derived();

private:
	int *p;
};

Derived::Derived() {
	p = new int(0);
}

Derived::~Derived() {
	cout << "Derived destructor!" << endl;
	delete p;
}

void func(Base *b) {
	delete b;
}


int main()
{
	Base *b = new Derived();
	func(b);   //Base类析构函数为非虚函数时，调用~Base()，
	           //当~Base()为虚函数时，调用~Derived()，实现多态

    return 0;
}

