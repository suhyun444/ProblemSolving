#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

bool hasKey[27];
bool visited[101][101];
char board[101][101];
queue < pair<int, int>> q;
int h, w;
int dirY[4] = { 0,0,-1,1 };
int dirX[4] = { 1,-1,0,0 };
void initQueue()
{
	for (int i = 0; i < h; i++)
	{
		if (board[i][0] == '.' || board[i][0] == '$' || ('a' <= board[i][0] && board[i][0] <= 'z'))
		{
			q.push({ i,0 });
			visited[i][0] = true;
		}
		if ('A' <= board[i][0] && board[i][0] <= 'Z' && hasKey[board[i][0] - 'A'])
		{
			q.push({ i,0 });
			visited[i][0] = true;
		}
		if (board[i][w - 1] == '.' || board[i][w-1] == '$' || ('a' <= board[i][w-1] && board[i][w-1] <= 'z'))
		{
			q.push({ i,w - 1 });
			visited[i][w - 1] = true;
		}
		if ('A' <= board[i][w - 1] && board[i][w - 1] <= 'Z' && hasKey[board[i][w - 1] - 'A'])
		{
			q.push({ i,w - 1 });
			visited[i][w - 1] = true;
		}
	}
	for (int i = 1; i < w - 1; i++)
	{
		if (board[0][i] == '.' || board[0][i] == '$' || ('a' <= board[0][i] && board[0][i] <= 'z'))
		{
			q.push({ 0,i });
			visited[0][i] = true;
		}
		if ('A' <= board[0][i] && board[0][i] <= 'Z' && hasKey[board[0][i] - 'A'])
		{
			q.push({ 0,i });
			visited[0][i] = true;
		}
		if (board[h - 1][i] == '.' || board[h-1][i] == '$' || ('a' <= board[h-1][i] && board[h-1][i] <= 'z'))
		{
			q.push({ h - 1,i });
			visited[h - 1][i] = true;
		}
		if ('A' <= board[h - 1][i] && board[h - 1][i] <= 'Z' && hasKey[board[h - 1][i] - 'A'])
		{
			q.push({ h - 1,i });
			visited[h - 1][i] = true;
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
		memset(visited, false, sizeof(visited));
		memset(hasKey, false, sizeof(hasKey));
		cin >> h >> w;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++) {
				cin >> board[i][j];
			}
		}
		string key;
		cin >> key;
		if (key != "0")
		{
			for (int i = 0; i < key.size(); i++)
			{
				hasKey[key[i] - 'a'] = true;
			}
		}
		initQueue();
		int cnt = 0;
		while (!q.empty())
		{
			pair<int, int> cur = q.front();
			q.pop();
			if ('a' <= board[cur.first][cur.second] && board[cur.first][cur.second] <= 'z')
			{
				hasKey[board[cur.first][cur.second] - 'a'] = true;
				board[cur.first][cur.second] = '.';
				memset(visited, false, sizeof(visited));
				while (!q.empty())q.pop();
				initQueue();
			}
			if (board[cur.first][cur.second] == '$')
			{
				cnt++;
				board[cur.first][cur.second] = '.';
			}
			for (int i = 0; i < 4; i++)
			{
				int nextY = cur.first + dirY[i];
				int nextX = cur.second + dirX[i];
				if (0 <= nextX && nextX < w && 0 <= nextY && nextY < h)
				{
					if (!visited[nextY][nextX])
					{
						if (board[nextY][nextX] == '.' || ('a' <= board[nextY][nextX] && board[nextY][nextX] <= 'z')  || board[nextY][nextX] == '$')
						{
							q.push({ nextY,nextX });
							visited[nextY][nextX] = true;
						}
						else if ('A' <= board[nextY][nextX] && board[nextY][nextX] <= 'Z' && hasKey[board[nextY][nextX] - 'A'])
						{
							q.push({ nextY,nextX });
							visited[nextY][nextX] = true;
						}
					}
				}
			}
		}
		cout << cnt << "\n";
	}
}