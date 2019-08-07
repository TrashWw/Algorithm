#include <iostream>
#include <cstddef> 
#include <typeinfo>

using namespace std;

int main() {

	int a = -2;
	//unsigned int b = 3;
	float b = 0.1;
	int c = a + b;
	cout << typeid(a + b).name() << a + b<<endl;
	cout << typeid(b + a).name() << b + a<<endl;
	cout << typeid(c).name() <<c << endl;
	return 0;
}