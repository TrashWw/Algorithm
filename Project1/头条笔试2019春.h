//我叫王大锤，是一家出版社的编辑。我负责校对投稿来的英文稿件，这份工作非常烦人，因为每天都要去修正无数的拼写错误。但是，优秀的人总能在平凡的工作中发现真理。我发现一个发现拼写错误的捷径：
//
//1. 三个同样的字母连在一起，一定是拼写错误，去掉一个的就好啦：比如 helllo->hello
//2. 两对一样的字母（AABB型）连在一起，一定是拼写错误，去掉第二对的一个字母就好啦：比如 helloo->hello
//3. 上面的规则优先“从左到右”匹配，即如果是AABBCC，虽然AABB和BBCC都是错误拼写，应该优先考虑修复AABB，结果为AABCC
//
//我特喵是个天才！我在蓝翔学过挖掘机和程序设计，按照这个原理写了一个自动校对器，工作效率从此起飞。用不了多久，我就会出任CEO，当上董事长，迎娶白富美，走上人生巅峰，想想都有点小激动呢！
//……
//万万没想到，我被开除了，临走时老板对我说： “做人做事要兢兢业业、勤勤恳恳、本本分分，人要是行，干一行行一行。一行行行行行；要是不行，干一行不行一行，一行不行行行不行。” 我现在整个人红红火火恍恍惚惚的……



//#pragma once
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
//enum state { zero, one, two, three, four };
//
//int main() {
//	int total = 0;
//	cin >> total;
//	vector<string> input;
//	string s;
//	for (int i = 0; i < total; ++i) {
//		cin >> s;
//		input.push_back(s);
//	}
//
//	char c;
//
//	for (int i = 0; i < total; ++i) {
//		state state_now = zero;
//		for (auto c_ : input[i]) {
//			switch (state_now) {
//			case zero:
//				c = c_;
//				state_now = one;
//				cout << c_;
//				break;
//			case one:
//				if (c == c_)
//					state_now = two;
//				else {
//					c = c_;
//					state_now = one;
//				}
//				cout << c_;
//				break;
//			case two:
//				if (c != c_) {
//					c = c_;
//					state_now = three;
//					cout << c_;
//				}
//				break;
//			case three:
//				if (c != c_) {
//					c = c_;
//					state_now = one;
//					cout << c_;
//				}
//			}
//
//		}
//		cout << endl;
//	}
//	return 0;
//}