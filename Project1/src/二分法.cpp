#include <iostream>

using namespace std;
int search(int *array, int length, int key) {
	int low = 0, high = length - 1, index = length / 2;

	while (low <= high) {
		if (array[index] == key) {
			return index;
		}
		else if (array[index] > key) {
			high = index - 1;
			index = (high + low) / 2;
		}
		else {
			low = index + 1;
			index = (low + high) / 2;
		}

	}

	return -1;
}

int main() {
	int array[5] = { 1,3,5,8,9 };
	int pos = search(array, 5, -1);
	cout << pos << endl;
	return 0;
}