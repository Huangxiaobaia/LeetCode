#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	//���µ���
	void heapify(vector<int>&nums, int index,int size)
	{
		int left = index * 2 + 1;//����
		//������ĶѵĴ�С
		while (left < size)
		{
			//�õ����Һ����е����ֵ
			int largest = left + 1 < size&&nums[left] < nums[left + 1] ? left + 1 : left;
			//�õ����Һ����Լ����ڵ�����ֵ
			largest = nums[index]>nums[largest]?index:largest;
			//������ڵ�������ٵ���
			if (largest == index)
				break;
			//���򽻻�����������
			swap(nums[index], nums[largest]);
			index = largest;
			left = index * 2 + 1;
		}
		
	}
	//�����
	void heapSort(vector<int>&nums)
	{
		int size = nums.size();
		if (size < 2)
			return;
		for (int i =size - 1; i >= 0; i--)
			heapify(nums, i,size);
		swap(nums[0], nums[--size]);
		while (size > 0)
		{
			heapify(nums, 0,size);
			swap(nums[0], nums[--size]);
		}
	}
};

int main()
{
	vector<int>test = { 1,3,4,2,5 };
	Solution*s = new Solution;
	s->heapSort(test);
	for (auto &elm : test)
		cout << elm << " ";
	return 0;
}