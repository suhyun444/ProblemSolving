#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int dirY[4] = { -1,0,0,1 };
int dirX[4] = { 0,-1,1,0 };
char board[1001][1001];
int p[1000001];
int Find(int cur)
{
	if (p[cur] < 0)return cur;
	return p[cur] = Find(p[cur]);
}
bool Merge(int a,int b)
{
	a = Find(a);
	b = Find(b);
	if(a == b)	return false;
	p[b] = a;
	return true;
}
int BoardTypeToIndex(char type)
{
	switch (type)
	{
	case 'N':
		return 0;
	case 'W':
		return 1;
	case 'E':
		return 2;
	case 'S':
		return 3;
	default:
		break;
	}
}
void Dfs(int curY, int curX)
{
	int nextMoveType = BoardTypeToIndex(board[curY][curX]);
	int nextY = curY + dirY[nextMoveType];
	int nextX = curX + dirX[nextMoveType];
	int curIndex = curY * m + curX;
	int nextIndex = nextY * m + nextX;
	if (Merge(curIndex, nextIndex))
	{
		Dfs(nextY, nextX);
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
	for (int i = 0; i < n * m; i++)
		if (Find(i) == i)result++;
	cout << result;
}