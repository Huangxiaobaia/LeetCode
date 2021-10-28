#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//�������������ʹ����һ����ά�����¼�õ��Ƿ񱻷��ʹ������ı�ԭ������grid
class Solution {
	vector<int>vec;
	vector<vector<int>>isFind;
	queue<int>que;
	int m, n;
public:
	void bfs(vector<vector<char>>& grid, vector<vector<int>>&isFind, int i, int j)
	{
		isFind[i][j] = 1;//��Ǳ����ʹ�
		int k = i * m + j;//������תΪһ����
		que.push(k);
		while (!que.empty())
		{
			int k = que.front();
			que.pop();
			//��������Ļ�ԭ
			int x = k / m;
			int y = k % m;
			//�Ըõ��������ҵĵ�����ж�
			//��
			if (x > 0 && isFind[x - 1][y] != 1 && grid[x - 1][y] == '1')
			{
				que.push((x - 1)*m + y);
				isFind[x - 1][y] = 1;
			}
			//��
			if (x < n - 1 && isFind[x + 1][y] != 1 && grid[x + 1][y] == '1')
			{
				que.push((x + 1)*m + y);
				isFind[x + 1][y] = 1;
			}
			//��
			if (y > 0 && isFind[x][y - 1] != 1 && grid[x][y - 1] == '1')
			{
				que.push(x*m + y - 1);
				isFind[x][y - 1] = 1;
			}
			//��
			if (y < m - 1 && isFind[x][y + 1] != 1 && grid[x][y + 1] == '1')
			{
				que.push(x*m + y + 1);
				isFind[x][y + 1]=1;
			}
		}
	}

	int numIslands(vector<vector<char>>& grid) {
		if (grid.size() == 0)
			return 0;
		m = grid[0].size();
		n = grid.size();
		vec.resize(m);
		isFind.resize(n);
		for (int i = 0; i < n; i++)
			isFind[i] = vec;
		int sum = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == '1'&&isFind[i][j] != 1)
				{
					sum++;
					bfs(grid, isFind, i, j);
				}
			}
		return sum;
	}
};

//��������������ı���ԭ����
class Solution {
	int m, n;
public:
	void dfs(vector<vector<char>>& grid, int i, int j)
	{
		grid[i][j] = '0';
		if (i > 0 && grid[i - 1][j] == '1')dfs(grid, i - 1, j);
		if (i < n - 1 && grid[i + 1][j] == '1')dfs(grid, i + 1, j);
		if (j > 0 && grid[i][j - 1] == '1')dfs(grid, i, j - 1);
		if (j < m - 1 && grid[i][j + 1] == '1')dfs(grid, i, j + 1);
	}

	int numIslands(vector<vector<char>>& grid) {
		if (grid.size() == 0)
			return 0;

		m = grid[0].size();
		n = grid.size();

		int sum = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == '1')
				{
					sum++;
					dfs(grid, i, j);
				}
			}
		return sum;
	}
};