#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;


/**
*定义比较
*/
bool cmp(string  str1, string str2) {


	int i = 0;
	int j = 0;
	while (i < str1.size() || j < str2.size()) {
		if (i == str1.size()) {
			int index = 0;
			while (index < str2.size()) {
				if (str2[index] > str2[j%str2.size()])
					return true;
				else if (str2[index] < str2[j%str2.size()]) { return false; }
					
				j++;
				index++;
			}
			return true;
		}
		if (j == str2.size()) {
			int index = 0;
			while (index < str1.size()) {
				if (str1[index] > str1[i%str1.size()]) {
					return false;
				}
				else if(str1[index] < str1[i%str1.size()]){
					return true;
				}
					
				i++;
				index++;
			}
			return true;
		}
		if (str1[i] > str2[j]) {
			return true;
		}
		else if (str1[i] < str2[j]) {
			return false;
		}
		i++;
		j++;
	}
	return false;
}

string s(int i) {
	return to_string(i);
}

void main() {
	
	vector<int> test{3,30,34,5,9};
	vector<string> test1;
	test1.resize(test.size());
	transform(test.begin(),test.end(),test1.begin(),s);
	sort(test1.begin(),test1.end(),cmp);
	string t;
	for (int i = 0; i < test1.size();i++) {
		t += test1[i];
	}
	cout << t;
}
