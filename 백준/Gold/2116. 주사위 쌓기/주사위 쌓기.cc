#include <iostream>

using namespace std;

int n;
int oppositeIndex[6] = { 5,3,4,1,2,0 };
int dice[10001][6];
int solve(int topIndex)
{
	int result = 0;
	int maxNum = 0;
	int top = dice[0][topIndex];
	for (int i = 0; i < 6; i++)
	{
		if (i != topIndex && i != oppositeIndex[topIndex])
		{
			maxNum = max(maxNum, dice[0][i]);
		}
	}
	result += maxNum;
	for (int i = 1; i < n; i++)
	{
		int bottomIndex = 0;
		for (int j = 0; j < 6;j++)
		{
			if (dice[i][j] == top)
			{
				bottomIndex = j;
				topIndex = oppositeIndex[bottomIndex];
				top = dice[i][topIndex];
				break;
			}
		}
		maxNum = 0;
		for (int j = 0; j < 6; j++)
		{
			if (j != bottomIndex && j != topIndex)
			{
				maxNum = max(maxNum, dice[i][j]);
			}
		}
		result += maxNum;
	}
	return result;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> dice[i][j];
		}
	}
	int result = 0;
	for (int i = 0; i < 6; i++)
	{
		result = max(result, solve(i));
	}
	cout << result;
}