#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int n,l;
int board[101][101];
bool visited[101];
bool CanSetRunwayVertical(int x, int startY,int endY)
{
	if (startY < 0 || endY >= n)return false;
	int num = board[startY][x];
	for (int i = startY; i <= endY; i++)
	{
		if (board[i][x] != num)return false;
		if (visited[i])return false;
		visited[i] = true;
	}
	return true;
}
bool CheckVertical(int x)
{
	memset(visited, false, sizeof(visited));
	for (int i = 1; i < n; i++)
	{
		if (abs(board[i][x] - board[i - 1][x]) > 1)return false;
		if (board[i][x] > board[i - 1][x])
		{
			if (!CanSetRunwayVertical(x, i - l, i - 1))return false;
		}
		if (board[i][x] < board[i - 1][x])
		{
			if (!CanSetRunwayVertical(x, i, i + l - 1))return false;
		}
	}
	return true;
}
bool CanSetRunwayHorizontal(int y, int startX, int endX)
{
	if (startX < 0 || endX >= n)return false;
	int num = board[y][startX];
	for (int i = startX; i <= endX; i++)
	{
		if (board[y][i] != num)return false;
		if (visited[i])return false;
		visited[i] = true;
	}
	return true;
}
bool CheckHorizontal(int y)
{
	memset(visited, false, sizeof(visited));
	for (int i = 1; i < n; i++)
	{
		if (abs(board[y][i] - board[y][i - 1]) > 1)return false;
		if (board[y][i] > board[y][i-1])
		{
			if (!CanSetRunwayHorizontal(y, i - l, i - 1))return false;
		}
		if (board[y][i] < board[y][i-1])
		{
			if (!CanSetRunwayHorizontal(y, i, i + l - 1))return false;
		}
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		if (CheckHorizontal(i))
			result++;
		if (CheckVertical(i))
			result++;
	}
	cout << result;
}