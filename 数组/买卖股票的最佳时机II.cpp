#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//�汾һ
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		vector<int>::iterator i = prices.begin();//ͷָ��
		vector<int>::iterator j = prices.begin();//βָ��
		int sum=0;
		vector<int>::iterator ht = j;//��¼βָ���ǰһ��λ��
		j++;
		while (j != prices.end())
		{
			if (*i >= *j)//��ͷָ����ڵ���βָ���ʱ��ͷβָ�붼ǰ��
			{
				ht = j;
				i = j;
				j++;
			}
			else if (*ht<=*j)//���βָ��ǰһλ�õ�ֵС��Ӻ�
			{
				sum = sum + *j - *ht;
				ht = j;
				j++;

			}
			else if (*ht > *j)//���βָ��ǰһλ�õ�ֵ����ͷָ����Ϊβָ���λ�ã�βָ��ǰ��
			{
				i =ht;
				i++;
				ht = j;
				j++;
			}
		}
		return sum;
	}
};

//��̬�滮
class Solution2 {
public:
	int maxProfit(vector<int>& prices) {
		int dp0 = 0;//���콻���������û�й�Ʊ������
		int dp1 = -prices[0];//���콻����������й�Ʊ������
		int len = prices.size();
		for (int i = 0; i < len; i++)
		{
			dp0 = max(dp0, dp1 + prices[i]);//1��֮ǰ���� 2����������
			dp1 = max(dp1, dp0 - prices[i]);//1��֮ǰ���� 2����������
		}
		return dp0;//�������϶����������û�й�Ʊ��ʱ��
	}
};

//̰���㷨
class Solution3 {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		int sum = 0;
		for (int i = 1; i < len; i++)
		{
			if (prices[i - 1] <= prices[i])
				sum += prices[i] - prices[i - 1];
		}
		return sum;
	}
};

int main()
{
	//Solution* s = new Solution();
	//Solution2* s = new Solution2();
	Solution3* s = new Solution3();
	vector<int> prices = {5,2,3,2,6,6,2,9,1,0,7,4,5,0};
	cout << s->maxProfit(prices);
	return 0;
}