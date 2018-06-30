//类模板

#include <iostream>
#include <cstdlib>
using namespace std;

struct Student {
    int id;
    float gpa;
};


template<class T>
class Store {
private:
    T item;
    bool haveValue;

public:
    Store();
    const T &getElem() const;
    void putElem(const T &x);
};

template<class T>
Store<T>::Store()
    :haveValue(false) { }

template<class T>
const T &Store<T>::getElem() const {
    if(!haveValue) { //试图提取为初始化的数据，终止程序
       cout << "No item present!" << endl;
       exit(1);
    }

    return item;
}

template<class T>
void Store<T>::putElem(const T &x) {
    haveValue = true;
    item = x;
}


int main() {
    Store<int> s1, s2;
    s1.putElem(3);
    s2.putElem(-7);
    cout << s1.getElem() << " " << s2.getElem() << endl;


    Student g = {1000, 3.9};
    Store<Student> s3;
    s3.putElem(g);
    cout << "The student id is: " << s3.getElem().id << endl;


    Store<double> d;
    cout << "Retrieving object d...";
    cout << d.getElem() << endl;
    //d未经过初始化，执行getItem()导致程序终止
    return 0;
}
