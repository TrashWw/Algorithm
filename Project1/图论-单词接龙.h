#pragma once
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;




class Solution {
public:
	bool static findV(string s0,string s1) {
		int size0 = s0.size();
		int size1 = s1.size();
		if (size0 != size1) {
			return false;
		}
		int diff = 0;
		for (int i = 0; i < size0; ++i) {
			if (s0[i] != s1[i])
				++diff;
			if (diff > 1)
				return false;
		}
		return true;
	}
	int static ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		int size = wordList.size();
		map<string, int> distance;
		
	}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right; 
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};


class Solution1 {
public:
	int static maxPathSum(TreeNode* root) {
		int res = INT_MIN;
		dfs(root, res);
		return res;
	}

	int static dfs(TreeNode* root, int &res) {
		if (!root)
			return 0;
		int l = max(0, dfs(root->left, res));
		int r = max(0, dfs(root->right, res));
		res = max(res, l + r + root->val);
		return max(l, r) + root->val;
	}
};