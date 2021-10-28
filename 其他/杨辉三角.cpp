#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>>ans{ {1} };//��0��
		for (int i = 1; i < numRows; i++)//��i��
		{
			vector<int>tmpans;
			for (int j = 0; j <= i; j++)//��i�е�j��Ԫ��
			{
				int left = j - 1;//���Ͻ�Ԫ�ض�Ӧ����ֵ
				int right = j;//���Ͻ�Ԫ�ض�Ӧ����ֵ
				if (left < 0||right>i-1)//�������ұ߽�ֵΪ1
					tmpans.push_back(1);
				else
					tmpans.push_back(ans[ans.size() - 1][left] + ans[ans.size() - 1][right]);
			}
			ans.push_back(tmpans);
		}
		return ans;
	}
};

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>>ans(numRows);
		for (int i = 0; i < numRows; i++)
		{
			ans[i].resize(i + 1);
			ans[i][0] = ans[i][i] = 1;
			for (int j = 1; j < i; j++)
				ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
		}
		return ans;
	}
};


int main()
{
	Solution*s = new Solution;
	vector<vector<int>>vec = s->generate(3);

	return 0;
}