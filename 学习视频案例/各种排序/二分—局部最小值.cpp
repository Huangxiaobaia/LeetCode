#include <iostream>
#include <vector>
using namespace std;

/* ���ֲ���Ӧ�õ���ֲ���Сֵ��λ������,������������� */
//������������Ԫ�ز���ȣ��ҵ��ֲ���Сֵ��λ��
class Solution {
public:
	int getLessIndex(vector<int>&nums)
	{
		if (nums.size() == 0)
			return -1;//������
		if (nums.size() == 1 || nums[0] < nums[1])
			return 0;
		if (nums[nums.size() - 1] < nums[nums.size() - 2])
			return nums.size() - 1;
		int left = 1;
		int right = nums.size() - 2;
		while (left < right)
		{
			int mid = left + ((right - left) >> 1);
			if (nums[mid] > nums[mid - 1])
				right = mid - 1;
			else if (nums[mid] > nums[mid + 1])
				left = mid + 1;
			else
				return mid;
		}
		return left;
	}
};

int main()
{
	vector<int>test = { 6,5,7,3,5,8,9 };
	Solution*s = new Solution;
	cout << s->getLessIndex(test);
	return 0;
}