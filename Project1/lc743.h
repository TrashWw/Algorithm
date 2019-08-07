#pragma once
#include "stdfx.h"
#include <deque>
class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		int size = times.size();
		if (size = 0)
			return -1;
		vector<int>dist(size, INT_MAX);
		deque<int>que;
		que.push_back(N - 1);
		dist[N - 1] = 0;
		while (!que.empty()) {
			auto now = que.front();
			que.pop_front();
			for (int i = 0; i < size; ++i) {
				if (times[now][i]>0) {
					dist[i] = min(dist[i], dist[now] + times[now][i]);
					que.push_back(i);
				}

			}
		}
		return dist[K - 1];
	}
};