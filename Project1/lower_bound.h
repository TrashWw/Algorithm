#pragma once

int lower_bound_(int *array,int key, int len) {
	int low = 0;
	int high = len - 1;
	while (low<high) {
		int mid = (low + high) / 2;
		if (array[mid] >= key)
			high = mid;
		else
			low = mid + 1;
	}
	if (array[low] == key)
		return low;
	else
		return -1;
}



int up_bound(int *array, int key, int len) {
	int low = 0;
	int high = len - 1;
	while (low<high) {
		int mid = (low + high) / 2;
		if (array[mid] > key)
			high = mid;
		else
			low = mid + 1;
	}
	return low;
}