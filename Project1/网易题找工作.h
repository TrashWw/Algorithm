//#pragma once
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <map>
//using namespace std;
//
//bool cmp(pair<int, int> i, pair<int, int> j) {
//	return i.first<j.first;
//}
//
//int main() {
//	int workNum = 0;
//	int guys = 0;
//	cin >> workNum;
//	cin >> guys;
//	vector<pair<int, int>>earn;
//	vector<int> strength;
//	map<int, int>earn_s;
//	int v0;
//	int v1;
//	for (int i = 0; i < workNum; ++i) {
//		cin >> v0;
//		cin >> v1;
//		earn.push_back({ v0,v1 });
//	}
//	for (int i = 0; i < guys; ++i) {
//		cin >> v0;
//		strength.push_back(v0);
//	}
//	sort(earn.begin(), earn.end(), cmp);
//	int max_ = 0;
//
//	for (int i = 0; i < workNum; ++i) {
//		max_ = max(max_, earn[i].second);
//		earn_s[earn[i].first] = max_;
//	}
//
//	map<int, int>::iterator it;
//	for (int i = 0; i < guys; ++i) {
//		it = earn_s.lower_bound(strength[i]);
//		cout << it->second;
//	}
//	return 0;
//}