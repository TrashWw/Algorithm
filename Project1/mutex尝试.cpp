#include <mutex>
#include <thread>
#include <stdarg.h>
#include <iostream>
#include <chrono>   
using namespace std;
mutex te_mutex;

void test(int *t) {
	while (1){
		te_mutex.lock();
		(*t) += 1;
		cout << (*t) << endl;
		te_mutex.unlock();
	}
	
}

int main() {
	int z =0 ;
	thread test0(test,&z);
	thread test1(test, &z);
	test0.detach();
	test1.detach();
	this_thread::sleep_for(chrono::seconds(1));
	return 0;
}