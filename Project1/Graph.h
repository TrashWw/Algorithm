#pragma once
#include "stdfx.h"

namespace Graph {
	//the definity fo Graph
	typedef vector<list<int>> Graph;
	typedef vector<vector<int>> Graph_V;
	typedef vector<list<pair<int, int>>> Graph_S;
	
	//Edge
	struct Edge {
		int u;
		int v;
		int weight;
		Edge(int u_,int v_,int weight_):u(u_),v(v_),weight(weight_) {
		}
	};
	

}