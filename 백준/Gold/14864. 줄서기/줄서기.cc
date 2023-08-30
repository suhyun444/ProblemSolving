#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100001];
int card[100001];
bool visited[100001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		card[i] = i;
	}
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		++card[a];
		--card[b];
	}
	for (int i = 1; i <= n; ++i)
	{
		if (card[i] > n || card[i] < 0 || visited[card[i]])
		{
			cout << -1;
			return 0;
		}
		visited[card[i]] = true;
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << card[i] << " ";
	}
}