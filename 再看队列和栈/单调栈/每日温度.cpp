#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//�����ⷨ
/*
	next������¶�ֵ��һ�γ��ֵ��±꣬��ʼ��Ϊ���ֵ
*/
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		int size = temperatures.size();
		vector<int>next(101, INT_MAX),ans(size);
		//�Ӻ���ǰ����
		for (int i = size-1; i>=0; i--)
		{
			int wamerIndex = INT_MAX;
			for (int j = temperatures[i] + 1; j < 101; j++)
				wamerIndex = min(wamerIndex, next[j]);
			if (wamerIndex != INT_MAX)
				ans[i] = wamerIndex - i;
			next[temperatures[i]] = i;
		}
		return ans;
	}
};

//����ջ
class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		stack<int>index;//��������¶ȵ��±�
		int size = temperatures.size();
		vector<int>ans(size);
		for (int i = 0; i < size; i++)
		{
			while (!index.empty() && temperatures[i] > temperatures[index.top()])
			{
				ans[index.top()] = i - index.top();
				index.pop();
			}
			index.push(i);
		}
		return ans;
	}
};