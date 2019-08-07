#include <iostream>
using namespace std;

void main() {
	int pay;
	cin >> pay;
	int num = 0;
	int last = 1024 - pay;
	if (last > 64) {
		num += last / 64;
		last = last % 64;
	}
	if (last > 16) {
		num += last / 16;
		last = last % 16;
	}
	if (last > 4) {
		num += last / 4;
		last = last % 4;
	}
	if (last > 1) {
		num += last / 1;
	}

	cout << num;

}