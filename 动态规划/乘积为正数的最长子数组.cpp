#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int getMaxLen(vector<int>& nums) {
		int positive = nums[0] > 0 ? 1 : 0;//�Ե�i��Ԫ��Ϊ��β������ĳ˻�Ϊ����������
		int negative = nums[0] < 0 ? 1 : 0;//�Ե�i��Ԫ��Ϊ��β������ĳ˻�Ϊ����������
		int maxNum = positive;
		for (int i = 1; i < nums.size(); i++)
		{
			//Ԫ��Ϊ�������ı�˻��ķ���
			if (nums[i] > 0)
			{
				positive = positive + 1;
				negative = negative > 0 ? (negative + 1) : 0;//���˻�Ϊ���ĸ���Ϊ0ʱ���������������Ӵ˸���
			}
			else if (nums[i] < 0)
			{
				int tmpPositive = positive;
				int tmpNegative = negative;//����������ʱ�������м��㣬����ı�ԭ����
				positive = tmpNegative > 0 ? (tmpNegative + 1) : 0;
				negative = tmpPositive + 1;
			}
			else//��Ԫ��Ϊ0ʱ��ֱ�ӽض�
			{
				positive = 0;
				negative = 0;
			}
			maxNum = max(maxNum, positive);
		}
		return maxNum;
	}
};