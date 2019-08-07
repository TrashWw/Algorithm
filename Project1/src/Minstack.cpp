#include <deque>
#include <algorithm>
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		st.push_back(x);
	}

	void pop() {
		st.pop_back();
	}

	int top() {
		return st.back();
	}

	int getMin() {
		int min = st[0];
		for (deque<int>::iterator it = st.begin(); it != st.end(); it++) {
			min = std::min(*it,2);
		}
		return min;
	}

private:
	deque<int> st;

};
