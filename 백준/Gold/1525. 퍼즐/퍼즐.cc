#include <iostream>
#include <map>
#include <queue>

using namespace std;

int dirIndex[4] = { -1,-3,1,3 };
int dirY[4] = { 0,-1,0,1 };
int dirX[4] = { -1,0,1,0 };
int main()
{
	map<string, int> visited;
	string start;
	for (int i = 0; i < 9; i++)
	{
		char cur;
		cin >> cur;
		start += cur;
	}
	queue<string> q;
	visited.insert({ start,1 });
	q.push(start);
	int level = 0;
	while (!q.empty())
	{
		int size = q.size();
		for(int k=0;k<size;k++)
		{
			string cur = q.front();
			q.pop();
			if (cur == "123456780")
			{
				cout << level;
				return 0;
			}
			int zeroPosition = -1;
			for (int i = 0; i < 9; i++)if (cur[i] == '0')zeroPosition = i;
			for (int i = 0; i < 4; i++)
			{
				string next = cur;
				int curY = zeroPosition / 3;
				int curX = zeroPosition % 3;
				int nextY = curY + dirY[i];
				int nextX = curX + dirX[i];
				if (0 <= nextY && nextY < 3 && 0 <= nextX && nextX < 3)
				{
					swap(next[zeroPosition], next[zeroPosition + dirIndex[i]]);
					if (visited.find(next) == visited.end())
					{
						visited.insert({ next,1 });
						q.push(next);
					}
				}
			}
		}
		level++;
	}
	cout << "-1";
}