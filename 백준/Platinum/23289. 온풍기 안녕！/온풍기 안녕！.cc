#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int r, c, k,w;
vector<pair<pair<int, int>,int>> heater;
vector<pair<int, int>> check;
bool wall[21][21][21][21];
int board[21][21];
int copyBoard[21][21];
bool visited[21][21];

void HeaterRight(int y, int x, int heat)
{
	if (y < 0 || y >= r || x < 0 || x >= c)return;
	if (visited[y][x])return;
	board[y][x] += heat;
	visited[y][x] = true;
	if (heat == 1)return;
	if (!wall[y][x][y][x + 1])
	{
		HeaterRight(y, x + 1, heat - 1);
	}
	if (!wall[y][x][y - 1][x] && !wall[y - 1][x][y - 1][x + 1])
	{
		HeaterRight(y - 1, x + 1, heat - 1);
	}
	if (!wall[y][x][y + 1][x] && !wall[y + 1][x][y + 1][x + 1])
	{
		HeaterRight(y + 1, x + 1, heat - 1);
	}
}
void HeaterLeft(int y, int x,int heat)
{
	if (y < 0 || y >= r || x < 0 || x >= c)return;
	if (visited[y][x])return;
	board[y][x] += heat;
	visited[y][x] = true;
	if (heat == 1)return;
	if (!wall[y][x][y][x - 1])
	{
		HeaterLeft(y, x - 1, heat - 1);
	}
	if (!wall[y][x][y - 1][x] && !wall[y - 1][x][y - 1][x - 1])
	{
		HeaterLeft(y - 1, x - 1, heat - 1);
	}
	if (!wall[y][x][y + 1][x] && !wall[y + 1][x][y + 1][x - 1])
	{
		HeaterLeft(y + 1, x - 1, heat - 1);
	}
}
void HeaterUp(int y, int x, int heat)
{
	if (y < 0 || y >= r || x < 0 || x >= c)return;
	if (visited[y][x])return;
	board[y][x] += heat;
	visited[y][x] = true;
	if (heat == 1)return;
	if (!wall[y][x][y - 1][x])
	{
		HeaterUp(y - 1, x, heat - 1);
	}
	if (!wall[y][x][y][x - 1] && !wall[y][x - 1][y - 1][x - 1])
	{
		HeaterUp(y - 1, x - 1, heat - 1);
	}
	if (!wall[y][x][y][x + 1] && !wall[y][x + 1][y - 1][x + 1])
	{
		HeaterUp(y - 1, x + 1, heat - 1);
	}
}
void HeaterDown(int y, int x, int heat)
{
	if (y < 0 || y >= r || x < 0 || x >= c)return;
	if (visited[y][x])return;
	board[y][x] += heat;
	visited[y][x] = true;
	if (heat == 1)return;
	if (!wall[y][x][y + 1][x])
	{
		HeaterDown(y + 1, x, heat - 1);
	}
	if (!wall[y][x][y][x - 1] && !wall[y][x - 1][y + 1][x - 1])
	{
		HeaterDown(y + 1, x - 1, heat - 1);
	}
	if (!wall[y][x][y][x + 1] && !wall[y][x + 1][y + 1][x + 1])
	{
		HeaterDown(y + 1, x + 1, heat - 1);
	}
}
void PowerOnHeater()
{
	for (int i = 0; i < heater.size(); ++i)
	{
		memset(visited, false, sizeof(visited));
		int y = heater[i].first.first;
		int x = heater[i].first.second;
		int direction = heater[i].second;
		if (direction == 1)
			HeaterRight(y,x + 1,5);
		if (direction == 2)
			HeaterLeft(y, x - 1,5);
		if (direction == 3)
			HeaterUp(y - 1, x,5);
		if (direction == 4)
			HeaterDown(y + 1, x,5);
	}
}
void AdjustTwoPoint(int bigY, int bigX, int smallY, int smallX)
{
	if (wall[bigY][bigX][smallY][smallX])return;
	int diff = board[bigY][bigX] - board[smallY][smallX];
	diff /= 4;
	copyBoard[bigY][bigX] -= diff;
	copyBoard[smallY][smallX] += diff;
}
void AdjustTemperature()
{
	for (int i = 0; i < 21; ++i)for (int j = 0; j < 21; ++j)copyBoard[i][j] = board[i][j];
	int bigY, bigX, smallY, smallX;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (j + 1 < c)
			{
				if (board[i][j] > board[i][j + 1])
				{
					bigY = i; bigX = j;
					smallY = i; smallX = j + 1;
				}
				else
				{
					smallY = i; smallX = j;
					bigY = i; bigX = j + 1;
				}
				AdjustTwoPoint(bigY, bigX, smallY, smallX);
			}
			if (i + 1 < r)
			{
				if (board[i][j] > board[i + 1][j])
				{
					bigY = i; bigX = j;
					smallY = i + 1; smallX = j;
				}
				else
				{
					smallY = i; smallX = j;
					bigY = i + 1; bigX = j;
				}
				AdjustTwoPoint(bigY, bigX, smallY, smallX);
			}
		}
	}
	for (int i = 0; i < 21; ++i)for (int j = 0; j < 21; ++j)board[i][j] = copyBoard[i][j];
}
bool CheckBoard()
{
	for (int i = 0; i < check.size(); ++i)
	{
		int y = check[i].first;
		int x = check[i].second;
		if (board[y][x] < k)
		{
			return false;
		}
	}
	return true;
}
void OutsideTemperatureDown()
{
	for (int i = 0; i < r; ++i)
	{
		board[i][0] = max(board[i][0] - 1, 0);
		board[i][c - 1] = max(board[i][c - 1] - 1, 0);
	}
	for (int j = 1; j < c - 1; ++j)
	{
		board[0][j] = max(board[0][j] - 1, 0);
		board[r-1][j] = max(board[r-1][j] - 1, 0);
	}
}
void PrintBoard()
{
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout.width(2);
			cout << board[i][j];
			cout << " ";
		}
		cout << "\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c >> k;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			int item;
			cin >> item;
			if (1 <= item && item <= 4)
			{
				heater.push_back({ {i,j},item });
			}
			else if (item == 5)
			{
				check.push_back({ i,j });
			}
		}
	}
	cin >> w;
	for (int i = 0; i < w; ++i)
	{
		int x, y, t;
		cin >> y >> x >> t;
		--y;
		--x;
		if (t == 0)
		{
			wall[y - 1][x][y][x] = true;
			wall[y][x][y - 1][x] = true;
		}
		else
		{
			wall[y][x + 1][y][x] = true;
			wall[y][x][y][x + 1] = true;
		}
	}
	int result = 1;

	while (true)
	{
		PowerOnHeater();
		AdjustTemperature();
		OutsideTemperatureDown();
		if (CheckBoard())
		{
			cout << result;
			return 0;
		}
		else if (result == 100)
		{
			cout << "101";
			return 0;
		}
		result++;
	}
}