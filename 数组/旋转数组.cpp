#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//��η�ת
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		k = k % len;

		reverse(nums, nums.begin(), nums.end()-1);//�ȷ�תȫ��Ԫ��
		reverse(nums,nums.begin(),nums.begin()+k-1);//�ٷ�תǰk��Ԫ��
		reverse(nums, nums.begin() + k, nums.end()-1);//�ٷ�תʣ��Ԫ��
	}
	void reverse(vector<int>&nums,vector<int>::iterator t1, vector<int>::iterator t2)
	{
		while (t1 < t2)
		{
			int temp = *t1;
			*t1 = *t2;
			*t2 = temp;
			t2--;
			t1++;
		}
	}
};

//��״�滻
class Solution2 {
public:
	void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		k = k % len;
		int count = gcd(k, len);
		for (int start = 0; start < count; start++)
		{
			int current = start+k;
			while (current != start)
			{
				int next = (current + k) % len;
				swap(nums[current], nums[start]);
				current = next;
			}
		}
	}
	int gcd(int a, int b)
	{
		int t;
		while (b)
		{
			t = a % b;
			a = b;
			b = t;
		}
		return a;
	}
};

int main()
{
	Solution2* s = new Solution2();
	vector<int> nums = {1,2,3,4,5,6,7 };
	s->rotate(nums,3);
	cout << s->gcd(1, 3);
	for (auto elm : nums)
		cout << elm << " ";
	return 0;
}