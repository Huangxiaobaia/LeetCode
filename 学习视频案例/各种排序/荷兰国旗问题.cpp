#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
	/* 
		����һ������arr����һ����num�����С�ڵ���num���������������ߣ�����num��������������ұߡ�
	Ҫ�����ռ临�Ӷ�O(1)��ʱ�临�Ӷ�O(N)
	*/
	vector<int> partition(vector<int>&arr, int l, int r, int p)
	{
		int less = l - 1;
		int more = r + 1;
		while (l < more)
		{
			if (arr[l] < p)
				swap(arr[l++], arr[++less]);
			else if (arr[l] > p)
				swap(arr[l++], arr[--more]);
			else
				l++;
		}
		return { less + 1,more - 1 };
	}

	void problem1(vector<int>&arr,int num)
	{
		partition(arr, 0,arr.size()-1,num);
	}
	/*
		����һ������arr����һ����num�����С��num���������������ߣ�����num��������������м䣬����num��������������ұߡ�
	Ҫ�����ռ临�Ӷ�O(1)��ʱ�临�Ӷ� O(N)
	*/
	void netherlandsFlag(vector<int>&arr,int num)
	{
		partition(arr, 0,arr.size()-1,num);
	}
};

int main()
{
	vector<int>test = { 3,5,6,2,4,8 };
	Solution*s = new Solution;
	s->problem1(test, 5);
	for (auto &elm : test)
		cout << elm << " ";
	cout << "\n";

	return 0;
}