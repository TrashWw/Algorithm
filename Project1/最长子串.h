#pragma once
#include <unordered_map>
#include "stdfx.h"
namespace Solution {
	int lengthOfLongestSubstring(string s) {
		int maxSize = 0;
		int current_size = 0;
		int size = s.size();
		int posLast = 0;
		bool hasmeet = false;
		unordered_map<int, int>key;
		if (size == 0)
			return 0;
		for (int i = 0; i < size; ++i) {
			if (!key[(int)s[i]] ||( key[(int)s[i]]-1<posLast)&&hasmeet) {
				key[(int)s[i]] = i + 1;
				++current_size;
				maxSize = max(maxSize, current_size);
			}
			else {
				hasmeet = true;
				posLast = key[(int)s[i]]-1;
				
				current_size = i - key[(int)s[i]] + 1;
				key[(int)s[i]] = i + 1;
			}
		}
		return maxSize;
	}

	void test() {
		int a = lengthOfLongestSubstring("pwwkew");
	}
};