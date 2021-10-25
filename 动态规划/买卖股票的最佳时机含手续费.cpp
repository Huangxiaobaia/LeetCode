#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* ������ע����Ŀ�Ƿ����������� */
//��̬�滮
class Solution {
public:
	int maxProfit(vector<int>& prices, int fee) {
		int dp0 = 0, dp1 = -prices[0];
		for (int i = 1; i < prices.size(); i++)
		{
			dp0 = max(dp0, dp1 + prices[i] - fee);
			dp1 = max(dp1, dp0 - prices[i]);
		}
		return max(dp0, dp1);//��Ϊ���������ѣ���������������ʱ��һ��������Ĺ�Ʊ����
	}
};