#include <iostream>
using namespace std;

int native_str_match(char S[], char P[]) {
	int s = strlen(S);
	int p = strlen(P);
	int i = 0, j = 0;

	while (i < s && j < p) {

		if (S[i] == P[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == p) {
		return i - p;
	}
	return -1;
}

int main() {
	char s[] = "youaremydear";
	char p[] = "are";
	cout << native_str_match(s, p);

}