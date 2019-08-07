#pragma once
#include "stdfx.h"
class Solution {
public:
	bool stoneGame(vector<int>& piles) {
		int size = piles.size();
		if (!size)
			return false;
		if (size == 1)
			return true;
		int left = 0;
		int right = 0;
		int l = 0;
		int r = size - 1;
		bool turn = true;
		while (r > l)
		{
			if (turn)
			{
				left += max(piles[l], piles[r]);
			}
			else
			{
				right += max(piles[l], piles[r]);
			}
			if (piles[l] > piles[r])
			{
				l++;
			}
			else
			{
				r--;
			}
			turn = !turn;
		}
		return left > right;

	}
};