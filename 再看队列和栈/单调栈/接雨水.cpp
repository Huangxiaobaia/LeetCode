#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//ÿ���㶼����һ�˱���,ʱ�临�ӶȽϸ�
class Solution4 {
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
class Solution3 {
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
/* ��ջ�д洢Ԫ�ص��±꣬ջ���±��Ӧ��Ԫ�ش�СΪ�ݼ��� */
class Solution {
public:
	int trap(vector<int>& height) {
		stack<int>stack;
		stack.push(0);
		int sum = 0;
		for (int i = 1; i < height.size(); i++)
		{
			//��ջ��Ϊ�ղ����¼����Ԫ�ش���ջ��Ԫ��
			while (!stack.empty() && height[i] > height[stack.top()])
			{
				int top = stack.top();
				stack.pop();
				//���ջ��ֻ��һ��Ԫ���������˴�ѭ��
				if (stack.empty())
					break;
				//���ջ��Ԫ���������������ʱһ���ܴ���ˮ
				int left = stack.top();
				//leftʼ�մ���ǰԪ����ߵı������Ԫ�أ��ܵĹ��̿������Ϊһ�������ϵ�����ˮ
				int width = i - left - 1;
				sum += width * (min(height[left], height[i]) - height[top]);
			}
			stack.push(i);
		}
		return sum;
	}
};

//˫ָ���Ż���̬�滮
/* �÷���������ָ������˶�̬�滮������leftMax�����rightMax���飬
��Ϊ�ڶ�̬�滮�����м�����ˮ��ʱֻ�õ���leftMax��rightMax�еĽ�Сֵ�������һ�α����п���ά������������
����ǰԪ�ص�������ֵС�ڵ����ұ����ֵʱ������Ϊ������ֵΪ����ֵ��������ֵ���еĽϴ�ֵ��ͬʱ�����Ԫ�ص�
��ˮ������ǰԪ�ص��ұ����ֵͬ��
*/
class Solution2 {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		int left = 0, right = n - 1;
		int leftMax = 0, rightMax = 0;
		int sum = 0;
		while (left < right)
		{
			while (left < right&&height[left] <= height[right])
			{
				leftMax = max(leftMax,height[left]);
				left++;
				sum += (leftMax - height[left]>0? (leftMax - height[left]):0);
			}
			while (left < right&&height[right] <= height[left])
			{
				rightMax = max(rightMax,height[right]);
				right--;
				sum += (rightMax - height[right]>0?(rightMax - height[right]):0);
			}
		}
		return sum;
	}
};

int main()
{
	vector<int>height{0,1,0,2,1,0,1,3,2,1,2,1};
	Solution*s = new Solution;
	cout << s->trap(height);
	return 0;
}