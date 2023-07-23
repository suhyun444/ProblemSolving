#include <iostream>

using namespace std;

int arr[100001];
int tree[300001];
void InitTree(int l, int r, int node)
{
	if (l == r)
	{
		tree[node] = l;
		return;
	}
	int mid = (l + r) / 2;
	InitTree(l, mid, node * 2);
	InitTree(mid + 1, r, node * 2+1);
	if (arr[tree[node * 2]] <= arr[tree[node * 2 + 1]])
		tree[node] = tree[node * 2];
	else
		tree[node] = tree[node * 2 + 1];
}
void Update(int l, int r, int node, int index, int value)
{
	if (l > index || index > r)return;
	if (l == r)	return;
	int mid = (l + r) / 2;
	Update(l, mid, node * 2,index,value);
	Update(mid + 1, r, node * 2 + 1,index,value);
	if (arr[tree[node * 2]] <= arr[tree[node * 2 + 1]])
		tree[node] = tree[node * 2];
	else
		tree[node] = tree[node * 2 + 1];
}
int Query(int l, int r, int node, int nodeL, int nodeR)
{
	if (l > nodeR || nodeL > r)return -1;
	if (nodeL <= l && r <= nodeR)return tree[node];
	int mid = (l + r) / 2;
	int left = Query(l, mid, node * 2, nodeL, nodeR);
	int right = Query(mid + 1, r, node * 2 + 1, nodeL, nodeR);
	if (left != -1 && (right == -1|| arr[left] <= arr[right]))
		return left;
	else
		return right;
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
			arr[b] = c;
			Update(1, n, 1, b, c);
		}
		else
		{
			cout << Query(1, n, 1, b, c) << "\n";
		}
	}

}