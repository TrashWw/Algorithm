#pragma once
#include "stdfx.h"
#include <string>
class Solution {
public:
	void Next(string &p, vector<int>&next) {
		int size = next.size();
		int j = 0;
		int k = -1;
		next[0] = -1;
		while (j<size-1) {
			if (k == -1 || p[j] == p[k]) {
				++k;
				++j;
				next[j] = k;
			}
			else {
				k = next[k];
			}
		}
	}

	int strStr(string haystack, string needle) {
		int size = needle.size();
		vector<int> next(size, 0);
		Next(needle, next);
		int i = 0;
		int j = 0;
		int sizeS = haystack.size();
		while (i<sizeS&&j<size) {
			if (j = -1 || haystack[i] == needle[j]) {
				++j;
				++i;
			}
			else {
				j = next[j];
			}
		}
		if (j == size)
			return i - j + 1;
		return -1;
	}
};