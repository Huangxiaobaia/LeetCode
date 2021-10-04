#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;


/*
��������������Ѿ��ź����أ��㽫����Ż�����㷨��
��� nums1 �Ĵ�С�� nums2 С�ܶ࣬���ַ������ţ�
(�����)��� nums2 ��Ԫ�ش洢�ڴ����ϣ��ڴ������޵ģ������㲻��һ�μ������е�Ԫ�ص��ڴ��У������ô�죿
*/


//��ϣ��
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size())
			intersect(nums2, nums1);//����С��һ�����й�ϣӳ��
		vector<int>vec;
		unordered_map<int, int>umap;
		for (int elm : nums1)
			umap[elm]++;
		for (auto elm : nums2)
		{
			if (umap[elm] > 0)
			{
				vec.push_back(elm);
				umap[elm]--;
			}
		}
		return vec;
	}
};

//����˫ָ��
class Solution2 {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		auto iter1 = nums1.begin();
		auto iter2 = nums2.begin();
		vector<int>ret;
		while (iter1 != nums1.end() && iter2 != nums2.end())
		{
			if (*iter1 == *iter2)
			{
				ret.push_back(*iter1);
				iter1++;
				iter2++;
			}
			else if (*iter1 < *iter2)
				iter1++;
			else iter2++;
		}
		return ret;
	}
};

int main()
{
	Solution2*s = new Solution2;
	vector<int>nums1 = {4,9,5 };
	vector<int>nums2 = {9,4,9,8,4};
	vector<int>vec = s->intersect(nums1, nums2);
	for (int elm : vec)
		cout << elm << " ";
	return 0;
}