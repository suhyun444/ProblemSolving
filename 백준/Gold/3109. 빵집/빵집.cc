#include <iostream>

using namespace std;

int r, c;
string board[10001];
bool dfs(int curY, int curX)
{
	board[curY][curX] = 'x';
	if (curX == c - 1)return true;
	for (int i = -1; i <= 1; i++)
	{
		int nextY = curY + i;
		if (0 <= nextY && nextY < r && board[nextY][curX + 1] == '.')
			if (dfs(nextY, curX + 1)) return true;
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		cin >> board[i];
	}
	int result = 0;
	for (int i = 0; i < r; i++)
	{
		if (dfs(i, 0)) result++;
	}
	cout << result;
}