#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;
	int x, y = -1;
	for (int i = 0; i < a.length(); ++i)
	{
		for (int j = 0; j < b.length(); ++j)
		{
			if (a[i] == b[j])
			{
				x = i;
				y = j;
				break;
			}
		}
		if (y != -1)break;
	}
	char board[31][31];
	for (int i = 0; i < 31; ++i)for (int j = 0; j < 31; ++j)board[i][j] = '.';
	for (int i = 0; i < a.length(); ++i)board[y][i] = a[i];
	for (int i = 0; i < b.length(); ++i)board[i][x] = b[i];
	for (int i = 0; i < b.length(); ++i)
	{
		for (int j = 0; j < a.length(); ++j)
		{
			cout << board[i][j];
		}
		cout << "\n";
	}
}