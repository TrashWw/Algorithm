#include <iostream>
using namespace std;
void replaceSpace(char *str, int length) {

	int index = 0;
	for (int i = 0; i < length; i++) {
		if (str[i] == ' ') {
			index++;
		}
	}
	char *s = (char *)malloc(sizeof(char)*(length + index * 3+1));
	memset(s,0, length + index * 3);
	for (int j = 0, c = 0; j < length + index * 3 && c < length; j++, c++) {
		if (str[c] == ' ') {
			s[j++] = '\%';
			s[j++] = '2';
			s[j] = '0';
		}
		else {
			s[j] = str[c];
		}
	}
	memcpy(str,s, length + index * 3 + 1);
}

int main() {
	char  s[] = "h l";
	replaceSpace(s, 3);
}