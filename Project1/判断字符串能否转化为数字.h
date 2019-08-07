#pragma once
#include <string>
using namespace std;

bool isPositive(char s) {
	if (s == '-' || s == '+')
		return true;
	else
		return false;
}

bool isNumber_(char s) {
	if (s >= '0'&&s <= '9')
		return true;
	else
		return false;
}



bool isSpace_(char s) {
	if (s == '\t' || s == '\n' || s == ' ')
		return true;
	else
		return false;
}

bool isNumber1(string s) {
	int size = s.size();
	int beforeMode = -1;  //数字为0.空格为1，点为2，e为3,+-为4
	bool hasSpace = false;
	bool hasPoint = false;
	bool hasE = false;
	bool hasNumber = false;
	bool hasPositive = false;
	int i = 0;
	while (i<size) {
		if (isNumber_(s[i]) && ((beforeMode == 1 && !hasNumber) || beforeMode != 1)) {
			beforeMode = 0;
			hasNumber = true;
			++i;
		}
		else if (isSpace_(s[i]) && beforeMode != 4 && beforeMode != 3 && (!hasNumber&&beforeMode != 2 || hasNumber)) {
			beforeMode = 1;
			hasSpace = true;
			++i;
		}
		else if (s[i] == 'e' && !hasE&&beforeMode != 4 && beforeMode != 1 && hasNumber && (hasNumber || beforeMode != 2 && !hasNumber)) {
			beforeMode = 3;
			hasE = true;
			++i;
		}
		else if (s[i] == '.' && !hasE && !hasPoint&&beforeMode != 3 && ((hasNumber&&beforeMode != 1) || (!hasNumber))) {
			beforeMode = 2;
			hasPoint = true;
			++i;
		}
		else if ((isPositive(s[i]) && !hasNumber&&beforeMode != 2 && !hasPositive&&beforeMode != 3) || beforeMode == 3) {
			hasPositive = true;
			beforeMode = 4;
			++i;
		}
		else
			return false;

	}

	if (hasNumber&&beforeMode != 3 && beforeMode != 4)
		return true;

	return false;

}



bool isNumber(string s) {
	enum INPUT {
		INVIAD,
		NUMBER,
		SPACE,
		DOT,
		SIGN,
		E
	};

	int transform[][6]{
		-1,1,2,4,7,8,   //在无任何输入的情况下的状态转移0
		-1,1,3,10,-1,8,            //无E,dot输入数字1
		-1,1,2,4,1,-1,        //无任何输入下的空格2
		-1,-1,3,-1,-1,-1,       //有数字和符号（.）情况下输入空格后的状态3
		-1,5,-1,-1,-1,-1,                 //无数字输入点后  4        
		-1,5,3,-1,-1,8,   //有.状态输入数字5
		-1,1,-1,-1,-1,-1,               //+-状态6
		-1,9,-1,-1,-1,-1,                 //e后+-7
		-1,9,-1,-1,7,-1,                //e的状态8
		-1,9,3,-1,-1,-1,       //有e后输入数字9
		-1,5,3,-1,-1,8      //有数字输入点的装填10
	};

	int state = 0;
	int i = 0;
	int size = s.size();
	while (i < size) {
		INPUT input = INVIAD;
		if (s[i] >= '0'&&s[i] <= '9') input = NUMBER;
		else if (s[i] == ' ') input = SPACE;
		else if (s[i] == '.') input = DOT;
		else if (s[i] == '+' || s[i] == '-') input = SIGN;
		else if (s[i] == 'e') input = E;
		state = transform[state][input];
		++i;
		if (state == -1)return false;

	}
	return state == 1 || state == 3 || state == 5 || state == 9 || state == 10;
}