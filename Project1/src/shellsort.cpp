#include <iostream>
using namespace std;

void shell_sort(int *array, int len) {
	int tmp;
	int delta;
	int j;
	for (delta = len / 2; delta > 0; delta /= 2) {
		for (int i = delta; i < len; i++) {
			if (array[i]<array[i - delta]) {
				tmp = array[i];
				for (j = i - delta; j >= 0 && (tmp < array[j]); j -= delta) {
					array[j + delta] = array[j];
				}
				array[j + delta] = tmp;
			}
		}
	}

}

int main() {
	int a[5] = { 3,8,2,4,6 };
	shell_sort(a, 5);
	for (int i = 0; i < 5; i++) {
		cout << a[i];
	}
}
