#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//��̬�滮
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		//���ù�������
		int pre = 0,maxAns=nums[0];//pre��ʾ�յ���i�������е���������
		for (int i = 0; i < nums.size(); i++)
		{
			//pre = max(pre, 0) + nums[i];//���ǰһ��������С��0ֱ����ȥ����Խ��ԽС������0���뱾λ���,������������Խ��Խ��
			pre = max(pre + nums[i], nums[i]);
			maxAns = max(maxAns, pre);//�������ֵΪ��ǰ���ֵ�뵱ǰ�ۼ�ֵ֮������ֵ
		}
		return maxAns;
	}
};

int main()
{

	return 0;
}