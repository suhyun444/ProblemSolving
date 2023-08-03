#include <iostream>

using namespace std;

int arr[1000001];
int tree[3000001];
void InitTree(int l,int r,int node)
{
	if (l == r)
	{
		tree[node] = arr[l];
		return;
	}
	int mid = (l + r) / 2;
	InitTree(l, mid, node * 2);
	InitTree(mid + 1, r, node * 2 + 1);
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}
int Query(int l, int r, int node, int nodeL, int nodeR)
{
	if (nodeR < l || nodeL > r)return 0;
	if (nodeL <= l && r <= nodeR)return tree[node];
	int mid = (l + r) / 2;
	return max(Query(l, mid, node * 2, nodeL, nodeR), Query(mid + 1, r, node * 2 + 1, nodeL, nodeR));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n;++i)
	{
		cin >> arr[i];
	}
	InitTree(1, n, 1);
	for (int i = m; i <= n - m + 1; ++i)
	{
		cout << Query(1, n, 1, i - m + 1, i + m - 1) << " ";
	}
}
