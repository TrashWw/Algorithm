//#pragma once


/***
1.递归的实现：循环的交换，并递归，还原。
2.字典排序
3.全排列的优化问题
4.八皇后问题


***/

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//void sort(vector<char>in, int index) {
//	auto it = in.begin();
//	advance(it, index);
//	sort(it, in.end());
//	int size = in.size();
//	if (index >= size) {
//		for (auto c : in)
//			cout << c;
//		cout << "\n";
//		return;
//	}
//	else {
//		for (int i = index; i<size; ++i) {
//			swap(in[i], in[index]);
//			sort(in, index + 1);
//			swap(in[i], in[index]);
//		}
//	}
//
//
//}
//
//int main() {
//	vector<char>input;
//	char c;
//	c = cin.peek();
//	while (c != '\n'&&c != ' ') {
//		cin.get(c);
//		input.push_back(c);
//		c = cin.peek();
//	}
//	//for(auto c:input)
//	//    cout<<c;
//	sort(input.begin(), input.end());
//	sort(input, 0);
//}