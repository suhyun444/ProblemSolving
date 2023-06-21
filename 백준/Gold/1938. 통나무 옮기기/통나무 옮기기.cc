#include <iostream>
#include <queue>

using namespace std;

int n;
bool visited[52][52][2];
char board[51][51];
int dirY[4] = { 0,1,0,-1 };
int dirX[4] = { 1,0,-1,0 };
bool CanPlace(int y,int x,int rotateType)
{
	if (rotateType == 0)
		for (int i = -1; i <= 1; i++)
			if (x + i < 0 || x + i >= n || board[y][x + i] == '1')return false;
	if (rotateType == 1)
		for (int i = -1; i <= 1; i++)
			if (y + i < 0 || y + i >= n || board[y + i][x] == '1')return false;
	return true;
}
bool CanRotate(int y, int x)
{
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (y + i < 0 || y + i >= n || x + j < 0 || x + j >= n)return false;
			if (board[y + i][x + j] == '1')
				return false;
		}
	}
	return true;
}
int bfs(pair<pair<int, int>, int> start, pair<pair<int, int>, int> end)
{
	queue < pair<pair<int, int>, int>> q;
	q.push(start);
	visited[start.first.first][start.first.second][start.second] = true;
	int level = 0;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			pair<pair<int, int>, int> cur = q.front();
			q.pop();
			for (int j = 0; j < 4; j++)
			{
				int nextY = cur.first.first + dirY[j];
				int nextX = cur.first.second + dirX[j];
				int rotateType = cur.second;
				if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n)continue;
				if (visited[nextY][nextX][rotateType])continue;
				if (CanPlace(nextY, nextX, rotateType))
				{
					visited[nextY][nextX][rotateType] = true;
					q.push({ {nextY,nextX},rotateType });
					if (nextY == end.first.first && nextX == end.first.second && rotateType == end.second)
						return level + 1;
				}
			}
			if (!visited[cur.first.first][cur.first.second][!cur.second] &&  CanRotate(cur.first.first, cur.first.second))
			{
				visited[cur.first.first][cur.first.second][!cur.second] = true;
				q.push({ {cur.first.first,cur.first.second},!cur.second });
				if (cur.first.first == end.first.first && cur.first.second == end.first.second && cur.second != end.second)
					return level + 1;
			}
		}
		level++;
	}
	return 0;
}
int main()
{
	pair<pair<int, int>, int> start = { {-1,-1},-1 };
	pair<pair<int, int>, int> end = { {-1,-1},-1 };
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (start.first.first == -1 && board[i][j] == 'B' && j + 1 < n && board[i][j + 1] == 'B')
				start = { {i,j + 1},0 };
			if (start.first.first == -1 && board[i][j] == 'B' && i + 1 < n && board[i + 1][j] == 'B')
				start = { {i + 1,j},1 };
			if (end.first.first == -1 && board[i][j] == 'E' && j + 1 < n && board[i][j + 1] == 'E')
				end = { {i,j + 1},0 };
			if (end.first.first == -1 && board[i][j] == 'E' && i + 1 < n && board[i + 1][j] == 'E')
				end = { {i + 1,j},1 };
		}
	}
	cout << bfs(start, end);
}