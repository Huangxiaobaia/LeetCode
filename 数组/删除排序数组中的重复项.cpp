#include <iostream>
#include <vector>
using namespace std;

//�����ⷨ
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		if (nums.size() == 0)return 0;

		vector<int>::iterator t1 = nums.begin();
		vector<int>::iterator t2 = nums.begin();

		int t=*t2;//����t2ָ���ǰһ��ֵ
		t2++;

		while(t2 != nums.end())
		{
			if (*t2 !=t)//���t2ָ����ǰһ��ֵ�����
			{
				t1++;
				*t1 = *t2;
			}
			t = *t2;
			t2++;
		}
		return t1 - nums.begin() + 1;
	}
};


int main()
{
	Solution* s = new Solution();
	vector<int>nums = { 1,1,2 };
	int len = s->removeDuplicates(nums);
	int i = 0;
	for (i; i < len; i++)
		cout << nums[i] << " ";
	return 0;
}
