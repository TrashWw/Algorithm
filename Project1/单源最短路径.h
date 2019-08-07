#pragma once

/**
*@Author:wr
*@describe: ��Դ���·�����ʵ��
**/
#include "Graph.h"
#include <queue>
namespace Graph {

	/**
	*BELLMAN_FORD��������
	*1.��ʼ��
	*2.�ɳ�
	*3.����Ƿ����ɳڣ�����Ǵ��ڸ���
	**/
	bool BELLMAN_FORD(Graph_S G,int src,vector<int>&dist) {
		int size = G.size();//ͼ�Ķ�����

		/**1.��ʼ��**/
		dist.swap(vector<int>(size,INT_MAX));
		dist[src] = 0;

		/**2.�ɳ�**/
		while (--size > 0) {
			for (int i = 0; i < size; ++i) {
				auto it = G[i].begin();
				for (; it != G[i].end(); ++it) {
					dist[(*it).first] = min(dist[(*it).first], dist[i] + (*it).second);
				}
			}
		
		}
		

		/**3.����**/
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
	*dijkstra�Ĳ��裺
	*1.��ʼ��
	*2.����S�еĵ��ʾ�Ѿ�ʹ�õĵ㣬ѡ�������С��
	*dijkstra ��Ϊһ��̰���㷨���临�Ӷ�O(v^2),����ϡ�������ԣ�������Ӷ�̫��
	*����û��BELLMAN_FORD�ĸ��Ӷȵͣ�ͨ��ʹ�����ȼ����н��͸��Ӷȵ�O((v+e)lgv)
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
		//��ʼ��
		dist.swap(vector<int>(size,INT_MAX));
		dist[src] = 0;

		//ͨ�����ȼ����б����̽��㣬���ݾ������������ȼ�
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