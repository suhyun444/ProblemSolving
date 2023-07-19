#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int r, c;
char board[101][101];
bool visited[101][101];
int dirY[4] = { 0,0,-1,1 };
int dirX[4] = { 1,-1,0,0 };
void FloorBfs(int y,int x)
{
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = true;
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextY = cur.first + dirY[i];
			int nextX = cur.second + dirX[i];
			if (0 <= nextY && nextY < r && 0 <= nextX && nextX < c)
			{
				if (board[nextY][nextX] == 'x' && !visited[nextY][nextX])
				{
					q.push({ nextY,nextX });
					visited[nextY][nextX] = true;
				}
			}
		}
	}
}
void FallMineral()
{
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < c; i++)
	{
		if (board[r-1][i] == 'x' && !visited[r-1][i])
		{
			FloorBfs(r - 1, i);
		}
	}
	int minFallDist = r;
	bool find = false;
	for (int i = r-1; i >= 0; i--)
	{
		for (int j = 0; j < c; j++)
		{
			if (board[i][j] == 'x' && !visited[i][j])
			{
				int nextY = i;
				for (int k = i; k < r; k++)
				{
					if (visited[k][j])
					{
						break;
					}
					nextY = k;
				}
				minFallDist = min(nextY - i, minFallDist);
			}
		}
	}	
	for (int i = r - 1; i >= 0; i--)
	{
		for (int j = 0; j < c; j++)
		{
			if (board[i][j] == 'x' && !visited[i][j])
			{
				board[i][j] = '.';
				board[i + minFallDist][j] = 'x';
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];
		}
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int y;
		cin >> y;
		y = r - y;
		if (i % 2 == 0) //왼쪽
		{
			for (int j = 0; j < c; j++)
			{
				if (board[y][j] == 'x')
				{
					board[y][j] = '.';
					break;
				}
			}
		}
		else // 오른쪽
		{
			for (int j = c-1; j >= 0; j--)
			{
				if (board[y][j] == 'x')
				{
					board[y][j] = '.';
					break;
				}
			}
		}
		FallMineral();
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << board[i][j];
		}
		cout << "\n";
	}

}