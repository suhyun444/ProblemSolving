#include <iostream>

using namespace std;

int dirY[4] = { 1,0,-1,0 };
int dirX[4] = { 0,1,0,-1 };
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int curY = 0, curX = 0;
		int direction = 0;
		int minY = 0, minX = 0, maxY = 0, maxX = 0;
		string s;
		cin >> s;
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == 'F')
			{
				curY += dirY[direction];
				curX += dirX[direction];
				minY = min(minY, curY);
				minX = min(minX, curX);
				maxY = max(maxY, curY);
				maxX = max(maxX, curX);
			}
			else if (s[i] == 'R')
			{
				direction++;
				direction %= 4;
			}
			else if (s[i] == 'L')
			{
				--direction;
				if (direction < 0)direction = 3;
			}
			else if (s[i] == 'B')
			{
				curY -= dirY[direction];
				curX -= dirX[direction];
				minY = min(minY, curY);
				minX = min(minX, curX);
				maxY = max(maxY, curY);
				maxX = max(maxX, curX);
			}
		}
		cout << (maxX - minX) * (maxY - minY) << "\n";
	}
}