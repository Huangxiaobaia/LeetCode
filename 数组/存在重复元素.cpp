#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		quick_sort(nums.begin(), nums.end()-1);
		vector<int>::iterator vec = nums.begin()+1;
		int tmp = nums[0];
		while (vec != nums.end())
		{
			if (*vec == tmp)return true;
			tmp = *vec;
			vec++;
		}
		return false;
	}

	void quick_sort(vector<int>::iterator left, vector<int>::iterator right)
	{
		int base = *left;//���û�׼ֵ
		vector<int>::iterator t1 = left;
		vector<int>::iterator t2 = right;//�����ڱ�
		int tmp;
		while (t1 < t2)
		{
			while (t1 < t2&&*t2 > base)t2--;
			while (t1 < t2&&*t1 <= base)t1++;
			if (t1 < t2)
			{
				tmp = *t1;
				*t1 = *t2;
				*t2 = tmp;
			}
		}
		//����׼��λ
		tmp = base;
		*left = *t1;
		*t1 = tmp;
		if (t1 == left||t1==right)return;
		quick_sort(left, t1 - 1);
		quick_sort(t1 + 1, right);
		return;
	}
};

//��ϣ��
class Solution2 {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> uset;
		for (int elm : nums)
		{
			if (uset.find(elm) != uset.end())
				return true;
			uset.insert(elm);
		}
		return false;
	}
};



int main()
{
	Solution2 *s = new Solution2();
	vector<int> nums = { 1,1,1,3,3,4,3,2,4,2 };
	cout<<s->containsDuplicate(nums);
	return 0;
}