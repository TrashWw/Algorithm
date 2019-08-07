#pragma once
#include "stdfx.h"

using namespace std;
const int MAX_NUM = 6;

namespace Solution {
	void getAllTimes(int num,int *ans) {
		int *pro[2];
		pro[0] = new int[num*MAX_NUM + 1];
		pro[1] = new int[num * MAX_NUM + 1];

		int size = num * MAX_NUM + 1;
		for (int i = 0; i < size; ++i) {
			pro[0][i] = 0;
			pro[1][i] = 0;
		}

		for (int i = 1; i <= MAX_NUM; ++i)
			pro[0][i] =1;

		int flag = 0;
		for (int i = 2; i <= num;++i) {
			for (int k = 0; k < i; ++k)
				pro[1 - flag][k] = 0;    //去除因为骰子增加而达不到的值
			int size_ = i * MAX_NUM;
			for (int k = i; k <= size_; ++k) {
				pro[1 - flag][k] = 0;
				for (int j = 1; k > j&&j <= MAX_NUM; ++j) {
					pro[1 - flag][k] += pro[flag][k - j];
				}
			}
			flag = 1 - flag;
		}
		ans = pro[flag];
		for (int i = num; i < size; ++i)
			cout <<i<<":"<<ans[i]<<" ,";
		delete[] pro[1 - flag];
	}

}