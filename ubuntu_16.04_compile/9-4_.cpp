//数组模板类Array.h的应用

#include <iostream>
#include "Array.h"
using namespace std;


int main() {
    Array<int> a(10);
    int count = 0;

    int n;
    cout << "Enter a value>=2 as upper limit for prime numbers: ";
    cin >> n;
    
    for(int i = 2; i <= n; i ++) {
        bool isPrime = true;
	//检查i能否被比他小的质数整除
	for(int j=0; j<count; j++) {
	    if(i % a[j] == 0){
		isPrime = false;
		break;
	    }
	}
    //把i写入质数表中
	if(isPrime){
	    //若质数表满了，将其空间加倍
	    if(count == a.getSize()){
		a.resize(count*2);
	    }
	    a[count++] = i;
	}
    }
    
    //输出质数
    for(int i=0; i<count; i++){
	cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
