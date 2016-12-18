#include <iostream>
using namespace std;

class A {
public:
	A() {}
	~A() { cout << "~A"<<endl; }
};

int main (){
	int a = 0;
	cin >> a;
	A *ar = new A[a] ;
	delete[] ar;
	return 0;
}
