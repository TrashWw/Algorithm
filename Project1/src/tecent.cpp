#include<iostream>
#include <vector>
using namespace std;
int find(vector<char> s) {
	int length = s.size();
	int last_length = s.size();
	for (int i = 0; i < length;i++) {
		if (i + 1 < length && (s[i] ^ s[i + 1])) {
			last_length -= 2;
			i++;
		}
	}
	return last_length;
}

int main() {
	int m;
	char n;
	vector<char> s;
	cin >> m;
	cin >> n;
	while (m>0) {

		s.push_back(n);
		m--;
		if (m>0) 
		cin >> n;
		
	}
	int a = find(s);
	return 0;
}