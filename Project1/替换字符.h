#pragma once
#include "stdfx.h"
#include <string>
class Solution {
public:
	void replaceSpace(char *str, int length) {
		char *pos = str;
		int len_space = 0;
		while (*pos != '\0') {
			if (*pos == ' ')
				++len_space;
			++pos;
		}
		len_space = len_space * 2 + length;
		str[len_space--] = '\0';
		for (int i = length - 1; i >= 0; --i) {
			if(str[i]!=' ')
				str[len_space--] = str[i];
			else {
				str[len_space--] = '0';
				str[len_space--] = '2';
				str[len_space--] = '%';
			}
				
		}
	}
};