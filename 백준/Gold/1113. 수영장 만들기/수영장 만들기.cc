#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
bool visited[52][52];
int board[52][52];
int dirY[4] = { 0,1,0,-1 };
int dirX[4] = { 1,0,-1,0 };
int bfs(int y, int x)
{
	int canStack = 2e9;
	int findNum = board[y][x];
	//가능한 만큼만 채우기
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = true;
	int numOfChange = 0;
	while (!q.empty())
	{
		numOfChange++;
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextY = cur.first + dirY[i];
			int nextX = cur.second + dirX[i];
			if (board[nextY][nextX] == findNum && !visited[nextY][nextX])
			{
				q.push({ nextY,nextX });
				visited[nextY][nextX] = true;
			}
			else if(board[nextY][nextX] != findNum)
			{
				canStack = min(canStack, board[nextY][nextX]);
			}
		}
	}
	if (canStack == 0 || canStack == 2e9 || canStack < findNum)return 0;
	//cout << "stack Num " << canStack << " , " << findNum << "\n";
	memset(visited, false, sizeof(visited));
	q.push({ y, x});
	visited[y][x] = true;
	
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		board[cur.first][cur.second] = canStack;
		for (int i = 0; i < 4; i++)
		{
			int nextY = cur.first + dirY[i];
			int nextX = cur.second + dirX[i];
			if (!visited[nextY][nextX])
			{
				if (board[nextY][nextX] == findNum)
				{
					q.push({ nextY,nextX });
					visited[nextY][nextX] = true;
				}
			}
		}
	}
	memset(visited, false, sizeof(visited));
	return numOfChange * (canStack - findNum);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char ch;
			cin >> ch;
			board[i][j] = ch - '0';
		}
	}
	int result = 0;
	while (true)
	{
		bool isFind = false;
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (!visited[i][j])
				{
					int point = bfs(i, j);
					result += point;
					if (point != 0)isFind = true;
				}
			}
		}
		if (!isFind)break;
	}
	cout << result;
}