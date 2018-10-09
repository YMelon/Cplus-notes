#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
public:
    void input(){
	cin >> name >> age >> id >> avg1 >> avg2 >> avg3 >> avg4;
    }
    void calculate() {
        avg = (float)(avg1 + avg2 + avg3 + avg4) / 4;
    }
    void output() { 
        cout << name << "," << age << "," << id << "," <<avg << endl;
    }

private:
    string name;
        int age;
	    int id;
	        int avg1, avg2, avg3, avg4;
		    float avg;
};

int main() {
    Student student;        // 定义类的对象
	student.input();        // 输入数据
	    student.calculate();    // 计算平均成绩
		student.output();       // 输出数据
		}
