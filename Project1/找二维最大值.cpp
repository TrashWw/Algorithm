#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sort_x_y(pair<int, int>a, pair<int, int>b) {
	return a > b;
}

int main() {
	
	vector<pair<int, int>> v;
	int x;
	int y;
	int size;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> x;
		cin >> y;
		pair<int, int> test(x, y);
		v.push_back(test);
	}

	sort(v.begin(),v.end(),sort_x_y);
	//cout << v[0].first<<" "<< v[0].second<<endl;
	pair<int, int>cmp(v[0].first,v[0].second);
	vector<pair<int, int>> v1;
	for (auto i:v) {
		if (i.second > cmp.second){
			cmp.first = i.first;
			cmp.second = i.second;
			
			v1.push_back(cmp);
		}
			
	}
	v1.push_back(v[0]);
	for (auto j : v1) {
		cout << j.first << " " << j.second << endl;
	}
	return 0;
}