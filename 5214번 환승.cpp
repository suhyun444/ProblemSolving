#include <iostream>
#include <queue>

using namespace std;

vector<int> adj[101011];
bool visited[101011];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k, m;
	cin >> n >> k >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int a;
			cin >> a;
			adj[a].push_back(100010 + i);
			adj[100010 + i].push_back(a);
		}
	}
	queue<pair<int,int>> q;
	q.push({ 1,1 });
	visited[1] = true;
	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			pair<int,int> cur = q.front();
			q.pop();
			if (cur.first == n)
			{
				cout << cur.second;
				return 0;
			}
			for (int next : adj[cur.first])
			{
				if (!visited[next])
				{
					if (next >= 100010)
					{
						q.push({next, cur.second});
						visited[next] = true;
					}
					else
					{
						q.push({ next,cur.second + 1 });
						visited[next] = true;
					}
				}
			}
		}
	}
	cout << "-1";
}