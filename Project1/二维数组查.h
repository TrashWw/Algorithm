#pragma once
#include "stdfx.h"
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int size = array.size();
		if (size == 0)
			return false;
		int size1 = array[0].size();
		int left = 0, right = size1;
		int up = 0, down = size;
		int row = 0, col = 0;
		while (left<right || up<down) {
			
			while (left<right) {
				int mid = (left + right)/2;
				if (array[row][mid] == target)
					return true;
				else if (array[up][mid]<target)
					left = mid + 1;
				else
					right = mid;
			}
			
			while (up<down) {
				int mid = (up + down)/2;
				if (array[mid][col] == target)
					return true;
				else if (array[mid][col]<target)
					up = mid + 1;
				else
					down = mid;
			}
			
			++row;
			++col;
			left = col;
			up = row;
		}
		return false;
	}
};