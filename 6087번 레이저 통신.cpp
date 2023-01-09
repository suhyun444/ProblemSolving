#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int w, h;
int dirX[4] = { 1,0,-1,0 };
int dirY[4] = { 0,1,0,-1 };
int visited[101][101];
char board[101][101];
int startX, startY = -1;
int endX, endY;
int ans = 2e9;
void bfs()
{
	queue < pair<pair<int, int>, pair<int, int>>> q;
	// y좌표, x좌표, 방향, 몇번꺾었는지
	q.push({ {startY,startX},{0,0} });
	q.push({ {startY,startX},{1,0} });
	q.push({ {startY,startX},{2,0} });
	q.push({ {startY,startX},{3,0} });
	for (int i = 0; i < 4; i++)visited[startY][startX] = 0;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			pair<pair<int, int>, pair<int, int>> cur = q.front();
			q.pop();
			if (cur.first.first == endY && cur.first.second == endX)
			{
				ans = min(ans, cur.second.second);
			}
			for (int j = 0; j < 4; j++)
			{
				int nextY = cur.first.first + dirY[j];
				int nextX = cur.first.second + dirX[j];
				if (0 <= nextX && nextX < w && 0 <= nextY && nextY < h)
				{
					if (board[nextY][nextX] != '*')
					{
						if (j == cur.second.first)
						{
							if (visited[nextY][nextX] > cur.second.second)
							{
								q.push({ { nextY,nextX }, {j,cur.second.second} });
								visited[nextY][nextX] = cur.second.second;

							}
						}
						else
						{
							if (visited[nextY][nextX] > cur.second.second + 1)
							{
								q.push({ { nextY,nextX }, {j,cur.second.second + 1} });
								visited[nextY][nextX] = cur.second.second + 1;
							}
						}
					}
				}
			}
		}
	}
}
int main()
{
	for (int i = 0; i < 4; i++)for (int j = 0; j < 101; j++)for (int k = 0; k < 101; k++)visited[j][k] = 2e9;
	cin >> w >> h;
	for (int i = 0; i < h; i++)
	{
		for(int j=0;j<w;j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'C')
			{
				if (startY == -1)
				{
					startY = i;
					startX = j;
				}
				else
				{
					endY = i;
					endX = j;
				}
			}
		}
	}
	bfs();
	cout << ans << "\n";
}