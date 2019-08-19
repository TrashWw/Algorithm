#pragma once
#include "stdfx.h"
class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == NULL || str == NULL || rows<1 || cols<1)
			return false;

		vector<bool>hasRcv(rows*cols, false);
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j) {
				if (hasPath_(matrix, rows, cols, i, j, 0, str, hasRcv)) {
					return true;
				}
			}
		return false;
	}

	bool hasPath_(const char* matrix, const int rows, const int cols, int row, int col, int len, const char *const str, vector<bool>& hasRcv) {
		if (str[len] == '\0')
			return true;

		bool haspath = false;
		if (row >= 0 && row<rows&&col >= 0 && col<cols && !hasRcv[row*cols + col] && matrix[row*cols + col] == str[len]) {
			++len;
			hasRcv[row*cols + col] = true;

			haspath = hasPath_(matrix, rows, cols, row + 1, col, len, str, hasRcv) ||
				hasPath_(matrix, rows, cols, row, col + 1, len, str, hasRcv) ||
				hasPath_(matrix, rows, cols, row - 1, col, len, str, hasRcv) ||
				hasPath_(matrix, rows, cols, row, col - 1, len, str, hasRcv);

			if (!haspath) {
				--len;
				hasRcv[row*cols + col] = false;
			}
		}
		return haspath;

	}


};