#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxSubarraySumCircular(vector<int>& nums) {
		int pre = nums[0],maxSum=nums[0],minSum=0,sum=nums[0];
		//������Խ������
		for (int i = 1; i < nums.size(); i++)
		{
			sum += nums[i];
			pre = max(pre, 0) + nums[i];
			maxSum = max(pre, maxSum);
		}
		//����Խ���������ض�����nums[0]��nums[n-1],�������ߵ���������м�����ݺ���С������м���С�ĺͼ��ɡ�
		pre = nums[0];
		for (int i = 1; i < nums.size() - 1; i++)
		{
			pre = min(pre, 0) + nums[i];
			minSum = min(pre, minSum);
		}
		return max(sum - minSum, maxSum);
	}
};

//�ڽ�����
class Solution2 {
public:
	int maxSubarraySumCircular(vector<int>& nums) {
		int n = nums.size();
		int pre = nums[0],ans=nums[0];
		//û��Խ��
		for (int i = 1; i < n; i++)
		{
			pre = max(pre, 0) + nums[i];
			ans = max(ans, pre);
		}
		//����Խ��
		// rightsums[i] = A[i] + A[i+1] + ... + A[N-1]
		vector<int>rightsums(n);
		rightsums[n - 1] = nums[n - 1];
		for (int i = n - 2; i > 1; i--)
			rightsums[i] = rightsums[i + 1] + nums[i];
		//maxright[i] = max_{j >= i} rightsums[j]
		vector<int>maxright(n);
		maxright[n - 1] = rightsums[n - 1];
		for (int i = n - 2; i > 1; i--)
			maxright[i] = max(maxright[i + 1], rightsums[i]);

		//����߲�������ĺ����ұ߲�����������ֵ���
		int leftsum = 0;
		for (int i = 0; i < n - 2; i++)
		{
			leftsum += nums[i];
			ans = max(ans, leftsum + maxright[i + 2]);
		}
		return ans;
	}
};

int main()
{
	vector<int>vec = { 1,-2,3,-2 };
	Solution2*s = new Solution2;
	cout << s->maxSubarraySumCircular(vec);
	return 0;
}