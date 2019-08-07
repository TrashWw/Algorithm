#pragma once
#include "stdfx.h"
#include <stack>
#include <vector>

bool cmp(pair<char,int>a,pair<char,int>b) {
	return a.second < b.second;
}

class solution {
public:

	int static longestValidParentheses(string s) {
		int maxMatch = 0;
		int recentMatch = 0;
		int len = s.size();
		int index = 0;
		stack<int> t;
		vector<int> ans;
		for (int i = 0; i < len; ++i) {
			if (s[i] == '(') {
				t.push(index);
				++index;
			}
			else {
				if (!t.empty()) {
					ans.push_back(t.top());
					t.pop();
				}
				else {
					++index;
				}
			}
			
		}
		sort(ans.begin(), ans.end());
		int lens = ans.size();
		for (int j = 0; j < lens; ++j) {
			if (recentMatch == 0) {
				recentMatch = 1;
			}
			else {
				if (ans[j] == ans[j - 1]+1) {
					++recentMatch;
				}
				else {
					
					maxMatch = max(recentMatch, maxMatch);
					recentMatch = 1;
				}
			}
		}
		maxMatch = max(recentMatch, maxMatch);
		return maxMatch;
	}

	int static longestValidParentheses2(string s) {
	
	}

};