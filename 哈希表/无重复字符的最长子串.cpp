#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <numeric>
#include <array>
using namespace std;

//���Ǹ��׳�
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.length() <= 1)return s.length();
		unordered_set<char>uset;
		int ans=0;
		int len = s.size();
		int rk = 0;//��ָ��
		for (int i=0;i<len; i++)//��ָ��ö��ÿ��Ԫ��
		{
			if (i != 0)uset.erase(s[i - 1]);//��ָ��ÿǰ��һ����ɾ����ǰһ��Ԫ��
			while (rk < len && (uset.count(s[rk])) == 0)
			{
				uset.insert(s[rk]);
				rk++;
			}
			ans = ans > (rk - i) ? ans : (rk - i);
		}
		return ans;
	}
};


int main()
{
	Solution*S = new Solution;
	string s = "anviaj";
	cout << S->lengthOfLongestSubstring(s);
	return 0;
}