#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long tree[1500005];
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
	if (nodeL <= l && r <= nodeR)return tree[node] * 1LL;
	int mid = (l + r) / 2;
	return Query(l, mid, node * 2, nodeL, nodeR) + Query(mid + 1, r, node * 2 + 1, nodeL, nodeR);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int,int>> arr(n+1);
	for (int i = 1; i <= n; ++i)
	{
		int item;
		cin >> item;
		arr[i] = { item,i };
	}
	long long result = 0;
	sort(arr.begin(), arr.end());
	for (int i = 1; i <= n; ++i)
	{
		int index = arr[i].second;
		result += Query(1, n, 1, index + 1, n);
		Update(1, n, 1, index, 1);
	}
	cout << result;
}