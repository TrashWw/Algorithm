#pragma once
#include "stdfx.h"
#include <unordered_set>
class Solution {
public:
	const char* sercret[26] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };


	int uniqueMorseRepresentations(vector<string>& words) {
		unordered_set<string>ans;
		int index = 0;
		for (auto word : words) {
			string s;
			for (auto c : word) {
				s += sercret[c - 'a'];
			}
			ans.insert(s);
		}
		return ans.size();

	}
};