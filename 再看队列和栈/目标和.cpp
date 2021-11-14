#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//�����������
class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		if (nums.size() == 1)
			return abs(nums[0]) == abs(target) ? 1 : 0;

		queue<int>que;
		que.push(nums[0]);

		for(int i=1;i<nums.size();i++)
		{
			int size = que.size();
			for (int j = 0; j < size; j++)
			{
				int front = que.front();
				que.pop();
				que.push(front - nums[i]);
				que.push(front + nums[i]);
			}
		}
		int sum = 0;
		while (!que.empty())
		{
			sum += abs(que.front()) == abs(target) ? 1 : 0;
			que.pop();
		}
		return target==0?sum*2:sum;
	}
};

//�����������(���ݷ�)
class Solution {
public:
	int dfs(vector<int>&nums, int target, int p)
	{
		return p == nums.size() ? target == 0 : (dfs(nums, target - nums[p], p + 1) + dfs(nums, target + nums[p], p + 1));
	}

	int findTargetSumWays(vector<int>& nums, int target) {
		return dfs(nums, target, 0);
	}
};

//��̬�滮
class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		int sum = 0;
		for (auto &num : nums)
			sum += num;

		int diff = sum - target;
		if (diff < 0 || diff % 2 != 0)
			return 0;

		int n = nums.size(), neg = diff / 2;
		vector<vector<int>>vec(n + 1, vector<int>(neg + 1));

		vec[0][0] = 1;
		//i��ʾ��ǰi������ѡȡԪ��,vec[i][j]��ʾǰi��Ԫ���к�Ϊj�ķ����ĸ���
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= neg; j++)
			{
				vec[i][j] = vec[i - 1][j];
				if (j >= nums[i - 1])
					vec[i][j] += vec[i-1][j - nums[i - 1]];
			}
		}
		return vec[n][neg];
	}
};
//�Ż��ռ�Ķ�̬�滮
class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int target) {
		int sum = 0;
		for (auto &num : nums)
			sum += num;

		int diff = sum - target;
		if (diff < 0 || diff % 2 != 0)
			return 0;

		int n = nums.size(), neg = diff / 2;
		vector<int>vec(neg + 1);

		vec[0] = 1;
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= neg; j++)
			{
				if (j >= nums[i - 1])
					vec[j] += vec[j - nums[i - 1]];
			}
		}
		return vec[neg];
	}
};

int main()
{
	vector<int>test{ 30,1,5,32,16,17,30,29,48,14,29,4,31,12,40,13,13,20,41,38 };
	Solution*s = new Solution;
	cout << s->findTargetSumWays(test, 9);
	return 0;
}
