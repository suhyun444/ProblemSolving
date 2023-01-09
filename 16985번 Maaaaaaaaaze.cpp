#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool visited[5][5][5];
int board[5][5][5];
int order[5];//각 index층에 무슨종류의 판이 들어있는지
int type[5]; //각 index의 판이 몇도 돌아가 있는지 0 == 그대로, 1 == 90도, 2 == 180도, 3 == 270도
// 90도
// board[4 - x][y]
// 180도
// board[4 - y][4 - x]
// 270도
// board[x][4 - y]
// 
//board[z][y][x];
int dirZ[6] = { 1,-1,0,0,0,0 };
int dirX[6] = { 0,0,1,-1,0,0 };
int dirY[6] = { 0,0,0,0,1,-1 };
int ans = 2e9;
bool usedMaze[5];
int copyBoard[5][5][5];
pair<int, int> GetRotationIndex(pair<int, int> p, int stat)
{
	if (stat == 0)
		return p;
	if (stat == 1)
		return { 4 - p.second, p.first };
	if (stat == 2)
		return { 4 - p.first, 4 - p.second };
	if (stat == 3)
		return { p.second, 4 - p.first };
}
int bfs()
{
	memset(visited, false, sizeof(visited));
	queue < pair<int, pair<int, int>>> q;
	q.push({ 0,{0,0} });
	visited[0][0][0] = false;
	int level = 0;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			pair<int, pair<int, int>> cur = q.front();
			if (cur.first == 4 && cur.second.first == 4 && cur.second.second == 4)
			{
				return level;
			}
			q.pop();
			for (int j = 0; j < 6; j++)
			{
				int nextZ = cur.first + dirZ[j];
				int nextY = cur.second.first + dirY[j];
				int nextX = cur.second.second + dirX[j];
				if (0 <= nextZ && nextZ < 5 && 0 <= nextY && nextY < 5 && 0 <= nextX && nextX < 5)
				{
					if (!visited[nextZ][nextY][nextX] && copyBoard[nextZ][nextY][nextX] == 1)
					{
						visited[nextZ][nextY][nextX] = true;
						q.push({ nextZ,{nextY,nextX}});
					}
				}
			}
		}
		level++;
	}
	return 2e9;
}
void MakeMaze()
{
	for (int i = 0; i < 5; i++)
	{
		int zIndex = order[i];
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				pair<int, int> rotatedIndex = GetRotationIndex({ j,k }, type[zIndex]);
				copyBoard[i][j][k] = board[zIndex][rotatedIndex.first][rotatedIndex.second];
			}
		}
	}
}
void RotateMaze()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				for (int l = 0; l < 4; l++)
				{
					for (int p = 0; p < 4; p++)
					{
						type[0] = i;
						type[1] = j;
						type[2] = k;
						type[3] = l;
						type[4] = p;
						MakeMaze();
						if (copyBoard[0][0][0] == 0 || copyBoard[4][4][4] == 0)continue;
						ans = min(ans, bfs());
						if (ans == 12)
						{
							cout << ans;
							exit(0);
						}
					}
				}
			}
		}
	}
}
void MixMaze(int count)
{
	if (count == 5)
	{
		RotateMaze();
	}
	for (int i = 0; i < 5; i++)
	{
		if (usedMaze[i])continue;
		usedMaze[i] = true;
		order[count] = i;
		MixMaze(count + 1);
		usedMaze[i] = false;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				cin >> board[i][j][k];
			}
		}
	}
	MixMaze(0);
	if (ans == 2e9)
	{
		cout << "-1";
	}
	else
	{
		cout << ans;
	}
}