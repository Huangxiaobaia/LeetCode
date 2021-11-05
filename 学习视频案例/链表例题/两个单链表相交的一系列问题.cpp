#include <iostream>
using namespace std;

typedef struct node
{
	int value;
	struct node* next;
	node(int data)
	{
		value = data;
	}
}node, *Node;

/* �������������л�Ҳ�����޻��ĵ�����ͷ�ڵ�head1��head2����ʵ
��һ��������������������ཻ���뷵���ཻ�ĵ�һ���ڵ㡣������ཻ,��
��null */
class Solution {
public:
	/* �������л��򷵻ػ�����ڽ�㣬��û�л��򷵻ؿ� */
	Node getLoopNode(Node head)
	{
		if (head->next == NULL || head->next->next == NULL)
			return NULL;
		//���ÿ���ָ����һ��
		Node fast = head->next->next;
		Node slow = head->next;
		while (fast != slow)
		{
			if (fast->next == NULL || fast->next->next == NULL)
				return NULL;
			fast = fast->next->next;
			slow = slow->next;
		}
		//����ָ���ڻ�������֮�����ָ����Ϊͷ��㣬����ָ��ͬʱ�ƶ�һ�����ٴ�����ʱ��Ϊ�����
		fast = head;
		while (fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return fast;
	}

	Node noLoop(Node head1, Node head2)
	{
		int n = 0;
		Node cur1 = head1;
		Node cur2 = head2;
		while (cur1 != NULL)
		{
			n++;
			cur1 = cur1->next;
		}
		while (cur2 != NULL)
		{
			n--;
			cur2 = cur2->next;
		}
		//�����ĩ�˽�㲻ͬ��������϶����ཻ
		if (cur1 != cur2)
			return NULL;
		//��cur1ָ���������
		cur1 = n > 0 ? head1 : head2;
		cur2 = cur1 == head1 ? head2 : head1;
		//��cur1ǰ��abs(n)
		n = abs(n);
		while (n != 0)
		{
			n--;
			cur1 = cur1->next;
		}
		//cur1��cur2ͬʱǰ��
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}

	Node bothLoop(Node head1,Node loop1, Node head2,Node loop2)
	{
		Node cur1 = head1;
		Node cur2 = head2;
		if (loop1 == loop2)
		{
			int n = 0;
			while (cur1 != loop1)
			{
				n++;
				cur1 = cur1->next;
			}
			while (cur2 != loop2)
			{
				n--;
				cur2 = cur2->next;
			}
			cur1 = n > 0 ? head1 : head2;
			cur2 = cur1 == head1 ? head2 : head1;
			n = abs(n);
			while (n != 0)
			{
				n--;
				cur1 = cur1->next;
			}
			while (cur1 != cur2)
			{
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
			return cur1;
		}
		else
		{
			cur1 = loop1->next;
			while (cur1 != loop1)
			{
				if (cur1 == loop2)
					return loop1;
				cur1 = cur1->next;
			}
			return NULL;//���������л����ǲ��ཻ
		}
	}

	Node findFirstIntersectNode(Node head1,Node head2)
	{
		if (head1 == NULL || head2 == NULL)
			return NULL;
		Node loop1 = getLoopNode(head1);
		Node loop2 = getLoopNode(head2);
		//���һ�����������޻�
		if (loop1 == NULL && loop2 == NULL)
			return noLoop(head1, head2);
		//����������������л�
		if (loop1 != NULL && loop2 != NULL)
			return bothLoop(head1,loop1, head2,loop2);
		return NULL;
	}
};

int main()
{
	// 1->2->3->4->5->6->7->null
	Node head1 = new node(1);
	head1->next = new node(2);
	head1->next->next = new node(3);
	head1->next->next->next = new node(4);
	head1->next->next->next->next = new node(5);
	head1->next->next->next->next->next = new node(6);
	head1->next->next->next->next->next->next = new node(7);

	// 0->9->8->6->7->null
	Node head2 = new node(0);
	head2->next = new node(9);
	head2->next->next = new node(8);
	head2->next->next->next = head1->next->next->next->next->next; // 8->6
	

	// 1->2->3->4->5->6->7->4...
	head1 = new node(1);
	head1->next = new node(2);
	head1->next->next = new node(3);
	head1->next->next->next = new node(4);
	head1->next->next->next->next = new node(5);
	head1->next->next->next->next->next = new node(6);
	head1->next->next->next->next->next->next = new node(7);
	head1->next->next->next->next->next->next = head1->next->next->next; // 7->4

	// 0->9->8->2...
	head2 = new node(0);
	head2->next = new node(9);
	head2->next->next = new node(8);
	head2->next->next->next = head1->next; // 8->2


	// 0->9->8->6->4->5->6..
	head2 = new node(0);
	head2->next = new node(9);
	head2->next->next = new node(8);
	head2->next->next->next = head1->next->next->next->next->next; // 8->6

	Solution*s = new Solution;
	Node ans = s->findFirstIntersectNode(head1, head2);
	cout << ans->value;

	return 0;
}