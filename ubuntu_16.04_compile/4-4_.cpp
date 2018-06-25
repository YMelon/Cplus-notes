//类的组合

#include <iostream>
#include <cmath>
using namespace std;

class Point{
private:
    int x, y;

public:
    Point(int xx=0, int yy=0)
	:x(xx), y(yy) {}
    Point(Point &p);
    ~Point();
    int getX() { return x; }
    int getY() { return y; }
};

Point::Point(Point &p)
    :x(p.x), y(p.y){
    cout << "Calling the copy construtor!" << endl;
}

Point::~Point() {
    cout << "Calling the destructor of Point!" << endl;
}
class Line {
private:
    Point p1, p2;
    double len;

public:
    Line(Point p1, Point p2);
    Line(Line &l);
    ~Line();
    double getLen() { return len; }
};


Line::Line(Point p1, Point p2)
    :p1(p1), p2(p2) {
    double x = static_cast<double>(p1.getX()-p2.getX() );
    double y = static_cast<double>(p1.getY()-p2.getY() );
    len = sqrt(x*x + y*y);
}

Line::Line(Line &l)
    :p1(l.p1), p2(l.p2), len(l.len) {
    cout << "Calling the copy constructor of Line!" << endl;
}

Line::~Line() {
    cout << "Calling the destructor of Line!" << endl;
}
int main() {
    /*演示类的组合，构造函数调用顺序
    Point p1(1,1), p2(4,5);
    Line line(p1, p2);
    Line line2(line);

    cout << "The length of line is: ";
    cout << line.getLen() << endl;
    cout << "The length of line2 is: ";
    cout << line2.getLen() << endl;
    */

    //演示组合类析构函数执行顺序,分析每次析构函数调用对应的对象
    Point p1(1,1), p2(4,5);
    Line line(p1,p2);
    return 0;
}
