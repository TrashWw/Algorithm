#pragma once
#include <list>
using namespace std;
class Solution {
public:
	list<int> L;
	int LastRemaining_Solution(int n, int m)
	{
		if (n <= 0 || m <= 0) {
			return 0;
		}
		for (int i = 0; i < n; ++i)
			L.push_back(i);
		int index = 0;
		list<int>::iterator it = L.begin();
		while (true) {
			if (index == m - 1) {
				auto abonded = it;
				++it;
				L.erase(abonded);
				if (L.size() == 1) {
					return L.front();
				}
			}
			else {
				++it;
				++index;
			}
			if (it == L.end())
				it == L.begin();
		}
		return 0;
	}
};