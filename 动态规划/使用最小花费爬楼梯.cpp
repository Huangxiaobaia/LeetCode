#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		if (cost.size() == 1)
			return cost[0];
		if (cost.size() == 2)
			return cost[0] > cost[1] ? cost[1] : cost[0];
		/* ��Ϊ��Ŀ����Ϊ�� ÿ��������һ�������㶼Ҫ���Ѷ�Ӧ������ֵ��һ��֧������Ӧ������ֵ����Ϳ���ѡ��������һ�����ݻ������������ݡ�
		��֧���˽���̨�׵���������Լ������ϡ�����r��ʾ����ĳ��̨��ʱ�Ѿ������˵�����*/
		int q = 0, p = 0, r = 0;//q��ʾ����ǰǰһ��̨�׻������ٵ�������p��ʾ����ǰһ̨�׻������ٵ�����
		for (int i = 2; i <= cost.size(); i++)
		{
			q = p;
			p = r;
			r = min(q + cost[i - 2], p + cost[i - 1]);
		}
		return r;
	}
};
