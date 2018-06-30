//数组类模板定义，类似vector功能
#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cassert>

template<class T>
class Array {
private:
    T *list;
    int size;

public:
    Array(int sz=50);
    Array(const Array<T> &a);
    //重载赋值运算符
    Array<T> &operator=(const Array<T> &rhs);
    ~Array();
    
    //重载下标运算符
    T &operator[](int i);
    const T &operator[](int i) const;
    
    //重载到T*类型的转化
    operator T*();
    operator const T*() const;
    
    int getSize() const;
    void resize(int sz);
};

template<class T>
Array<T>::Array(int sz) {
    assert(sz >= 0);  //判定数组大小是否合法，应当非负
    size = sz;
    list = new T[size];
}

template<class T>
Array<T>::Array(const Array<T> &a) {
    size = a.size;
    list = new T[size];
    for(int i = 0; i < size; i ++) {
       list[i] = a.list[i]; 
    }
}

template<class T>
Array<T> &Array<T>::operator=(const Array<T> &rhs) {
    if(&rhs != this) { //避免自身赋值
       if(size != rhs.size) {
	   delete[] list;
	   size = rhs.size;
	   list = new T[size];
       }
       for(int i = 0; i < size; i ++) {
           list[i] = rhs.list[i]; 
       }
    }
    return *this;
}

template<class T>
Array<T>::~Array() {
    delete[] list;
}

template<class T>
T &Array<T>::operator[](int i) {
    assert(i >= 0 && i < size); //检查下标是否越界
    return list[i];    
}

template<class T>
const T &Array<T>::operator[](int i) const {
    assert(i >= 0 && i < size);
    return list[i];
}


template<class T>
Array<T>::operator T*() {
    return list;
}

template<class T>
Array<T>::operator const T*() const {
    return list;
}

template<class T>
int Array<T>::getSize() const {
    return size;
}

template<class T>
void Array<T>::resize(int sz) {
    assert(sz >= 0); //检查是否合法
    if(size != sz) {
        int n = (sz < size) ? sz : size;
	T *newList = new T[sz];
	for(int i = 0; i < n; i ++) {
	    newList[i] = list[i];
	}
	delete[] list;
	size = sz;
	list = newList;
    }
    return;
}

#endif  //_ARRAY_H_

