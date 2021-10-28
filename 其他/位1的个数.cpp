#include <iostream>
using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int ans = 0;
		while (n)
		{
			ans += n & 1;
			n >>= 1;
		}
		return ans;
	}
};

//ѭ����������λ
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int ans = 0;
		for (int i = 0; i < 32; i++)
		{
			if (n&(1 << i))
				ans++;
		}
		return ans;
	}
};

//λ�����Ż�
/* n&(n-1)��������ǡ��Ϊ�Ѷ������е����λ1��Ϊ0֮��Ľ����
	ʱ�临�Ӷȣ�log(n)*/
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int ans = 0;
		while (n)
		{
			n &= n - 1;
			ans++;
		}
		return ans;
	}
};