#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char board[5][5];
bool isChecked[5][5];
bool visited[5][5];
int dirX[4] = { 0,0,1,-1 };
int dirY[4] = { 1,-1,0,0 };
int ans;
vector<int> back;
int dfs(int y,int x)
{
	int num = 1;
	for (int i = 0; i < 4; i++)
	{
		int nextY = y + dirY[i];
		int nextX = x + dirX[i];
		if (0 <= nextY && nextY < 5 && 0 <= nextX && nextX < 5)
		{
			if (isChecked[nextY][nextX] && !visited[nextY][nextX])
			{
				visited[nextY][nextX] = true;
				num += dfs(nextY, nextX);
			}
		}
	}
	return num;
}
bool IsAdj()
{
	memset(isChecked, false, sizeof(isChecked));
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < back.size(); i++)
	{
		isChecked[back[i] / 5][back[i] % 5] = true;
	}
	int curY = back[0] / 5;
	int curX = back[0] % 5;
	visited[curY][curX] = true;
	int num = dfs(curY, curX);
	if (num == 7) return true;
	return false;
}
void backTracking(int n,int cnt)
{
	if (cnt == 7)
	{
		int cntS = 0;
		for (int i = 0; i < back.size(); i++)
		{
			if (board[back[i] / 5][back[i] % 5] == 'S')cntS++;
		}
		if (cntS < 4)return;
		if (IsAdj())ans++;
		return;
	}
	for (int i = n; i < 25; i++)
	{
		back.push_back(i);
		backTracking(i + 1, cnt + 1);
		back.pop_back();
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> board[i][j];
		}
	}
	backTracking(0,0);
	cout << ans;
}