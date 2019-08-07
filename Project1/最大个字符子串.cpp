/**
*@describle: 每个字符出现k次的最大子串
*/


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int maxSubString(string s,int k) {
	int letter[26] = {0};
	for (char c : s) letter[int(c - 'a')]++;
	bool run = true;
	int max_size = 0;
	int res = 0;

	for (int i = 0; i < s.size(); i++) {
		if (letter[int(s[i] - 'a')] < k) {
			res = max(res, maxSubString(s.substr(max_size,i- max_size),k));
			run = false;
			max_size++;
			break;
		}
	}
	return run ? s.size() : max(res, maxSubString(s.substr(max_size, s.size()-1 - max_size), k));
}



int longSubstr(string s,int k) {
	int i = 0, n = s.size(), res = 0;
	while (i+k<=n) {
		int max_size = i, mask = 0;
		int letter[26] = { 0 };
		for (int j = i; j < n;++j) {
			int t = s[j] - 'a';
			++letter[t];
			if (letter[t] < k) mask |= (1 << t);
			else mask &= (~(1 << t));
			if (mask ==0) {
				res = max(res, j - i+1);
				max_size = i;
			}
		
		}
		i = max_size + 1;
	
	}
	return res;
}
int main() {
	int test = longSubstr("aaabb",3);

	return 0;
}