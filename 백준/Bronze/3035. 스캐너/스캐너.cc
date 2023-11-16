#include <iostream>
#include <vector>

using namespace std;

char board[51][51];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int r, c, zr, zc;
	cin >> r >> c >> zr >> zc;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < r; ++i)
	{
		for (int l = 0; l < zr; ++l)
		{
			for (int j = 0; j < c; ++j)
			{
				for (int m = 0; m < zc; ++m)
				{
					cout << board[i][j];
				}
			}
			cout << "\n";
		}
	}
}
