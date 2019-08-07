#include<iostream>
#include<vector>
using namespace std;

void find(vector<int>power, vector<int>money,int pos1,int pos2,int &power_add,int &money_add) {
	for (int i = pos1 + 1;i<=pos2,i++) {
		
	}
}

int Pass(vector<int>power, vector<int>money,int size) {
	int total_money = 0;
	int power_now = 0;
	int last = 0;
	for (int i = 0; i < size; i++) {
		if (power_now<power[i]) {
			total_money += money[i];
			power_now += power[i];
		}
		
	}
	return total_money;
}

int main() {
	int size;
	int n;
	vector<int>power;
	vector<int>money;
	cin >> size;
	for (int i = 0; i < size;i++) {
		cin >> n;
		power.push_back(n);
	}
	for (int i = 0; i < size; i++) {
		cin >> n;
		money.push_back(n);
	}

	int pay = Pass(power,money,size);
	return 0;
}