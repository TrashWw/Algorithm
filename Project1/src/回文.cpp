#include <string>
#include<cctype>
using namespace std;


	bool isPalindrome(string s) {
		int low = 0;
		int high = s.length() - 1;
		char c ='c';
		while (low < high) {
			bool c = !isalpha(s[low]);
			bool a = s[low] < 48;
			bool d = s[low] >57;
			if (!isalpha(s[low]) && (s[low]<48 || s[low]>57)) {
				low++;
				continue;
			}
			if (!isalpha(s[high]) && s[high]<48 && s[high]>57) {
				high--;
				continue;
			}
			if (s[low] == s[high] || s[low] - 32 == s[high] || s[low] + 32 == s[high]) {
				low++;
				high--;
			}
			else {
				return false;
			}
		}

		return true;
	}

	void main() {
		string s = "0P";
		isPalindrome(s);
	
	}
