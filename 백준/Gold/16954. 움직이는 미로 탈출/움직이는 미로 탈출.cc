#include <iostream>
#include <queue>

using namespace std;

char board[8][8];
bool visited[8][8];
int dirY[9] = { -1,-1,-1,0,1,1,1,0,0 };
int dirX[9] = { -1,0,1,1,1,0,-1,-1,0 };
void Bfs()
{
	queue<pair<int, int>> q;
	q.push({ 7,0 });
	int level = 0;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			pair<int, int> cur = q.front();
			q.pop();
			for (int j = 0; j < 9; j++)
			{
				int nextY = cur.first + dirY[j];
				int nextX = cur.second + dirX[j];
				if (0 <= nextY && nextY < 8 && 0 <= nextX && nextX < 8)
				{
					if (nextY - level < 0 || board[nextY - level][nextX] == '.')
					{
						if (nextY - level - 1 < 0 || board[nextY - level - 1][nextX] == '.')
						{
							if (nextY == 0 && nextX == 7)
							{
								cout << "1";
								return;
							}
							q.push({ nextY,nextX });
						}
					}
				}
			}
		}
		level++;
	}
	cout << "0";
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> board[i][j];
		}
	}
	Bfs();
}