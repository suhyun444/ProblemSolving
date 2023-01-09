#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool visited[10000];

int a, b;
char method[4] = { 'D','S','L','R' };
string bfs()
{
	queue < pair<int, string> >q;
	q.push({ a,"" });
	visited[a] = true;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			pair<int, string> cur = q.front();
			if (cur.first == b)
				return cur.second;
			q.pop();
			
			//D
			int next[4];
			next[0] = (cur.first * 2) % 10000;
			//S
			next[1] = (cur.first - 1);
			if (next[1] == -1)next[1] = 9999;
			//L
			next[2] = (cur.first % 1000) * 10 + cur.first / 1000;
			//R
			next[3] = (cur.first % 10) * 1000 + (cur.first / 10);
			for (int j = 0; j < 4; j++)
			{
				if (!visited[next[j]])
				{
					q.push({ next[j],cur.second + method[j] });
					visited[next[j]] = true;
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		memset(visited, false, sizeof(visited));
		cout << bfs() << "\n";
	}
}