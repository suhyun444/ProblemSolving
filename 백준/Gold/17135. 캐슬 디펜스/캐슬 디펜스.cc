#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int n, m, d;
int board[16][16];
int copyBoard[16][16];
int dirY[3] = { 0,-1,0 };
int dirX[3] = { -1,0,1 };
vector<pair<int, int>> backTracking;
pair<int, int> FindNearestEnemy(int y, int x)
{
	bool visited[16][16];
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = true;
	int level = 0;
	while (!q.empty())
	{
		if (level == d) return { -1,-1 };
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			pair<int, int> cur = q.front();
			q.pop();
			for (int j = 0; j < 3; j++)
			{
				int nextY = cur.first + dirY[j];
				int nextX = cur.second + dirX[j];
				if (0 <= nextY && nextY < n && 0 <= nextX && nextX < m)
				{
					if (!visited[nextY][nextX])
					{
						if (copyBoard[nextY][nextX] == 1)
						{
							return { nextY,nextX };
						}
						q.push({ nextY,nextX });
						visited[nextY][nextX] = true;
					}
				}
			}
		}
		level++;
	}
	return { -1,-1 };
}
bool CheckEnd()
{
	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (copyBoard[i][j] == 1)return false;
		}
	}
	return true;
}
void MoveBoard()
{
	for (int i = 0; i < m; i++)
		copyBoard[n - 1][i] = 0;
	for (int i = n-2; i >= 0; i--)
	{
		for (int j = 0; j < m; j++)
		{
			copyBoard[i + 1][j] = copyBoard[i][j];
			copyBoard[i][j] = 0;
		}
	}
}
void CopyBoard()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			copyBoard[i][j] = board[i][j];
		}
	}
}
int Solve()
{
	int eliminationCount = 0;
	CopyBoard();
	while (true)
	{
		if (CheckEnd())
		{
			return eliminationCount;
		}
		pair<int, int> targetEnemy[3];
		for (int i = 0; i < 3; i++)
		{
			targetEnemy[i] = FindNearestEnemy(backTracking[i].first, backTracking[i].second);
		}
		for (int i = 0; i < 3; i++)
		{
			if (targetEnemy[i].first == -1)continue;
			if (copyBoard[targetEnemy[i].first][targetEnemy[i].second] == 1)
			{
				eliminationCount++;
				copyBoard[targetEnemy[i].first][targetEnemy[i].second] = 0;
			}
		}
		MoveBoard();
	}
}
int SetArcherPosition(int index, int l)
{
	int result = 0;
	if (l == 3)
	{
		return Solve();
	}
	for (int i = index; i <= m; i++)
	{
		backTracking.push_back({n, i});
		result = max(result,SetArcherPosition(index + 1, l + 1));
		backTracking.pop_back();
	}
	return result;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	cout << SetArcherPosition(0, 0);
}