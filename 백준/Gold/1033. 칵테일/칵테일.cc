#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int ingredient[10];
vector<int> adj[10];
bool visited[10];
void dfs(int cur, int ratio)
{
	visited[cur] = true;
	ingredient[cur] *= ratio;
	for (int next : adj[cur])
	{
		if (visited[next])continue;
		dfs(next, ratio);
	}
}
int gcd(int a, int b)
{
	if (b == 0)return a;
	return gcd(b, a % b);
}
void Devide(int n)
{
	int cur = ingredient[0];
	for (int i = 1; i < n; ++i)
	{
		cur = gcd(cur, ingredient[i]);
	}
	if (cur == 1)return;
	for (int i = 0; i < n; ++i)
	{
		ingredient[i] /= cur;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 10; ++i)ingredient[i] = 1;
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b, p, q;
		cin >> a >> b >> p >> q;
		memset(visited, false, sizeof(visited));
		int mulA = ingredient[b] * p;
		int mulB = ingredient[a] * q;
		dfs(a, mulA);
		dfs(b, mulB);
		Devide(n);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; ++i)
		cout << ingredient[i] << " ";
}