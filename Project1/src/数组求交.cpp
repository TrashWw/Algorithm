/*
*@Describle: Median of two sorted array
*
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

void getdiff(vector<int> num1, vector<int> num2) {
	int pos1 = 0, pos2 = 0;
	while (pos1<num1.size() && pos2<num2.size()) {
		if (num1[pos1] <= num2[pos2]) {
			cout << num1[pos1] << " ";
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
		cout << num2[pos2]<<" ";
		pos2++;
	}
}

int b_s(vector<int>num1,vector<int>num2) {
	int pos1 = num1.size() / 2;
	int pos2 = num2.size() / 2;
	int index1, index2;
	if (num1[pos1]>num2[pos2]) {
		if (num1[pos1]-1>num2[pos2+1]) {
			index1 = 
		}
	}
}


int main() {
	vector<int> num1;
	int size1;
	cout << "Please input array1 length and it" << endl;
	cin >> size1;
	int num;
	for (int i = 0; i < size1; i++) {
		cin >> num;
		num1.push_back(num);
	}

	int size2;
	vector<int> num2;

	cout << "Please input array2 length and it" << endl;
	cin >> size2;
	for (int i = 0; i < size2; i++) {
		cin >> num;
		num2.push_back(num);
	}
	getdiff(num1, num2);
	system("pause");
	return 0;
}