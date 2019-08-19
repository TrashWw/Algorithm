#pragma once
#include "stdfx.h"
#include <algorithm>
class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false

	int count_if(int numbers[], int length, int left, int right) {
		int count = 0;
		for (int i = 0; i < length; ++i) {
			if (numbers[i] >= left&&numbers[i] <= right)
				++count;
		}
		return count;
	}
	bool duplicate(int numbers[], int length, int* duplication) {
		int left = 0; int right = length - 1;

		while (left<right) {
			int mid = (left + right) >> 1;
			int count_ = count_if(numbers, length, left, mid);
			if (count_>(mid - left + 1))
				right = mid;
			else
				left = mid + 1;
		}
		if (count_if(numbers, length, left, right)>1) {
			*duplication = left;
			return true;
		}
		return false;
	}
};