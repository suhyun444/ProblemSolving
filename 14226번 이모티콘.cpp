#include <iostream>
#include <queue>

using namespace std;

bool visited[2001][2001];
int main()
{
	int s;
	cin >> s;
	queue<pair<int, int>> q;
	q.push({ 1,0 });
	visited[1][0] = true;
	int level = 0;
	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			pair<int, int> cur = q.front();
			q.pop();
			if (cur.first == s)
			{
				cout << level;
				return 0;
			}
			if (!visited[cur.first][cur.first])
			{
				q.push({ cur.first,cur.first });
				visited[cur.first][cur.first] = true;
			}
			if (cur.first + cur.second <= 2000 && !visited[cur.first + cur.second][cur.second])
			{
				q.push({ cur.first + cur.second,cur.second });
				visited[cur.first + cur.second][cur.second] = true;
			}
			if (cur.first - 1 >= 0 && !visited[cur.first - 1][cur.second])
			{
				q.push({ cur.first - 1,cur.second });
				visited[cur.first - 1][cur.second] = true;
			}
		}
		level++;
	}
}