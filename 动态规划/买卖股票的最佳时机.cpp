#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//��̬�滮
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int q=0,p=-prices[0];//qΪ�����й�Ʊ������pΪ���й�Ʊ������
		for (int i = 1; i < prices.size(); i++)
		{
			q = max(p+prices[i],q);
			p = max(p, -prices[i]);
		}
		return q;
	}
};

int main()
{

	return 0;
}