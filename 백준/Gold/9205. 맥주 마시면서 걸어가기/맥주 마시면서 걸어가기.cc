#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;

vector<pair<int, int>> nodes;
bool visited[103];
int Dist(pair<int, int> cur, pair<int, int> next)
{
	return abs(next.first - cur.first) + abs(next.second - cur.second);
}
bool bfs()
{
	queue<int> q;
	q.push({ 0 });
	visited[0] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < nodes.size(); i++)
		{
			if (Dist(nodes[cur], nodes[i]) <= 1000)
			{
				if (i == nodes.size() - 1)return true;
				if (!visited[i])
				{
					q.push(i);
					visited[i] = true;
				}
			}
		}
	}
	return false;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(visited, false, sizeof(visited));
		int n;
		cin >> n;
		for (int i = 0; i < n + 2; i++)
		{
			int x, y;
			cin >> x >> y;
			nodes.push_back({ x,y });
		}
		cout << ((bfs()) ? "happy\n" : "sad\n");
		nodes.clear();
	}
}