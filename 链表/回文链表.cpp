#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* ���ʹ�õݹ鷴������ڵ㣬ͬʱʹ�õݹ麯����ı�����ǰ�������Ϳ����ж������Ƿ�Ϊ���ġ� */
class Solution {
	ListNode* frontPointer;
public:

	bool recursivelyCheck(ListNode*currentNode)
	{
		if (currentNode != NULL)
		{
			if (!recursivelyCheck(currentNode->next))
				return false;
			if (currentNode->val != frontPointer->val)
				return false;
			frontPointer = frontPointer->next;
		}
		return true;
	}

	bool isPalindrome(ListNode* head) {
		frontPointer = head;
		return recursivelyCheck(head);
	}
};
/*
ʱ�临�Ӷȣ�O(n)������ n ָ��������Ĵ�С��
�ռ临�Ӷȣ�O(n)������ n ָ��������Ĵ�С������Ҫ�������������еݹ麯������һ�������е���һ������ʱ��
�������Ҫ�ڽ��뱻���ú���֮ǰ�������ڵ�ǰ�����е�λ�ã��Լ��κξֲ�������ֵ����ͨ������ʱ����ڶ�ջ����ʵ�֣���ջ֡����
�ڶ�ջ�д�ź������ݺ�Ϳ��Խ��뱻���õĺ���������ɱ����ú���֮�����ᵯ����ջ����Ԫ�أ��Իָ��ڽ��к�������֮ǰ���ڵĺ�����
�ڽ��л��ļ��֮ǰ���ݹ麯�����ڶ�ջ�д��� n ����ջ֡�������������������д���������ʹ�õݹ�ʱ�ռ临�Ӷ�Ҫ���Ƕ�ջ��ʹ�������

���ַ�������ʹ���� O(n)O(n)O(n) �Ŀռ䣬�ұȵ�һ�ַ��������Ϊ����������У���ջ֡�Ŀ����ܴ��� Python����
������������ʱ��ջ���Ϊ 1000���������ӣ������п��ܵ��µײ���ͳ����ڴ������
Ϊÿ���ڵ㴴����ջ֡������������㷨�ܹ��������������С��

*/

/*
	Ϊ�˴ﵽ0(1)�Ŀռ临�Ӷȣ����øı�����ķ�����
	������ĺ�벿�ַ�ת�����Ǹ÷����ڲ����Ļ�������ȱ�㣬����ִ��ʱ��Ҫ���������̻߳���̶�����ķ��ʣ���Ϊ�ں���ִ�й���������ᱻ�޸ġ�
*/

class Solution {
public:
	bool isPalindrome(ListNode*head)
	{
		if (head == NULL)
			return true;
		//����ָ��Ѱ�������е�
		ListNode*fast = head;
		ListNode*slow = head;
		while (fast->next!=NULL&&fast->next->next!=NULL)
		{
			fast = fast->next->next;//��ָ��������
			slow=slow->next;//��ָ����һ��
		}
		//��ת��벿��
		slow->next=reverseList(slow->next);
		//ǰ�벿�����벿�ֶԱ�
		ListNode*p1 = head;
		ListNode*p2 = slow->next;
		bool result=true;
		while (result&&p2 != NULL)
		{
			if (p2->val != p1->val)
				result=false;
			p2 = p2->next;
			p1 = p1->next;
		}
		//��ԭ����ĺ�벿��
		slow->next = reverseList(slow->next);
		return result;
	}

	//��ת����ĵݹ�д��
	ListNode* reverseList(ListNode*node)
	{
		if (node == NULL||node->next==NULL)
			return node;
		ListNode* nextNode = node->next;
		ListNode* reversed = reverseList(node->next);
		nextNode->next = node;
		node->next = NULL;
		return reversed;
	}
	//��ת����ķǵݹ�д��
	ListNode* reverseList(ListNode*node)
	{
		ListNode*prev = NULL;
		ListNode*curr = node;
		while (node != NULL)
		{
			ListNode*tmp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = tmp;
		}
	}

};