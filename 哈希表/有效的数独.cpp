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


//
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int rows[9][9];//��¼ÿһ��ÿ�����ֳ��ֵĴ���
		int columns[9][9];//��¼ÿһ��ÿ�����ֳ��ֵĴ���
		int subboxs[3][3][9];//��¼ÿһ���Ź�����ÿ�����ֵĳ��ִ���

		memset(rows, 0, sizeof(rows));
		memset(columns, 0, sizeof(columns));
		memset(subboxs, 0, sizeof(subboxs));

		for(int i=0;i<9;i++)
			for (int j = 0; j < 9; j++)
			{
				char c = board[i][j];
				if (c != '.')
				{
					int index = c - '0' - 1;//Ҫ�����ֶ�Ӧ����������������Լ�һ
					rows[i][index]++;
					columns[j][index]++;
					subboxs[i / 3][j / 3][index]++;
					if (rows[i][index] > 1 || columns[j][index] > 1 || subboxs[i / 3][j / 3][index] > 1)
						return false;
				}
			}
		return true;
	}
};

int main()
{
	

	return 0;
}