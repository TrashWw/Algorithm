#include <iostream>
#include <math.h>
using namespace std;

int isPrimeNumber(int Num) {
	if (Num == 2) {
		return Num;
	}
	for (int i = 2; i < sqrt(Num)+1; i++) {
		if (Num % i == 0) {
			return 0;
		}
	}
	return Num;
}

void print(int Pn, int Pm) {
	int index = 0, posNum = 2;
	while (index < Pm) {
		if (isPrimeNumber(posNum) == posNum) {
			index++;
			if (index >= Pn&&index <= Pm) {
				if ((index - Pn + 1) % 10 != 0) {
					cout << posNum << " ";
				}
				if ((index - Pn + 1) % 10 == 0) {
					cout << posNum << endl;
				}
			}
		}
		posNum++;
	}
}
int main() {
	int n, m;
	cin >> n;
	cin >> m;
	print(n, m);
	return 0;
}
