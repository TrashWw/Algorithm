#pragma once
#include<string>
#include <vector>
using namespace std; //命名空间的作用？

bool isMatch(string s, string p) {
	int size_s = s.size();
	int size_p = p.size();
	if (size_s == 0 || size_p == 0)
		return false;
	vector<vector<bool>>m(size_s, vector<bool>(size_p, false));
	for (int j = 0; j < size_p;) {
		int hasget = false;
		if (j + 1<size_p&&p[j + 1] == '*') {
			m[0][j] = (s[0] == p[j] || p[j] == '.')&&(j>=1&&m[0][j-1]||j>=2&&p[j-1]=='*'&&m[0][j - 2]);
			j += 2;
		}
		else {
			if (hasget)
				break;
			m[0][j] = (s[0] == p[j] || p[j] == '.')&&!((j >= 1 && m[0][j - 1] || j >= 2 && p[j - 1] == '*'&&m[0][j - 2]));
			hasget = true;
			++j;
		}
	}
	if (size_s == 0 || size_p)


		for (int i = 1; i < size_s; ++i)
			for (int j = 0; j < size_p; ++j) {
				if (j + 1<size_p&&p[j + 1] == '*') {
					m[i][j] = ((s[i] == p[j] || p[j] == '.') && (m[i - 1][j])) || (j - 1 >= 0 && m[i][j - 1] || j - 2 >= 0 && m[i][j - 2]);
				}
				else if (p[j] != '*') {
					m[i][j] = (s[i] == p[j] || p[j] == '.') && (j - 1 >= 0 && m[i - 1][j - 1] || j - 2>0 && p[j - 1] == '*'&& m[i - 1][j - 2]);
				}
			}
	return m[size_s - 1][size_p - 1] || p[size_p - 1] == '*'&&m[size_s - 1][size_p - 2];
}