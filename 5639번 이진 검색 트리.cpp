#include <iostream>

using namespace std;

struct Node {
	Node()
	{

	}
	Node(int _item)
	{
		item = _item;
		left = nullptr;
		right = nullptr;
	}
	int item;
	Node* left;
	Node* right;
};
Node nodes[10001];
int index = 0;
void Insert(Node* cur, int value)
{
	if (cur->item > value)
	{
		if (cur->left == nullptr)
		{
			nodes[index].item = value;
			cur->left = &nodes[index++];
			return;
		}
		Insert(cur->left, value);
	}
	else
	{
		if (cur->right == nullptr)
		{
			nodes[index].item = value;
			cur->right = &nodes[index++];
			return;
		}
		Insert(cur->right, value);
	}
}
void PostOrder(Node* cur)
{
	if (cur == nullptr)
	{
		return;
	}
	PostOrder(cur->left);
	PostOrder(cur->right);
	cout << cur->item << "\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int item;
	cin >> item;
	Node head = Node(item);
	while (cin >> item)
	{
		Insert(&head, item);
	}
	PostOrder(&head);
}