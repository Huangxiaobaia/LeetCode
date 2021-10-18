#include <iostream>
#include <vector>
#include <array>
using namespace std;


//��̬�滮
class Solution {
public:
	int climbStairs(int n) {
		//���ù��������˼�뽫�ռ临�ӶȽ�Ϊ����
		int p = 0, q = 0, r = 1;
		for (int i = 1; i <= n; i++)
		{
			p = q;
			q = r;
			r = p + q;
		}
		return r;
	}
};

//���������
class Solution {
public:

	vector<vector<long long>> multiply(vector<vector<long long>> &a, vector<vector<long long>> &b)
	{
		vector<vector<long long>>c(2, vector<long long>(2));
		for(int i=0;i<2;i++)
			for (int j = 0; j < 2; j++)
			{
				c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
			}
		return c;
	}


	vector<vector<long long>> matrixPow(vector<vector<long long>> a, int n)
	{
		vector<vector<long long>>ret = { {1,0},{0,1} };
		while (n > 0)
		{
			if ((n & 1) == 1)
			{
				ret = multiply(ret, a);
			}
			n >>= 1;
			a = multiply(a, a);
		}
		return ret;
	}

	int climbStairs(int n) {
		vector<vector<long long>>ret = { {1,1},{1,0} };
		vector<vector<long long>>res = matrixPow(ret, n);
		return res[0][0];
	}
};

/* ԭ��Ŀ�ϼ����������� 1��ÿ��������� 1 �� 2 ��̨�ס� 2����������������̨�ס�
���������Ϊ�����������̨�ף��´β�����������̨�ף�*/
class Solution {
public:
	int climbStairs(int n) {
		int p = 1, q = 1, r = 2;
		for (int i = 3; i <= n; i++)
		{
			p = q;
			q = r;
			r = p + q;
		}
		return r;
	}
};