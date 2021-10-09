#include <iostream>
#include <vector>
using namespace std;

//˫ָ��
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		if (nums.size() <= 1)return;
		auto fast = nums.begin();
		auto slow = nums.begin();

		while (fast != nums.end())
		{
			fast++;
			while (fast != nums.end() && *fast == 0)fast++;//�ҵ���һ����Ϊ0��λ��
			while (slow < fast&&*slow != 0)slow++;
			if(fast!=nums.end()&&slow<fast)
				swap(*fast, *slow);
		}
	}
};

//˫ָ��
class Solution2 {
public:
	void moveZeroes(vector<int>& nums) {
		int left = 0;//ָ�����ź����е�ĩβ
		int right = 0;//ָ����������е�ͷ��
		while (right < nums.size())
		{
			if (nums[right])
			{
				if (left < right)
				{
					//swap(nums[right], nums[left + 1]);
					nums[left] = nums[right];
					nums[right] = 0;
					
				}
				left++;
			}
			right++;
		}
	}
};



int main()
{
	Solution2*s = new Solution2;
	vector<int>vec{1 ,2,3,0,4,5};
	s->moveZeroes(vec);
	for (auto elm : vec)
		cout << elm << " ";
	return 0;
}