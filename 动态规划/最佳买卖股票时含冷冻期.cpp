#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//��̬�滮
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int f1 = -prices[0];//��i��������й�Ʊ���������
		int f2 = 0;//��i������û�й�Ʊ���Ҵ����䶳������µ��������
		int f3 = 0;//��i������û�й�Ʊ���Ҳ������䶳�ڵ�����µ��������
		for (int i = 0; i < prices.size(); i++)
		{
			int tmpf1 = f1;
			int tmpf2 = f2;
			f1 = max(f1, f3 - prices[i]);
			f2 = tmpf1 + prices[i];
			f3 = max(tmpf2, f3);
		}
		return max(f2, f3);
	}
};