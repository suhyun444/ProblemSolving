#include <iostream>

using namespace std;

int ans = 2e9;
int dirY[5] = { 0,1,0,-1,0 };
int dirX[5] = { 0,0,1,0,-1 };
bool light[10][10];
bool CheckEnd()
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (light[i][j])return false;
		}
	}
	return true;
}
void Switch(int y, int x)
{
	for (int i = 0; i < 5; ++i)
	{
		int nextY = y + dirY[i];
		int nextX = x + dirX[i];
		if (0 <= nextY && nextY < 10 && 0 <= nextX && nextX < 10)
			light[nextY][nextX] = !light[nextY][nextX];
	}
}
void Solve(int count)
{
	bool copy[10][10];
	for (int i = 0; i < 10; ++i)for (int j = 0; j < 10; ++j)copy[i][j] = light[i][j];
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if (light[i - 1][j])
			{
				Switch(i, j);
				++count;
			}
		}
	}
	if (CheckEnd())
		ans = min(ans, count);
	for (int i = 0; i < 10; ++i)for (int j = 0; j < 10; ++j)light[i][j] = copy[i][j];
}
void FirstLine(int n,int count)
{
	if (n == 10)
	{
		Solve(count);
		return;
	}
	FirstLine(n + 1,count);
	Switch(0, n);
	FirstLine(n + 1,count + 1);
	Switch(0, n);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			char c;
			cin >> c;
			if (c == 'O')light[i][j] = true;
		}
	}
	FirstLine(0, 0);
	cout << ans;
}