#include <iostream>
#include <vector>
using namespace std;

/* һ�����������������ֳ����������Σ��ҳ����������� */
class Solution {
public :
	vector<int> oddNumber(vector<int>&nums)
	{
		int eor = 0;
		
		for (int i = 0; i < nums.size(); i++)
			eor ^= nums[i];

		//ȡ��eor�����Ҳ�Ϊ1�Ķ�����λ
		int tmpEor = eor & (~eor + 1);

		//�����������з��ϸö�����λΪ1������򣬵õ����������ֵ�����һ��
		int a = 0;
		for (int i = 0; i < nums.size(); i++)
			if(nums[i]&tmpEor==1)
				a ^= nums[i];

		//Ȼ��a��eor���õ����������ֵ���һ��
		int b = eor ^ a;

		return { a,b };
	}
};

int main()
{
	vector<int>test = { 0,0,3,4,6,5,5,6 };
	Solution*s = new Solution;
	vector<int>ans = s->oddNumber(test);
	for (auto &elm : ans)
		cout << elm << " ";
	return 0;
}