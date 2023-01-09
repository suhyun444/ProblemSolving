#include <iostream>

using namespace std;

int h, w;
int heights[501];
bool CanContainRain(int index, int height)
{
	bool left = false, right = false;
	for (int i = index - 1; i >= 0; i--)
	{
		if (heights[i] >= height)
		{
			left = true;
			break;
		}
	}
	for (int i = index + 1; i < w; i++)
	{
		if (heights[i] >= height)
		{
			right = true;
			break;
		}
	}
	return (left && right);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> h >> w;
	for (int i = 0; i < w; i++)
	{
		cin >> heights[i];
	}
	int result = 0;
	for (int i = 0; i < w; i++)
	{
		for (int j = heights[i] + 1; j <= h; j++)
		{
			if (CanContainRain(i, j))
			{
				result++;
			}
			else
			{
				break;
			}
		}
	}
	cout << result;
}