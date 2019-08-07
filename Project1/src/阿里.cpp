#include<iostream>
#include <vector>
#include<iomanip>
using namespace std;

int main() {
	int N = 0;
	float p;
	cin >> N;
	vector<float>p_N;
	for (int i = 0; i < N; i++) {
		cin >> p;
		p_N.push_back(p);
	}
	float p_getM = 0;
	float p_flase = 1;
	for (int i = 0; i < 100; i++) {
		if (p_N[i%N] == 1) {
			if (i == 0)p_getM = 1;
			break;
		}
		if (i%N == 0) {
			p_getM += p_flase * p_N[i%N];
			p_flase *= (1 - p_N[i%N]);
		}
		else {
			p_flase *= (1 - p_N[i%N]);
		}
	}
	cout << fixed << setprecision(4) << p_getM;
	return 0;
}

