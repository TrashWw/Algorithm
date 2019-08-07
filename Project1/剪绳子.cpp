/**
*@Author: wr
*@decrible：动态规划的问题与分治法的区别，在于动态规划的子问题之间相互关联。
*@step: 1:构造最优子结构。 2：递归定义最优值 3.自底而上的解决问题 4.求解
*question: 为什么自底而上的解决问题，因为动态规划的子问题相互关联，在递归（自顶而下的解决方法）的过程中会被重复计算。
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
