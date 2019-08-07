#pragma once
#include <memory>
namespace sort {

	//≤Â»Î≈≈–Ú
	void insert_sort(int a[],const int &len) {
		if (len <= 0)
			return;
		//…˘√˜…⁄±¯
		int key;
		for (int i = 1; i < len; ++i) {
			key = a[i];
			int pos = i - 1;
			while (pos >= 0 && key > a[pos]) {
				a[pos + 1] = a[pos];
				--pos;
			}
			a[pos+1] = key;
		}
	}

	//œ£∂˚≈≈–Ú
	void shell_helper(int a[],int increase,int len) {
		if (len <= 0)
			return;
		int key = 0;
		for (int i = increase; i < len; ++i) {
			key = a[i];
			int pos = i - increase;
			while (pos > 0 && a[pos] > key) {
				a[pos + increase] = a[pos];
				pos -= increase;
			}
			a[pos + increase] = key;
		}
	}
	void shell_sort(int a[],int len) {
		if (len <= 0)
			return;
		for (int i = len / 2; i > 0; i /= 2) {
			shell_helper(a,i,len);
		}
	}
	

	//øÏÀŸ≈≈–Ú
	int patition(int a[],int low,int high) {
		int key = a[low];
		while (low<high) {
			while (low<high&&a[high]>=key) --high;
			a[low] = a[high];
			while (low < high&&a[low] <= key) ++low;
			a[high] = a[low];
		}
		a[low] = key;
		return low;
	}

	void qsort(int a[], int low,int high) {
		if (low < high) {
			int piot = patition(a, low, high);
			qsort(a, low, piot - 1);
			qsort(a, piot + 1, high);
		}
	}

	void quick_sort(int a[], int len) {
		qsort(a, 0, len - 1);
	}



	//∂—≈≈–Ú
	int getLC(int i) {
		return 2 * i + 1;
	}

	int getRC(int i) {
		return 2 * i + 2;
	}

	void heapAdjust(int a[],int i,int len) {
		int key = a[i];
		for (int j = getLC(i); j < len;j = getLC(j)) {
			if (j + 1 < len&&a[j] < a[j + 1]) ++j;
			if (key < a[j]) {
				a[i] = a[j];
				i = j;
			}
			else
				break;
				
		}
		a[i] = key;

	}

	void heap_sort(int a[], int len) {
		for (int i = len / 2-1; i >=0; --i)
			heapAdjust(a,i,len);
		for (int i = len-1; i > 0; --i){
			int temp = a[i];
			a[i] = a[0];
			a[0] = temp;
			heapAdjust(a, 0, i);
		}
	
	
	}

	//πÈ≤¢≈≈–Ú
	void merge(int* a, int low, int mid, int high) {
		int *b = (int*)malloc(sizeof(int)*(high-low+1));

		int i = low, j = mid+1;
		int start = 0;
		while (i <= mid&&j <= high) {
			if (a[i] < a[j])
				b[start++] = a[i++];
			else
				b[start++] = a[j++];				
		}
		while (i <= mid) {
			b[start++] = a[i++];
		}

		while (j <= high) {
			b[start++] = a[j++];
		}

		start = low;
		for (int i = 0; i < high - low+1;++i) {
			a[start++] = b[i];
		}
		free(b);
	}

	void msort(int *a,int low, int high) {
		int mid = (low + high) / 2;
		if (low < high) {
			msort(a, low, mid);
			msort(a, mid + 1, high);
			merge(a,low,mid,high);
		}
	}

	void merge_sort(int *a,int len) {
		msort(a, 0, len - 1);
	}

	void test() {
		int a[] = {2,5,8,6,3,4,8,23,2,14,5};
		//shell_sort(a,11);
		merge_sort(a, 11);
	}

}