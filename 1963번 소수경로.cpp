#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

bool prime[10][10][10][10];
bool visited[10][10][10][10];
int bfs(int s,int e)
{
	memset(visited, false, sizeof(visited));
	queue<string> q;
	string start = to_string(s);
	string end = to_string(e);
	q.push(start);
	visited[start[0] - '0'][start[1] - '0'][start[2] - '0'][start[3] - '0'] = true;
	int level = 0;
	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			string cur = q.front();
			q.pop();
			if (cur == end)
			{
				return level;
			}
			for (int i = 1; i <= 9; i++)
			{
				string next = cur;
				next[0] = i + '0';
				if (prime[next[0] - '0'][next[1] - '0'][next[2] - '0'][next[3] - '0'] && !visited[next[0] - '0'][next[1] - '0'][next[2] - '0'][next[3] - '0'])
				{
					q.push(next);
					visited[next[0] - '0'][next[1] - '0'][next[2] - '0'][next[3] - '0'] = true;
				}
			}
			for (int i = 1; i < 4; i++)
			{
				for (int j = 0; j <= 9; j++)
				{
					string next = cur;
					next[i] = j + '0';
					if (prime[next[0] - '0'][next[1] - '0'][next[2] - '0'][next[3] - '0'] && !visited[next[0] - '0'][next[1] - '0'][next[2] - '0'][next[3] - '0'])
					{
						q.push(next);
						visited[next[0] - '0'][next[1] - '0'][next[2] - '0'][next[3] - '0'] = true;
					}
				}
			}
		}
		level++;
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(prime, true, sizeof(prime));
	for (int i = 2; i < 10000; i++)
	{
		for (int j = 2; i * j < 10000; j++)
		{
			if (i * j >= 1000)
			{
				string s = to_string(i * j);
				prime[s[0] - '0'][s[1] - '0'][s[2] - '0'][s[3] - '0'] = false;
			}
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		int s, e;
		cin >> s >> e;
		int result = bfs(s, e);
		if (result == -1) cout << "IMPOSSIBLE\n";
		else cout << result << "\n";
	}
}