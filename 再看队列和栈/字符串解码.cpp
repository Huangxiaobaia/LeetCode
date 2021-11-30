#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	string decodeString(string s) {
		stack<string>stacks;
		stack<int>stacki;
		string a = "";
		int num = 0;//�������һλ��������

		for (auto &c : s)
		{
			if (c == '[')
			{
				stacki.push(num);
				num = 0;
				stacks.push(a + c);
			} 
			else if (c != ']' && ((c - '0') < 0 || (c - '0') > 9))
				stacks.push(a + c);
			else if ((c - '0') >= 0 && (c - '0') <= 9)
				num = num * 10 + (c - '0');
			else//��������
			{
				string tmp="";
				while (stacks.top() != "[")
				{
					tmp = stacks.top()+tmp;
					stacks.pop();
				}
				stacks.pop();//����������
				int num = stacki.top();
				stacki.pop();
				string ttmp = tmp;
				for (int i = 0; i < num-1; i++)tmp += ttmp;
				stacks.push(tmp);
			}
		}

		a.clear();
		while (!stacks.empty())
		{
			a = stacks.top() + a;
			stacks.pop();
		}
		return a;
	}
};

int main()
{
	Solution* s = new Solution;
	string S = "3[a2[c]]";
	cout << s->decodeString(S);
	//string s = "";
	//cout << s + 'b' << endl;;
	//cout << ""+'b';
	return 0;
}