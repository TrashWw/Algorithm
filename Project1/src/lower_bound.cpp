#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void main() {
	vector<int> test{0,1,5,7,8,9};
	auto t = lower_bound(test.begin(),test.end(),7);
}
