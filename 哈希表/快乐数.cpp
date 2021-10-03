#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//����ָ�뷨
class Solution {
public:
	int get_next(int number)
	{
		int sum=0;
		do {
			int a = number % 10;
			number = number / 10;
			sum += a * a;
		} while (number != 0);
		return sum;
	}

	bool isHappy(int n) {
		int fast = get_next(n);
		int slow = n;
		while (fast != slow && fast != 1)
		{
			fast = get_next(get_next(fast));
			slow = get_next(slow);
		}
		return fast == 1;
	}
};

//�ù�ϣ���ϼ��ѭ��
class Solution2 {
public:
	bool isHappy(int n) {
		unordered_set<int>num;
		int sum = 0;
		int tmp = n;
		while (true)
		{
			do {
				int a = tmp % 10;
				tmp = tmp / 10;
				sum += a * a;
			} while (tmp != 0);
			if (num.count(sum) != 0)return false;
			if (sum == 1)return true;
			num.insert(sum);
			//cout << sum << "\n";
			tmp = sum;
			sum = 0;
		}
	}
};

int main()
{
	Solution *s = new Solution();
	cout << s->isHappy(2);
	return 0;
}