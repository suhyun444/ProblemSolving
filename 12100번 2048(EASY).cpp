#include <iostream>
#include <cstring>

using namespace std;

int n;
int board[21][21];
int copyBoard[21][21];
bool check[21][21];
void moveLeft()
{
	memset(check, false, sizeof(check));
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			for (int k = j - 1; k >= 0; k--)
			{
				if (board[i][k] == 0 && k == 0)
				{
					board[i][k] = board[i][j];
					board[i][j] = 0;
				}
				if (board[i][k] == 0)continue;
				if (board[i][k] == board[i][j] && !check[i][k])
				{
					board[i][k] *= 2;
					board[i][j] = 0;
					check[i][k] = true;
					break;
				}
				if (board[i][k] != board[i][j] || check[i][k])
				{
					board[i][k + 1] = board[i][j];
					if(k + 1 != j)board[i][j] = 0;
					break;
				}
			}
		}
	}
}
void moveRight()
{
	memset(check, false, sizeof(check));
	for (int i = 0; i < n; i++)
	{
		for (int j = n-2; j >= 0; j--)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (board[i][k] == 0 && k == 0)
				{
					board[i][k] = board[i][j];
					board[i][j] = 0;
				}
				if (board[i][k] == 0)continue;
				if (board[i][k] == board[i][j] && !check[i][k])
				{
					board[i][k] *= 2;
					board[i][j] = 0;
					check[i][k] = true;
					break;
				}
				if (board[i][k] != board[i][j] || check[i][k])
				{
					board[i][k - 1] = board[i][j];
					if (k - 1 != j)board[i][j] = 0;
					break;
				}
			}
		}
	}
}
void moveUp()
{
	memset(check, false, sizeof(check));
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			for (int k = j - 1; k >= 0; k--)
			{
				if (board[k][i] == 0 && k == 0)
				{
					board[k][i] = board[j][i];
					board[j][i] = 0;
				}
				if (board[k][i] == 0)continue;
				if (board[k][i] == board[j][i] && !check[k][i])
				{
					board[k][i] *= 2;
					board[j][i] = 0;
					check[k][i] = true;
					break;
				}
				if (board[k][i] != board[j][i] || check[k][i])
				{
					board[k + 1][i] = board[j][i];
					if (k + 1 != j)board[j][i] = 0;
					break;
				}
			}
		}
	}
}
void moveDown()
{
	memset(check, false, sizeof(check));
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 2; j >= 0; j--)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (board[k][i] == 0 && k == 0)
				{
					board[k][i] = board[j][i];
					board[j][i] = 0;
				}
				if (board[k][i] == 0)continue;
				if (board[k][i] == board[j][i] && !check[k][i])
				{
					board[k][i] *= 2;
					board[j][i] = 0;
					check[k][i] = true;
					break;
				}
				if (board[k][i] != board[j][i] || check[k][i])
				{
					board[k-1][i] = board[j][i];
					if (k - 1 != j)board[j][i] = 0;
					break;
				}
			}
		}
	}
}
int dfs(int cnt)
{
	if (cnt == 5)
	{
		int maxBlock = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				maxBlock = max(maxBlock, board[i][j]);
			}
		}
		return maxBlock;
	}
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			copyBoard[i][j] = board[i][j];
		}
	}
	moveLeft();
	ret = max(ret,dfs(cnt + 1));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			board[i][j] = copyBoard[i][j];
		}
	}
	moveRight();
	ret = max(ret, dfs(cnt + 1));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			board[i][j] = copyBoard[i][j];
		}
	}
	moveDown();
	ret = max(ret, dfs(cnt + 1));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			board[i][j] = copyBoard[i][j];
		}
	}
	moveUp();
	ret = max(ret, dfs(cnt + 1));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	cout <<  dfs(0);
	
}