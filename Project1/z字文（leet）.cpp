#include<iostream>
#include <string>
using namespace std;

string convert(string s, int numRows) {
	string t;
	int pos = 0;
	int k = 0;
	t.resize(s.size());
	for (int i = 0; i < numRows; i++) {

		while (true) {
			int index1 = (2 * numRows - 2)*k + i;
			int index2 = (2 * numRows - 2)*(k+1) - i;
			if (pos >= s.size())
				break;
			if (index1 < s.size())
				t[pos++] = s[index1];
			else {
				k = 0;
				break;
			}
				
				
			if (index2<s.size()&& index2!=index1+ (2 * numRows - 2) && index2 != index1)
				t[pos++] = s[index2];
			

			k++;
		}

	}
	return t;
}


int main() {
	string t = convert("leetcodeishiring",3);
	return 0;
}