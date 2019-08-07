#pragma once
namespace beatyOfNumber {
	int Count(int i) {
		int  count = 0;
		while (i) {
			if (i % 2 == 1)
				++count;
			i /= 2;
		}
		return count;
	}

	int Count1(int i) {
		int count = 0;
		int mask = 1;
		while (mask) {
			if (mask&i)
				++count;
			mask = mask << 1;
		}
		return count;
	}

	int Count2(int i) {
		int count = 0;
		while (i) {
			i = i&(i - 1);
			++count;
		}
		return count;
	}
}