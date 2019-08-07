#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string findlongest(const string &s) {
	int maxsize = 0;
	int len = s.size();
	int maxposL = 0;
	int maxposR = 0;
	for (int i = 0; i < len;i++) {
		int posL = i - 1;
		int posR = i + 1;
		int len_ = 1;		
		if (s[i] == s[posR]) {
			posR++;
			len_++;
			while (posL >= 0 && posR < len) {
				if (s[posL] == s[posR]) posL--, posR++, len_ += 2;
				else break;
			}
		}		
		if(len_>maxsize) {
			maxsize = max(len_, maxsize);
			maxposL = posL + 1;
			maxposR = posR;
		}
		posL = i - 1;
		posR = i + 1;
		len_ = 1;
		while (posL >= 0 && posR < len) {
			if (s[posL] == s[posR]) posL--, posR++, len_ += 2;
			else break;
		}
		if (len_>maxsize) {
			maxsize = max(len_, maxsize);
			maxposL = posL + 1;
			maxposR = posR;
		}
	}
	string t(s, maxposL, maxposR- maxposL);
	return t;
}

int main() {
	/***
	*通过中心判别，O(n^2)
	*/

	string a = findlongest("cccc");
	return 0;
}