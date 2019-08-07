#pragma once
#include "stdfx.h"
#include  <unordered_map>

namespace Solution {
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		if (nums.size() == 0)
			return ans;
		sort(nums.begin(), nums.end());
		vector<int>::iterator low ;
		vector<int>::iterator high;
		int size = nums.size();
		for (vector<int>::iterator it = nums.begin(); *it<0; ++it) {
			if (it != nums.begin() && *it == *(it - 1))
				continue;
			low = nums.begin();
			high = nums.end() - 1;
			while (low<high) {
				if ((*low + *high) == -*it) {
					if (it != low&&it != high) {
						vector<int>ans_{ *it,*low,*high };
						ans.push_back(ans_);
						++low;
						--high;
						continue;
					}
					++low;
					
				}
				else if ((*low + *high)>-*it) {
					--high;
				}
				else {
					++low;
				}

			}
		}
		return ans;
	}


	void test() {
		vector<int> t{ -4,-2,-1 };
		vector<vector<int>>an =threeSum(t);
	
	}
};