#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

/*
��һ���д���ֵ����⣺
��1��map���������˳���insert��˳���ǲ�һ���ģ�
��2��unordered_map�������˳���insert˳����һ���ģ�
���⣬�������ͬ�ļ�ֵ��insert�ƺ�û���𲻵����ã���û�иı�ԭ�е����ݣ�Ҳû�в����µ����ݡ���Ҫ�����ݴ���map/unordered_map�У���Ҫ���ж��Ƿ�key�Ƿ��Ѿ����ڣ�
������ڣ����� [] ��ʽ�޸�value����������ڣ���ֱ��insert��
��˲���Ҫ�ٲ��ҷ���Ҫ����ַ���ԭ�ַ����е�����
*/
class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<char, int>umap;
		int i = 0;
		int ret=999999;
		for (i = 0; i < s.length(); i++)
		{
			if (umap.count(s[i]) != 0)
				umap[s[i]]++;
			else
				umap[s[i]] = 1;
		}
		for (auto iter = umap.begin(); iter != umap.end(); iter++)
		{
			if (iter->second == 1)
			{
				int index = s.find(iter->first);
				if (index < ret)ret = index;
			}
		}
		return ret<999999?ret:-1;
	}
};
//�޸ĺ�İ汾
class Solution2 {
public:
	int firstUniqChar(string s) {
		unordered_map<int, int> umap;
		for (char ch : s) {
			umap[ch]++;
		}
		for (int i = 0; i < s.size(); ++i) {
			if (umap[s[i]] == 1) {
				return i;
			}
		}
		return -1;
	}
};

//ʹ�ù�ϣ��洢����
class Solution3 {
public:
	int firstUniqChar(string s) {
		unordered_map<int, int> umap;
		for (int i = 0; i < s.size(); i++)
		{
			if (umap.count(s[i]) != 0)
			{//�������ֶ�Σ���Ϊ-1
				umap[s[i]] = -1;
			}
			else
				umap[s[i]] = i;//�洢��Ӧ����
		}
		int first = s.size();
		for (auto iter = umap.begin(); iter != umap.end(); iter++)
			if (iter->second != -1&& iter->second<first)first=iter->second;
		return first==s.size()?-1:first;
	}
};

//ʹ�ö���
class Solution4 {
public:
	int firstUniqChar(string s) {
		unordered_map<char, int> umap;
		queue<pair<char, int>>que;
		for (int i = 0; i < s.size(); i++)
		{
			if (umap.count(s[i]) == 0)
			{//����ַ�û�г��ֹ���������ϣӳ���Լ�����
				umap[s[i]] = i;
				que.emplace(make_pair(s[i], i));
			}
			else 
			{//����ַ����ֹ�������λ-1�������������Ԫ��ֵΪ-1�����
				umap[s[i]] = -1;
				while (!que.empty() && umap[que.front().first] == -1)
					que.pop();
			}
		}
		//������в��գ�������Ϊ��һ��Ψһ�ַ���������пգ�����ַ�������
		return que.empty() ? -1 : que.front().second;
	}
};


int main()
{
	Solution4*S = new Solution4;
	string s = "loveleetcode";
	cout << S->firstUniqChar(s);
	return 0;
}