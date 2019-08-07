#pragma once

/**
*@Author:wr
*@describe: 单源最短路径相关实现
**/
#include "Graph.h"
#include <queue>
namespace Graph {

	/**
	*BELLMAN_FORD三部曲：
	*1.初始化
	*2.松弛
	*3.检查是否还在松弛，如果是存在负环
	**/
	bool BELLMAN_FORD(Graph_S G,int src,vector<int>&dist) {
		int size = G.size();//图的定点数

		/**1.初始化**/
		dist.swap(vector<int>(size,INT_MAX));
		dist[src] = 0;

		/**2.松弛**/
		while (--size > 0) {
			for (int i = 0; i < size; ++i) {
				auto it = G[i].begin();
				for (; it != G[i].end(); ++it) {
					dist[(*it).first] = min(dist[(*it).first], dist[i] + (*it).second);
				}
			}
		
		}
		

		/**3.检验**/
		for (int i = 0; i < size; ++i) {
			auto it = G[i].begin();
			for (; it != G[i].end(); ++it) {
				if(dist[(*it).first]> dist[i] + (*it).second)
					return false;
			}
		}
		return true;
	}

	/**
	*dijkstra的步骤：
	*1.初始化
	*2.集合S中的点表示已经使用的点，选择距离最小的
	*dijkstra 作为一种贪心算法，其复杂度O(v^2),对于稀疏矩阵而言，这个复杂度太大。
	*反而没有BELLMAN_FORD的复杂度低，通过使用优先级队列降低复杂度到O((v+e)lgv)
	**/


	struct node {
		int v;
		int dist;
		node(int v_,int d_):v(v_),dist(d_) {
		}

	};

	class cmp {
	public:
		bool operator()(node i, node j) {
			return i.dist > j.dist;
		}
	};

	void Dijkstra(Graph_S G,int src,vector<int>&dist) {
		int size = G.size();
		vector<bool>hasRec(size,false);
		//初始化
		dist.swap(vector<int>(size,INT_MAX));
		dist[src] = 0;

		//通过优先级队列保存可探测点，根据距离来建立优先级
		priority_queue<node,vector<node>,cmp> Q;
		Q.push(node(src,0));
		while (!Q.empty()) {
			auto n = Q.top();
			Q.pop();
			if (hasRec[n.v])
				continue;
			hasRec[n.v] = true;
			for (auto it : G[n.v]) {
				if (dist[it.first] > dist[n.v] + it.second) {
					dist[it.first] = dist[n.v] + it.second;
					Q.push(node(it.first,it.second));
				}
			}
		}
	}

}