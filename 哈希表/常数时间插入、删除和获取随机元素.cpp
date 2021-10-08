#include <iostream>
#include <unordered_set>
using namespace std;

//����unordered_set
class RandomizedSet {
public:
	RandomizedSet() {
		uset = {};
	}

	bool insert(int val) {
		if (uset.count(val) != 0)
			return false;
		uset.insert(val);
		return true;
	}

	bool remove(int val) {
		if (uset.count(val) == 0)
			return false;
		uset.erase(val);
		return true;
	}

	int getRandom() {
		auto iter = uset.begin();
		advance(iter, rand() % uset.size());
		return *iter;
	}
private:
	unordered_set<int>uset;
};

/*
	����leetcode�ⷨ��Java�汾ʹ��һ����̬����͹�ϣ��ʵ�֣�
	��̬���飺�洢Ԫ��ֵ
	��ϣ����ΪԪ��ֵ��ֵΪԪ��ֵ�ڶ�̬�����е�������
	����������ȡֵ��ʵ�ֳ�����ʱ�临�Ӷ�
	��ɾ��Ԫ��ʱ�������Ȳ鵽Ԫ��ֵ��������Ȼ�����������ҵ�����ʱ�临�Ӷ�Ϊ������
	Ȼ���ڽ�Ҫɾ����ֵ������ĩβ��ֵ�������������ĩβ��ֵɾ������������м�ʱ����
	Ԫ���ڹ�ϣ���ж�Ӧ���������������̵�ʱ�临�Ӷ�Ϊ������
*/

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main()
{

	return 0;
}