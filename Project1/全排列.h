//#pragma once


/***
1.�ݹ��ʵ�֣�ѭ���Ľ��������ݹ飬��ԭ��
2.�ֵ�����
3.ȫ���е��Ż�����
4.�˻ʺ�����


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