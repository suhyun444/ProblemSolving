#include <iostream>

using namespace std;

int arr[100001];
int tree[300003];
void InitTree(int l, int r, int node)
{
	if (l == r)
	{
		tree[node] = arr[l];
		return;
	}
	int mid = (l + r) / 2;
	InitTree(l, mid, node * 2);
	InitTree(mid + 1, r, node * 2 + 1);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
void Update(int l, int r, int node, int index, int value)
{
	if (l > index || index > r)return;
	if (l == r)
	{
		tree[node] = value;
		return;
	}
	int mid = (l + r) / 2;
	Update(l, mid, node * 2, index, value);
	Update(mid + 1, r, node * 2 + 1, index, value);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
int Query(int l, int r, int node, int nodeL, int nodeR)
{
	if (l > nodeR || nodeL > r)return 2e9;
	if (nodeL <= l && r <= nodeR)return tree[node];
	int mid = (l + r) / 2;
	return min(Query(l, mid, node * 2, nodeL, nodeR), Query(mid + 1, r, node * 2 + 1, nodeL, nodeR));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
	}
	InitTree(1,n,1);
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			Update(1, n, 1, b, c);
		}
		else
		{
			cout << Query(1, n, 1, b, c) << "\n";
		}
	}
}