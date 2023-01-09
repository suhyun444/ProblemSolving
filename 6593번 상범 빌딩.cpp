#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
typedef pair<int, pair<int, int>> piii;

char board[30][30][30];
bool visited[30][30][30];
int dirX[6] = { 0,0,1,-1,0,0 };
int dirY[6] = { 1,-1,0,0,0,0 };
int dirZ[6] = { 0,0,0,0,1,-1 };
int bfs(int l, int r, int c,int sX,int sY, int sZ)
{
	queue<piii> q;
	q.push({ sY,{sX,sZ} });
	visited[sY][sX][sZ] = true;
	int level = 0;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			piii cur = q.front();
			q.pop();
			for (int j = 0; j < 6; j++)
			{
				int nextY = cur.first + dirY[j];
				int nextX = cur.second.first + dirX[j];
				int nextZ = cur.second.second + dirZ[j];
				if (0 <= nextX && nextX < c && 0 <= nextY && nextY < r && 0 <= nextZ && nextZ < l)
				{
					if (board[nextY][nextX][nextZ] == 'E')
					{
						return level + 1;
					}
					if (!visited[nextY][nextX][nextZ] && board[nextY][nextX][nextZ] == '.')
					{
						visited[nextY][nextX][nextZ] = true;
						q.push({ nextY, { nextX,nextZ } });
					}
				}
			}
		}
		level++;
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (true)
	{
		int l, r, c;
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0)return 0;
		int sX, sY, sZ;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < r; j++)
			{
				for (int k = 0; k < c; k++)
				{
					//[y][x][z];
					cin >> board[j][k][i];
					if (board[j][k][i] == 'S')
					{
						sY = j;
						sX = k;
						sZ = i;
					}
				}
			}
		}
		int result = bfs(l, r, c, sX, sY,sZ);
		if (result == -1)
		{
			cout << "Trapped!\n";
		}
		else
		{
			cout << "Escaped in " << result << " minute(s).\n";
		}
	}
}