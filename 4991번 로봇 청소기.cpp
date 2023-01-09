#include <iostream>
#include <queue>
#include <cstring>;

using namespace std;

int w, h;
int dirtyCount;
int dirY[4] = { 0,0,1,-1 };
int dirX[4] = { 1,-1,0,0 };
char board[21][21];
bool visited[21][21];
bool dfsVisited[10];
pair<int,int> point[10];
vector<pair<int,int>> adj[10];
int bfs(int curIndex)
{
	memset(visited, false , sizeof(visited));
	queue<pair< int, int>> q;
	q.push({ point[curIndex].first,point[curIndex].second});
	visited[point[curIndex].first][point[curIndex].second] = true;

	int level = 1;
	while (!q.empty())
	{
		int size = q.size();
		while (size--)
		{
			pair<int, int> cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nextY = cur.first + dirY[i];
				int nextX = cur.second + dirX[i];
				if (0 <= nextY && nextY < h && 0 <= nextX && nextX < w)
				{
					if (!visited[nextY][nextX] && board[nextY][nextX] != 'x')
					{
						visited[nextY][nextX] = true;
						if (board[nextY][nextX] != '.')
						{
							int index = board[nextY][nextX] - '0';
							adj[curIndex].push_back({ index, level });
							q.push({ nextY,nextX });
						}
						else
						{
							q.push({nextY,nextX});
						}
					}
				}
			}
		}
		level++;
	}
	return -1;
}
int dfs(int cur,int length)
{
	if (length == dirtyCount)return 0;
	int num = 2e9;
	for (pair<int, int> next : adj[cur])
	{
		if (!dfsVisited[next.first])
		{
			dfsVisited[cur] = true;
			num = min(num, dfs(next.first,length + 1) + next.second);
			dfsVisited[cur] = false;
		}
	}
	return num;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (true)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)return 0;
		dirtyCount = 1;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> board[i][j];
				if (board[i][j] == 'o')
				{
					board[i][j] = '0';
					point[0] = { i,j };
				}
				else if (board[i][j] == '*')
				{
					board[i][j] = ('0' + dirtyCount);
					point[dirtyCount++] = { i,j };

				}
			}
		}
		for (int i = 0; i < dirtyCount; i++)
		{
			bfs(i);
		}
		memset(dfsVisited, false, sizeof(dfsVisited));
		int result = dfs(0, 1);
		if (result == 2e9)
			cout << "-1\n";
		else cout << result << "\n";
		for (int i = 0; i < dirtyCount; i++)
		{
			adj[i].clear();
		}
	}
}