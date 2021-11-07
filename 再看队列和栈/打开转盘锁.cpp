#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

//�����������
class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		if (target == "0000")
			return 0;
		unordered_set<string>dead(deadends.begin(),deadends.end());
		if (dead.count("0000"))
			return -1;

		auto num_prev = [](char x)->char {
			return (x == '0' ? '9' : x - 1);
		};
		auto num_succ = [](char x)->char {
			return (x == '9' ? '0' : x + 1);
		};

		auto get = [&](string &status)->vector<string> {
			vector<string>ret;
			for (int i = 0; i < 4; i++)
			{
				char num = status[i];
				status[i] = num_prev(num);
				ret.push_back(status);
				status[i] = num_succ(num);
				ret.push_back(status);
				status[i] = num;
			}
			return ret;
		};

		unordered_set<string>seen{"0000"};//��¼���ҹ���ֵ

		queue<pair<string,int>>que;
		que.emplace("0000", 0);
		while (!que.empty())
		{
			//ȡ������Ԫ�أ��õ���Ԫ�ط�ת��Ŀ��ܵ�ֵ
			pair<string,int> head = que.front();
			que.pop();
			vector<string>shifted=get(head.first);
			//�жϷ�ת���Ԫ���ǲ��Ǳ����ҹ��Լ��ǲ�����������
			for (auto&elm : shifted)
			{
				if (!seen.count(elm) && !dead.count(elm))
				{
					if (elm == target)
						return head.second + 1;
					que.push({ elm,head.second + 1 });
					seen.insert(elm);
				}
			}
		}
		return -1;
	}
};

//����ʽ����
struct AStar {
	int f_, g_, h_;
	string status_;

	AStar(const string&status, const string&target, int g) :status_{ status }, g_(g), h_{ getH(status,target) }
	{
		f_ = g_ + h_;
	}
	//��������
	int getH(const string&status, const string&target)
	{
		int ret = 0;
		for (int i = 0; i < 4; i++)
		{
			int dist = abs(int(status[i]) - int(target[i]));
			ret += min(dist, 10 - dist);
		}
		return ret;
	}
	bool operator< (const AStar& that) const {
		return f_ > that.f_;
	}
};

class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		if (target == "0000")
			return 0;
		unordered_set<string>dead(deadends.begin(), deadends.end());
		if (dead.count("0000"))
			return -1;

		auto num_prev = [](char c)->char {
			return c == '0' ? '9' : c - 1;
		};
		auto num_succ = [](char c)->char {
			return c == '9' ? '0' : c + 1;
		};

		auto get = [&](string &status)->vector<string> {
			vector<string>ret;
			for (int i = 0; i < 4; i++)
			{
				char c = status[i];
				status[i] = num_prev(c);
				ret.push_back(status);
				status[i] = num_succ(c);
				ret.push_back(status);
				status[i] = c;
			}
			return ret;
		};

		unordered_set<string>seen{ "0000" };
		priority_queue <AStar> que;
		que.emplace("0000", target, 0);
		while (!que.empty())
		{
			AStar head = que.top();
			que.pop();
			vector<string>shifted = get(head.status_);
			for (auto &elm : shifted)
			{
				if (!seen.count(elm) && !dead.count(elm))
				{
					if (elm == target)
						return head.g_ + 1;
					que.emplace(elm, target, head.g_ + 1);
					seen.insert(elm);
				}
			}
		}
		return -1;
	}
};



