#include <iostream>

using namespace std;

template<class T>
int* getNext(T *array, int length) {
	int *next = (int*)malloc(sizeof(int)*length);
	int k = -1;
	next[0] = -1;
	for (int p = 1; p < length; p++) {
		while (k >= 0 && array[k + 1] != array[p]) {
			k = next[k];
		}
		if (array[k + 1] == array[p])
			k = k + 1;
		next[p] = k;
	}
	return next;
}

int main() {
	char a[5] = {'a','b','a','b','c'};
	int * t=getNext(a, 5);
	for (int i = 0; i < 5; i++) {
		cout << t[i];
	}
	return 0;
}
