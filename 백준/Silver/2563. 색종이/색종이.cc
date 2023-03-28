#include <iostream>

using namespace std;

int board[101][101];
void paintBoard(int x, int y)
{
	for (int i = y; i < y + 10; i++)
	{
		for (int j = x; j < x + 10; j++)
		{
			board[i][j] = 1;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		paintBoard(x, y);
	}
	int result = 0;
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (board[i][j] == 1)result++;
		}
	}
	cout << result;
}