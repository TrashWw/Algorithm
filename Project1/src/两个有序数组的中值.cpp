#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

void getdiff(vector<int> num1, vector<int> num2) {
	int pos1 = 0, pos2 = 0;
	while (pos1<num1.size() && pos2<num2.size()) {
		if (num1[pos1] <= num2[pos2]) {
			cout << num1[pos1]<<" ";
			pos1++;
		}
		else {
			cout << num2[pos2] << " ";
			pos2++;
		}
	}
	while (pos1<num1.size()) {
		cout << num1[pos1] << " ";
		pos1++;
	}
	while (pos2<num2.size()) {
		cout << num2[pos2] << " ";
		pos2++;
	}
}

int findMedianSortedArrays(vector<int>num1, vector<int>num2) {
	if (num1.size()>num2.size()) {
		return findMedianSortedArrays(num2, num1);
	}
	int key = (num1.size() + num2.size() - 1) / 2;
	int left = 0;
	int right = min((int)num1.size(), key);
	while (left<right) {
		int mid1 = (left + right) / 2;
		int mid2 = key - mid1;
		if (num1[mid1]<num2[mid2]) {
			left = mid1 + 1;
		}
		else {
			right = mid1;
		}
	}

	int odd = max(left>0 ? num1[left - 1] : INT_MIN, key - left >= 0 ? num2[key - left] : INT_MIN);
	if ((num1.size() + num2.size()) % 2 == 1)return odd;

	int even = min(left<num1.size() ? num1[left] : INT_MAX, key - left + 1 < num2.size() ? num2[key - left + 1] : INT_MAX);
	return (odd + even) / 2;
}

int main() {
	vector<int> num1;
	int size1;
	cout << "Please input array1 length and it" << endl;
	cin >> size1;
	int in;
	cin.ignore(256, '\n');
	for (int i = 0; i < size1; i++) {
		cin >> in;
		num1.push_back(in);
	}

	int size2;
	vector<int> num2;

	cout << "Please input array2 length and it" << endl;
	cin >> size2;
	cin.ignore(256, '\n');
	for (int i = 0; i < size2; i++) {
		cin >> in;
		num2.push_back(in);
	}
	getdiff(num1, num2);
	int a = findMedianSortedArrays(num1,num2);
	cout << endl;
	cout << a;
	system("pause");
	return 0;
}