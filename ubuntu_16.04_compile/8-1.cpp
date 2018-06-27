//运算符重载为成员函数，双目运算符
//重载为非成员函数

#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r=0, double i=0)
	:real(r), imag(i) { }
    /*重载为成员函数
    Complex operator+(const Complex &c) const;
    Complex operator-(const Complex &c) const;
    void display() const;
    */

    //重载为非成员函数
    friend Complex operator+(const Complex &c1, const Complex &c2);
    friend Complex operator-(const Complex &c1, const Complex &c2);
    friend ostream &operator<<(ostream &out, const Complex &c2);
};
/*
Complex Complex::operator+(const Complex &c) const {
    return Complex(real+c.real, imag+c.imag);
}

Complex Complex::operator-(const Complex &c) const {
    return Complex(real-c.real, imag-c.imag);
}

void Complex::display() const {
    cout << "(" << real << ", " << imag << ")" << endl;
}
*/


Complex operator+(const Complex &c1, const Complex &c2) {
    return Complex(c1.real+c2.real, c1.imag+c2.imag);
}
Complex operator-(const Complex &c1, const Complex &c2) {
    return Complex(c1.real-c2.real, c1.imag-c2.imag);
}
ostream &operator<<(ostream &out, const Complex &c) {
    out << "(" << c.real << ", " << c.imag << ")" << endl;
}


int main() {
    /*
    Complex c1(5,4), c2(2, 10), c3;
    cout << "c1= "; c1.display();
    cout << "c2= "; c2.display();

    c3 = c1 - c2;
    cout << "c3=c1-c2= "; c3.display();
    c3 = c1 + c2;
    cout << "c3=c1+c2= "; c3.display();
    */

    Complex c1(5,4), c2(2, 10), c3;
    cout << "c1= " << c1 << endl;
    cout << "c2= " << c2 << endl;

    c3 = c1 - c2;
    cout << "c3=c1-c2= " << c3 << endl;
    c3 = c1 + c2;
    cout << "c3=c1+c2= " << c3 << endl;

    return 0;
}
