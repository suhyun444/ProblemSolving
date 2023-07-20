#include <iostream>

using namespace std;

int tree[300003];
int arr[100001];

void InitTree(int l,int r,int node)
{
	if (l == r)
	{
		tree[node] = arr[l] % 2;
		return;
	}
	int mid = (l + r) / 2;
	InitTree(l, mid, node * 2);
	InitTree(mid + 1, r, node * 2 + 1);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
void Update(int l, int r, int node, int index,int val)
{
	if (l > index || index > r)return;
	if (l == r)
	{
		tree[node] = val % 2;
		return;
	}
	int mid = (l + r) / 2;
	Update(l, mid, node * 2,index,val);
	Update(mid + 1, r, node * 2 + 1, index, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int Query(int l, int r, int node, int nodeL, int nodeR)
{
	if (l > nodeR || nodeL > r)return 0;
	if (nodeL <= l && r <= nodeR)return tree[node];
	int mid = (l + r) / 2;
	return Query(l, mid, node * 2, nodeL, nodeR) + Query(mid + 1,r,node*2 + 1,nodeL,nodeR);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	InitTree(1,n,1);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			Update(1, n, 1, b, c);
		}
		else if (a == 2)
		{
			int length = c - b + 1;
			cout << length - Query(1, n, 1, b, c) << "\n";
		}
		else if (a == 3)
		{
			cout << Query(1, n, 1, b, c) << "\n";
		}
	}
}
