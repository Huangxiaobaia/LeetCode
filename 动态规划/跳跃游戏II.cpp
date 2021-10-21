#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//̰��
class Solution {
public:
	int jump(vector<int>& nums) {
		int rightmost = 0;//�ɵ������Զλ��
		int cur = 0;//Ŀǰ����λ��
		int sum = 0;//����
		while (rightmost < nums.size() - 1)
		{
			int tmpMax=0;
			int i = cur;
			while (i <= rightmost)
			{
				if (i + nums[i] > tmpMax)
				{
					tmpMax = i + nums[i];
					cur = i;
				}
				i++;
			}
			rightmost = tmpMax;
			sum++;//������һ
		}
		return sum;
	}
};

class Solution {
public:
	int jump(vector<int>& nums) {
		int rightmost = 0;
		int step = 0;
		int end = 0;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			rightmost = max(rightmost, i + nums[i]);
			if (i == end)
			{
				end = rightmost;
				step++;
			}
		}
		return step;
	}
};

