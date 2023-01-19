#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
vector<pair<int, int>> virusPosition;
vector<pair<int, int>> enabledVirus;
int emptyBoxCount = 0;
int board[51][51];
bool visited[51][51];
int dirY[4] = { 0,0,1,-1 };
int dirX[4] = { 1,-1,0,0 };
bool CheckEnd(int curEmptyBoxCount)
{
	return curEmptyBoxCount == emptyBoxCount;
}
int Bfs()
{
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	for (int i = 0; i < m; i++)
	{
		visited[enabledVirus[i].first][ enabledVirus[i].second] = true;
		q.push(enabledVirus[i]);
	}
	if (CheckEnd(0))return 0;
	int level = 0;
	int curEmptyBoxCount = 0;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			pair<int, int> cur = q.front();
			q.pop();
			for (int j = 0; j < 4; j++)
			{
				int nextY = cur.first + dirY[j];
				int nextX = cur.second + dirX[j];
				if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n)
				{
					if (!visited[nextY][nextX] && board[nextY][nextX] != 1)
					{
						if (board[nextY][nextX] == 0)curEmptyBoxCount++;
						visited[nextY][nextX] = true;
						q.push({ nextY,nextX });
					}
				}
			}
		}
		level++;
		if (CheckEnd(curEmptyBoxCount))return level;
	}
	return 1e9;
}
int Solve(int startIndex)
{
	if (enabledVirus.size() == m)
	{
		return Bfs();
	}
	int result = 2e9;
	for (int i = startIndex; i < virusPosition.size(); i++)
	{
		enabledVirus.push_back(virusPosition[i]);
		result = min(result,Solve(i + 1));
		enabledVirus.pop_back();
	}
	return result;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 0)emptyBoxCount++;
			if (board[i][j] == 2)
			{
				virusPosition.push_back({ i,j });
			}
		}
	}
	int result = Solve(0);
	if (result == 1e9)cout << "-1";
	else cout << result;
}