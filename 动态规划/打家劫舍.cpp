#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//��̬�滮
class Solution {
public:
	int rob(vector<int>& nums) {
		int dp1 = nums[0], dp0 = 0;//dp1��ʾ��һ�ұ�͵�ˣ�dp0��ʾ��һ��û��͵
		for (int i = 1; i < nums.size(); i++)//�ӵڶ��ҿ�ʼ
		{
			int tmp = max(dp1, dp0);
			dp1 = dp0 + nums[i];
			dp0 = tmp;
		}
		return max(dp0, dp1);
	}
};

int main()
{

	return 0;
}