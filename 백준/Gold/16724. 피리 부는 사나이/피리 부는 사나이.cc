#include <iostream>
#include <cstring>

using namespace std;

int n, m;
char board[1001][1001];
int p[1000001];
int dirY[4] = { -1,1,0,0 };
int dirX[4] = { 0,0,-1,1 };
int BoardTypeToMoveType(char type)
{
	switch (type)
	{
	case 'U':
		return 0;
	case 'D':
		return 1;
	case 'L':
		return 2;
	case 'R':
		return 3;
	}
}
int PositionToIndex(int y, int x)
{
	return x + m * y;
}
int Find(int cur)
{
	if (p[cur] < 0)return cur;
	return p[cur] = Find(p[cur]);
}
bool Merge(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a == b)return false;
	p[b] = a;
	return true;
}
void Dfs(int curY, int curX)
{
	char boardType = board[curY][curX];
	int moveType = BoardTypeToMoveType(boardType);
	int nextY = curY + dirY[moveType];
	int nextX = curX + dirX[moveType];
	int curIndex = PositionToIndex(curY, curX);
	int nextIndex = PositionToIndex(nextY, nextX);
	if (0 <= nextY && nextY < n && 0 <= nextX && nextX < m)
	{
		if (Merge(curIndex, nextIndex))
		{
			Dfs(nextY, nextX);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(p, -1, sizeof(p));
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			Dfs(i, j);
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (p[j + i * m] == -1)
			{
				result++;
			}
		}
	}
	cout << result;
}