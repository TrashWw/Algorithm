//�ҽ����󴸣���һ�ҳ�����ı༭���Ҹ���У��Ͷ������Ӣ�ĸ������ݹ����ǳ����ˣ���Ϊÿ�춼Ҫȥ����������ƴд���󡣵��ǣ��������������ƽ���Ĺ����з��������ҷ���һ������ƴд����Ľݾ���
//
//1. ����ͬ������ĸ����һ��һ����ƴд����ȥ��һ���ľͺ��������� helllo->hello
//2. ����һ������ĸ��AABB�ͣ�����һ��һ����ƴд����ȥ���ڶ��Ե�һ����ĸ�ͺ��������� helloo->hello
//3. ����Ĺ������ȡ������ҡ�ƥ�䣬�������AABBCC����ȻAABB��BBCC���Ǵ���ƴд��Ӧ�����ȿ����޸�AABB�����ΪAABCC
//
//�������Ǹ���ţ���������ѧ���ھ���ͳ�����ƣ��������ԭ��д��һ���Զ�У����������Ч�ʴӴ���ɡ��ò��˶�ã��Ҿͻ����CEO�����϶��³���ӭȢ�׸��������������۷壬���붼�е�С�����أ�
//����
//����û�뵽���ұ������ˣ�����ʱ�ϰ����˵�� ����������Ҫ����ҵҵ�����ڿҿҡ������ַ֣���Ҫ���У���һ����һ�С�һ���������У�Ҫ�ǲ��У���һ�в���һ�У�һ�в������в��С��� �����������˺����л��㱵ġ���



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