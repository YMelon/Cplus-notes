//copy constructor example program

#include <iostream>
using namespace std;

class Point{
private:
    int x, y;

public:
    Point(int xx=0, int yy=0)
	:x(xx), y(yy) {}
    Point(Point &p);

    int getX() { return x; }
    int getY() { return y; }
};

Point::Point(Point &p)
    :x(p.x), y(p.y){
    cout << "Calling the copy construtor!" << endl;
}

//形参为Point类对象
void func1(Point p){
    cout << p.getX() << endl;
}

//返回值为Point类对象
Point func2(){
    Point a(1,2);
    return a;
}


int main() {
    Point a(4, 5);
    Point b = a;  //调用复制构造函数
    cout << b.getX() << endl;

    func1(b);    //对象b为函数实参
    
    b = func2(); //函数返回值为类对象
    //g++下没有显示调用复制构造函数，为什么？
    //编译器做了优化，避免不必要的复制构造函数调用
    cout << b.getX() << endl;

    return 0;
}
