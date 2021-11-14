#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Node {
public:
	int val;
	vector<Node*> neighbors;
	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}
	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}
	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;
	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}
	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}
	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};
*/

/* ����Ҫ����������Բ���ֱ�Ӹ����ھ� */

//�����������
class Solution {
public:
	Node* cloneGraph(Node* node) {
		if (node == NULL)
			return NULL;
		
		unordered_map<Node*, Node*>umap;
		umap[node] = new Node(node->val);

		queue<Node*>que;
		que.push(node);

		while (!que.empty())
		{
			Node* front = que.front();
			que.pop();
			for (auto n : front->neighbors)
			{
				if (!umap.count(n))
				{
					umap[n] = new Node(n->val);
					que.push(n);
				}
				umap[front]->neighbors.emplace_back(umap[n]);
			}
		}
		return umap[node];
	}
};

//�����������
class Solution {
public:
	unordered_map<Node*, Node*>umap;

	Node* cloneGraph(Node* node) {
		if (node == NULL)
			return NULL;
		//����Ѿ�����������ӹ�ϣ����ֱ�Ӳ���	
		if (umap.count(node))
			return umap[node];
		//���û�б�����,�򿽱��ý�㵽��ϣ����
		else
			umap[node] = new Node(node->val);

		//�����ý����ھ�
		for (auto &n : node->neighbors)
			umap[node]->neighbors.emplace_back(cloneGraph(n));
		return umap[node];
	}
};