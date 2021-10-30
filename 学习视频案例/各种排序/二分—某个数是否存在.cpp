#include <iostream>
#include <vector>
using namespace std;

//��������
class Solution {
public:
	bool bsExist(vector<int>&nums,int a){
		if (nums.size() == 0)
			return false;
		int L = 0;
		int R = nums.size() - 1;
		while (L < R)
		{
			int mid = L + ((R - L) >> 1);
			if (nums[mid] == a)
				return true;
			else if (nums[mid] > a)
				R = mid - 1;
			else
				L = mid + 1;
		}
		return nums[L] == a;//���ǵ��������midΪLλ�ã��жϲ���Ⱥ�L+1
	}
};

int main()
{
	vector<int>test = { 0,1,2,3,4,5,6,7 };
	Solution*s = new Solution;
	cout << s->bsExist(test,9);
	return 0;
}