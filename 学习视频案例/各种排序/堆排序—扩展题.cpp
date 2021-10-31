#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
		��֪һ��������������飬����������ָ������������ź�˳��Ļ���ÿ��Ԫ���ƶ��ľ�����Բ�����k��
	����k�����������˵�Ƚ�С����ѡ��һ�����ʵ������㷨���������ݽ�������
*/
class Solution {
public:
	void sortedArrDistanceLessK(vector<int>&nums,int k)
	{
		//С����
		priority_queue<int, vector<int>, greater<int>>heap;
		int n = nums.size();
		//��n����k�����ǰk��Ԫ�طŽ�С����
		int i = 0;
		for (; i < min(n, k+1); i++)
			heap.push(nums[i]);
		//�Ѷ�Ԫ�رض���Ӧ���ź���֮���Ԫ��
		int j = 0;
		for (; i<n; j++,i++)
		{
			nums[j] = heap.top();
			heap.pop();
			heap.push(nums[i]);
		}
		//�Ѷ���ʣ���Ԫ�ظ��ǵ�ԭ����
		while (!heap.empty())
		{
			nums[j++] = heap.top();
			heap.pop();
		}
	}
};

//��дС����
class SmallHeap {
public:
	/* ɾ�������ضѶ�Ԫ�� */
	int top(vector<int>&current)
	{
		int ret = *current.begin();
		current.erase(current.begin());
		return ret;
	}
	/* ���������Ԫ�� */
	void push(vector<int>&current,int newnum)
	{
		current.push_back(newnum);
		heapify(current, 0, current.size() - 1);
	}
	/* �������ϵ��� */
	void heapify(vector<int>&nums, int index, int size)
	{
		int left = index * 2 + 1;
		while (left <= size)
		{
			int minest = left + 1 <= size && nums[left] > nums[left + 1] ? left + 1 : left;
			minest = nums[index] > nums[minest] ? minest : index;
			if (minest == index)
				break;
			swap(nums[index], nums[minest]);
			index = minest;
			left = index * 2 + 1;
		}
	}
	/* ����з�����Ԫ�ز������ϵ��� */
	void heapInsert(vector<int>&nums,int number,int index)
	{
		nums.push_back(number);
		while (nums[index] < nums[(index - 1) / 2])
		{
			swap(nums[index], nums[(index - 1) / 2]);
			index = (index - 1) / 2;
		}
	}

	void sortedArrDistanceLessK(vector<int>&origin, int k)
	{
		int n = origin.size();
		int m = min(n, k);
		//����ǰk+1��Ԫ�ص�С����
		vector<int>current;
		for (int i = 0; i <=m; i++)
			heapInsert(current, origin[i],i);
		//�������������淽��һ��
		int i = k+1,j=0;
		for (; i < n; i++, j++)
		{
			origin[j] = top(current);
			push(current, origin[i]);
		}
		while (!current.empty())
			origin[j++] = top(current);
	}
};

int main()
{
	vector<int>test = { 3,2,1,5,4 };
	Solution*s = new Solution;
	s->sortedArrDistanceLessK(test,2);
	for (auto &elm : test)
		cout << elm << " ";

	cout << "\n";

	SmallHeap*sh = new SmallHeap;
	sh->sortedArrDistanceLessK(test, 2);
	for (auto &elm : test)
		cout << elm << " ";

	return 0;
}