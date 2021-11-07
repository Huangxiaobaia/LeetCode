#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

//ά��һ���ݼ��ĵ���ջ
class StockSpanner {
	stack<int>stack;
	unordered_map<int, int>umap;//��¼Ԫ��ֵ�Լ���Ӧ�������������
public:
	StockSpanner() {

	}

	int next(int price) {
		int sum=1;
		while (!stack.empty()&&stack.top()<=price)
		{
			int top = stack.top();
			stack.pop();
			sum += umap[top];
		}
		stack.push(price);
		umap[price] = sum;
		return sum;
	}
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */