/**
*@Author: wr
*@decrible����̬�滮����������η����������ڶ�̬�滮��������֮���໥������
*@step: 1:���������ӽṹ�� 2���ݹ鶨������ֵ 3.�Ե׶��ϵĽ������ 4.���
*question: Ϊʲô�Ե׶��ϵĽ�����⣬��Ϊ��̬�滮���������໥�������ڵݹ飨�Զ����µĽ���������Ĺ����лᱻ�ظ����㡣
*/

#include <iostream>
#include <algorithm>
using namespace std;

int maxCut(int length) {
	if (length < 2) return 0;
	if (length == 2) return 1;
	if (length == 3) return 2;


	int * p = new int[length+1];

	p[0] = 0;
	p[1] = 1;
	p[2] = 2;
	p[3] = 3;
	int max = 0;
	for (int i = 4; i <= length; i++) {
		
		for (int j = 1; j <= i / 2; j++) {
			int p_i = p[j] * p[i - j];
			max = std::max(p_i, max);
		}
		p[i] = max;
	}
	max = p[length];
	delete [] p;
	return max;

}


int main() {

	cout<<maxCut(8);

	return 0;

}
