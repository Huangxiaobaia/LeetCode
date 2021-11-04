#include <iostream>
#include <unordered_map>
using namespace std;

typedef struct node
{
	int value;
	struct node* next;
	struct node* rand;
	node(int data)
	{
		value = data;
	}
}node, *Node;
/* 
	randָ���ǵ�����ڵ�ṹ��������ָ�룬rand����ָ�������е�����һ����
�㣬Ҳ����ָ��null������һ����Node�ڵ�������ɵ��޻��������ͷ�ڵ�
head����ʵ��һ����������������ĸ��ƣ������ظ��Ƶ��������ͷ�ڵ㡣
*/
class Solution {
public:
	Node copyListWithRandom2(Node head)
	{
		if (head == NULL)
			return NULL;
		Node cur = head;
		Node next = NULL;
		while (cur != NULL)
		{
			next = cur->next;
			cur->next = new node(cur->value);
			cur->next->next = next;
			cur = next;
		}
		Node curCopy = NULL;
		cur = head;
		while (cur != NULL)
		{
			curCopy = cur->next;
			curCopy->rand = cur->rand!=NULL?cur->rand->next:NULL;
			cur = curCopy->next;
		}
		Node res = head->next;
		cur = head;
		while (cur != NULL)
		{
			next = cur->next->next;
			curCopy = cur->next;
			cur->next = next;
			curCopy->next = next!=NULL?next->next:NULL;
			curCopy = next;
			cur = next;
		}
		return res;
	}
};



int main()
{
	Node head = new node(1);
	head->next = new node(2);
	head->next->next = new node(3);
	head->next->next->next = new node(4);
	head->next->next->next->next = new node(5);
	head->next->next->next->next->next = new node(6);
	head->next->next->next->next->next->next = NULL;

	head->rand = head->next->next->next->next->next; // 1 -> 6
	head->next->rand = head->next->next->next->next->next; // 2 -> 6
	head->next->next->rand = head->next->next->next->next; // 3 -> 5
	head->next->next->next->rand = head->next->next; // 4 -> 3
	head->next->next->next->next->rand = NULL; // 5 -> null
	head->next->next->next->next->next->rand = head->next->next->next; // 6 -> 4

	Solution*s = new Solution;
	Node ans = s->copyListWithRandom2(head);
	Node tmp = ans;
	while (tmp != NULL)
	{
		cout << tmp->value;
		tmp = tmp->next;
	}

	return 0;
}