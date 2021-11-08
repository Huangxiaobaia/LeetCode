#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//ÿ���㶼����һ�˱���,ʱ�临�ӶȽϸ�
class Solution {
public:
	int trap(vector<int>& height) {
		int left = 0, right = 0;
		int len = height.size();
		int sum = 0;
		//�����ڶ����������ڶ���
		for (int i = 1; i < len - 1; i++)
		{
			left =i-1;
			right = i + 1;
			int leftMax = INT_MIN;
			int rightMax = INT_MIN;
			//�����õ�����
			while (left >= 0)
			{
				leftMax = max(height[left], leftMax);
				left--;
			}
			//�����õ���ұ�
			while (right <= len - 1)
			{
				rightMax = max(height[right], rightMax);
				right++;
			}
			if (leftMax >= height[i] && rightMax >= height[i] && (leftMax != 0 || rightMax != 0))
			{
				sum += min(leftMax, rightMax) - height[i];
			}
		}
		return sum;
	}
};

//��̬�滮��leftMax��rightMax�����Ż�
class Solution {
public:
	int trap(vector<int>& height) {
		int len = height.size();
		vector<int>leftMax(len);
		vector<int>rightMax(len);
		leftMax[0] = height[0];
		rightMax[len - 1] = height[len - 1];
		int sum = 0;
		for (int i = 1; i < len - 1; i++)
			leftMax[i]=max(leftMax[i - 1], height[i]);	
		for (int i = len-2; i >=0; i--)
			rightMax[i] = max(rightMax[i + 1], height[i]);
		for (int i = 1; i < len - 1; i++)
			sum += min(leftMax[i], rightMax[i]) - height[i];
		return sum;
	}
};

//����ջ
class Solution {
public:
	int trap(vector<int>& height) {
		
	}
};

//˫ָ��
class Solution {
public:
	int trap(vector<int>& height) {

	}
};

int main()
{

	return 0;
}