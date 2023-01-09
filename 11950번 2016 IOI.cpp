#include <iostream>

using namespace std;

int n, m;
char board[51][51];
int solve(int firstIndex,int secondIndex)
{
	int ret = 0;
	for (int i = 0; i <= firstIndex; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] != 'W')ret++;
	
	for (int i = firstIndex + 1; i <= secondIndex; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] != 'B')ret++;

	for (int i = secondIndex + 1; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] != 'R') ret++;

	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	int result = 2e9;

	for (int i = 0; i < n - 2; i++)
		for (int j = i + 1; j < n - 1; j++)
			result = min(result, solve(i, j));

	cout << result;
}