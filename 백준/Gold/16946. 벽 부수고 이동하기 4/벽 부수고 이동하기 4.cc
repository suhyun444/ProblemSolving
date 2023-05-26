#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
char board[1001][1001];
pair<int,int> dfsBoard[1001][1001];
bool visited[1001][1001];
int dirY[4] = { 0,0,-1,1 };
int dirX[4] = { 1,-1,0,0 };
int Dfs(int curY, int curX)
{
	int num = 1;
	visited[curY][curX] = true;
	for (int i = 0; i < 4; i++)
	{
		int nextY = curY + dirY[i];
		int nextX = curX + dirX[i];
		if (0 <= nextY && nextY < n && 0 <= nextX && nextX < m)
		{
			if (!visited[nextY][nextX] && board[nextY][nextX] == '0')
			{
				num += Dfs(nextY, nextX);
			}
		}
	}
	return num;
}
void SetDfs(int curY, int curX,int value,int group)
{
	int num = 1;
	dfsBoard[curY][curX] = { group,value };
	for (int i = 0; i < 4; i++)
	{
		int nextY = curY + dirY[i];
		int nextX = curX + dirX[i];
		if (0 <= nextY && nextY < n && 0 <= nextX && nextX < m)
		{
			if (dfsBoard[nextY][nextX].second == 0 && board[nextY][nextX] == '0')
			{
				SetDfs(nextY, nextX,value,group);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<pair<int, int>> blocks;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == '1')blocks.push_back({ i,j });
		}
	}
	int groupIndex = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dfsBoard[i][j].second == 0 && board[i][j] == '0')
			{
				int point = Dfs(i, j);
				SetDfs(i, j, point, groupIndex);
				groupIndex++;
			}
		}
	}
	for (int i = 0; i < blocks.size(); i++)
	{
		pair<int, int> cur = blocks[i];
		int point = 1;
		for (int i = 0; i < 4; i++)
		{
			bool canAdd = true;
			if (cur.first + dirY[i] < 0 || cur.first + dirY[i] >= n || cur.second + dirX[i] < 0 || cur.second + dirX[i] >= m)continue;
			for (int j = i + 1; j < 4; j++)
			{
				if (cur.first + dirY[j] < 0 || cur.first + dirY[j] >= n || cur.second + dirX[j] < 0 || cur.second + dirX[j] >= m)continue;
				if (dfsBoard[cur.first + dirY[i]][cur.second + dirX[i]].first == dfsBoard[cur.first + dirY[j]][cur.second + dirX[j]].first)
				{
					canAdd = false;
				}
			}
			if (canAdd)	point += dfsBoard[cur.first + dirY[i]][cur.second + dirX[i]].second;
		}
		board[cur.first][cur.second] = (point%10) + '0';
	}
	for (int i = 0; i < n; i++)
	{	
		for (int j = 0; j < m; j++)
		{
			cout << board[i][j];
		}
		cout << "\n";
	}
}