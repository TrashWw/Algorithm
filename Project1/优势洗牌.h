#pragma once
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

namespace Solution {
	static bool cmp(int i, int j) {
		return i>j;
	}

	int find_(vector<int>& A,int key) {
		int size = A.size();
		for (int i = 0; i < size; ++i) {
			if (A[i] == key)
				return i;
		}
		return 0;
	}
	vector<int> advantageCount(vector<int>& A, vector<int>& B) {
		vector<int>hash = B;
		int size = A.size();

		if (size == 0)
		{
			vector<int>ans;
			return ans;
		}

		vector<int>ans(size, 0);
		// for(int i =0; i < size; ++i){
		//     hash[B[i]]=i;
		// }

		sort(A.begin(), A.end(), cmp);
		sort(B.begin(), B.end(), cmp);

		auto it = hash.begin();
		int posAlow = 0, posBlow = 0, posAHigh = size - 1, posBHigh = size - 1;
		for (; posAlow <= posAHigh;) {
			if (A[posAlow]>B[posBlow]) {
				it = find(hash.begin(), hash.end(), B[posBlow]);
				ans[*it] = A[posAlow];
				*it = -1;
				++posAlow;
				++posBlow;
			}
			else if (A[posAlow]<B[posBlow]) {
				it = find(hash.begin(), hash.end(), B[posBlow]);
				// it = hash.find(B[posBlow]);
				ans[*it] = A[posAHigh];
				*it = -1;
				--posAHigh;
				++posBlow;
			}
			else {
				if (A[posAHigh]>B[posBHigh]) {
					it = find(hash.begin(), hash.end(), B[posBHigh]);
					//it = hash.find(B[posBHigh]);
					ans[*it] = A[posAHigh];
					*it = -1;
					--posAHigh;
					--posBHigh;
				}
				else {
					it = find(hash.begin(), hash.end(), B[posBlow]);
					//it = hash.find(B[posBlow]);
					ans[*it] = A[posAHigh];
					*it = -1;
					--posAHigh;
					++posBlow;
				}
			}
		}
		return ans;
	}

	void tes_() {
		vector<int>A{ 5621,1743,5532,3549,9581 };
		vector<int>B{ 913,9787,4121,5039,1481 };
		vector<int>ans = advantageCount(A, B);
	}
};