#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, int> m;
long long arr[500001];
long long tree[1500003];
void Update(int l, int r, int node, int index, int value)
{
	if (index < l || r < index)return;
	tree[node] += value;
	if (l != r)
	{
		int mid = (l + r) / 2;
		Update(l, mid, node * 2, index, value);
		Update(mid + 1, r, node * 2 + 1, index, value);
	}
}
long long Query(int l, int r, int node, int nodeL, int nodeR)
{
	if (l > nodeR || nodeL > r)return 0;
	if (nodeL <= l && r <= nodeR)return tree[node];
	int mid = (l + r) / 2;
	return Query(l, mid, node * 2, nodeL, nodeR) + Query(mid + 1, r, node * 2 + 1, nodeL, nodeR);
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
		long long item;
		cin >> item;
		m.insert({ item,i});
	}
	for (int i = 1; i <= n; ++i)
	{
		long long item;
		cin >> item;
		arr[m[item]] = i;
	}
	long long result = 0;
	for (int i = 1; i <= n; ++i)
	{
		int index = arr[i];
		result += Query(1, n, 1, index + 1, n);
		Update(1, n, 1, index, 1);
	}
	cout << result;
}