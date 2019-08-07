#pragma once
#include <iostream>
#include <mutex>
using namespace std;
namespace jianzhioffer {

	class  singleton {
	private:
		singleton();
		static singleton *instance ;

	public:
		static singleton *getInstance() {
			if (instance == NULL) {
				instance =  new singleton();
			}
			return instance;
		}

	};


	class singleton1 {
	private:
		static singleton1 *instance;
		singleton1();

	public:
		static singleton1*getinstance() {
			return instance;
		}
	};
	singleton1 *singleton1::instance = new singleton1();

	class singleton2 {
	private:
		singleton2();
		static singleton2 *instance;
		static mutex lock_;

	public:
		static singleton2* getinstance() {
			if (instance == NULL) {
				lock_.lock();
				instance = new singleton2();
				lock_.unlock();
			}
			return instance;
		}
	};

	
}