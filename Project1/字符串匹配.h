#pragma once
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
#ifndef STR_MATCH
#define STR_MATCH



namespace STR_M {

	/*
	@decrible:下面这个功能是实现简单版的RABIN-KARP算法（二进制）
	*/
	bool RABIN_KARP_NIUKE(std::vector<int>str,std::vector<int>pattern) {
		int m_len = pattern.size();
		int n_len = str.size();
		int pattern_value = 0;
		int str_value = 0;
		if (n_len < m_len)
			return false;
		for (int i = 0; i < m_len; ++i) {
			pattern_value = 2 * pattern_value + pattern[i];
			str_value = 2 * pattern_value + str[i];
		}


		int len = n_len - m_len + 1;
		for (int j = 0; j < len; ++j) {
			if (str_value == pattern_value)
				return true;
			
		}
	
	}



	/*
	有限自动机解法
	
	
	*/
	namespace AutoMation_Matcher {

		bool Match_prefix(string pattern,int i,int k,char str) {
			if (k == 0)
				return true;
			if (k == 1)
				return pattern[0] == str;
			string sub = pattern.substr(0, k - 1);
			return str == pattern[k - 1] && !pattern.compare(i -k + 1 ,k-1, sub);
		}
	
		vector<map<char, int>> Compute_Transformation_Funtion(string pattern, string E) {
			int p_len = pattern.size();
			int E_len = E.size();
			vector<map<char,int>>delta(p_len+1);
			for (int i = 0; i <= p_len; ++i) {
				for (int j = 0; j < E_len; ++j) {
					int k = min(p_len, i + 1);
					while (!Match_prefix(pattern,i,k,E[j])) {
						k -= 1;
					}
					delta[i][E[j]] = k;
				}
			}
			
			return delta;
		}
	

		bool Finite_AutoMoto_Matcher(string S,string P,vector<map<char,int>>trans) {
			int s_len = S.size();
			int p_len = P.size();
			int state = 0;
			for (int i = 0; i < s_len; ++i) {
				state = trans[state][S[i]];
			}
			if (state == p_len)
				return true;
			return false;
		}



		void test_Compute_Transformation() {
			string pattern = "ababaca";
			string E = "abc";
			string s = "afsfsadfadsfasdababaca";
			vector<map<char, int>> test = Compute_Transformation_Funtion(pattern, E);
			bool te = Finite_AutoMoto_Matcher(s,pattern,test);
		}
	
	}

}

#endif // !STR_MATCH
