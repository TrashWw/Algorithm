#pragma once
#include "stdfx.h"

class Queen {
public:
	int a[9] = { 0 };
	int count = 1;
	bool  check(int *a, int pos) {
		for (int i = 1; i < pos; ++i) {
			if (a[i] == a[pos] || abs(a[i] - a[pos]) == abs(i - pos))
				return false;
		}

			

		return true;
	}

	void Queen8(int pos) {
		if (pos > 8) {
			cout << count++<<":";
			for (int i = 1; i <= 8; ++i)
				cout << a[i];
			cout << "\n";
			return;
		}
		for (int i = 1; i <= 8; ++i) {
			a[pos] = i;
			if (check(a, pos)) {
				Queen8(pos+1);
			}
		}
	}


	void Queen8_() {
		int a[9] = { 0 };
		int pos = 1;
		while (pos < 9) {
			int i = 1;
			while (i < 9) {
				a[pos] = i;
				
			}
		}
	}
};