#include <iostream>
using namespace std;

void heapAdjust(int *array,int start,int length) {
	int tmp = array[start];
	int child = 2 * start + 1;
	for (; child < length;child = child *2 +1) {
		if (child<length-1&&array[child]<array[child + 1]) {
			child++;
		}
		if (array[child]<=array[start]) {
			break;
		}
		array[start] = array[child];
		start = child;
		array[start] = tmp;
	}
	
}

void heapsort(int *array,int length) {
	for (int i = (length-2) / 2; i >= 0;i--) {
		heapAdjust(array, i, length);
	}
	for (int j = length - 1; j > 0; j--) {
		int t = move(array[j]);
		array[j] = move(array[0]);
		array[0] = move(t);
		heapAdjust(array, 0, j-1);
	}
	
}

int main() {
	int a[] = {2,8,7,6,3,5,8,9,20,7};
	//int a[] = { 2,8,5,6,5,9};
	heapsort(a, 10);
	return 0;
}