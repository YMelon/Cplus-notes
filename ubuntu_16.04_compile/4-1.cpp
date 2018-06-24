//构造函数例子程序

#include <iostream>
using namespace std;

class Clock{
private:
    int hour;
    int minute;
    int second;

public:
    Clock(int h, int m=0, int s=0)
      :hour(h), minute(m), second(s) {}
    void setTime(int h, int m, int s);
    void showTime() const;
};


void Clock::setTime(int h, int m, int s){
    hour = h;
    minute = m;
    second = s;
}

void Clock::showTime() const{
    cout << hour << ":" << minute << ":"
          << second << endl;
}


int main(){
    Clock c1 = 11;     //与Clock c1(11);相同
    Clock c2(11, 01, 35);
    
    cout << "Clock c1's time: ";
    c1.showTime();
    cout << "Clock c2's time: ";
    c2.showTime();

    cout << "After setTime: " << endl;
    c1.setTime(11, 04, 25);
    cout << "Clock c1's time: ";
    c1.showTime();
    c2.setTime(11, 05, 1);
    cout << "Clock c2's time: ";
    c2.showTime();

    return 0;
}
