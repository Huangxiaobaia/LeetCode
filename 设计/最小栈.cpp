#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//ʹ�ø���ջ
class MinStack {
public:
	MinStack() {
		xstack.push(INT_MAX);
	}

	void push(int val) {
		minstack.push(val);
		xstack.push(min(val, xstack.top()));
	}

	void pop() {
		minstack.pop();
		xstack.pop();
	}

	int top() {
		return minstack.top();
	}

	int getMin() {
		return xstack.top();
	}
private:
	stack<int>minstack;
	stack<int>xstack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

//��ʹ�ø���ջ,�����������,��compare����Ϊlong���ͽ������Խ������
class MinStack {
public:
	MinStack() {

	}

	void push(int val) {
		if (minstack.empty())
		{
			topmin = val;
			minstack.push(0);
		}
		else
		{
			long long compare = val - topmin;
			minstack.push(compare);
			topmin = compare > 0 ? topmin : val;
		}

	}

	void pop() {
		long long top = minstack.top();
		//���topС��0�������topmin
		topmin = top < 0 ? (topmin - top) : topmin;
		minstack.pop();
	}

	int top() {
		if (minstack.top() <= 0)
			return topmin;
		else
		{
			return minstack.top() + topmin;//ת��Ϊԭֵ
		}
	}

	int getMin() {
		return topmin;
	}
private:
	stack<long long>minstack;
	long long topmin;
};