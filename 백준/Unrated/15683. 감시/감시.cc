#include <iostream>
#include <vector>

using namespace std;

int cctv2[2][2] =
{
	{0,2},
	{1,3}
};
int cctv3[4][2] =
{
	{0,1},
	{1,2},
	{2,3},
	{3,0}
};
int cctv4[4][3] =
{
	{0,1,2},
	{1,2,3},
	{2,3,0},
	{3,0,1}
};
vector<pair<int, int>> camera;
int n, m;
int board[8][8];
int answer = 2e9;
void AddVertical(int x, int y, int sign, int addNum)
{
	while (0 <= y && y < n)
	{
		y += sign;
		if (y < 0 || y >= n) return;
		if (board[y][x] == 6)return;
		if (board[y][x] > 0)continue;
		board[y][x] += addNum;
	}
}
void AddHorizontal(int x, int y, int sign, int addNum)
{
	while (0 <= x && x < m)
	{
		x += sign;
		if (x < 0 || x >= m)return;
		if (board[y][x] == 6)return;
		if (board[y][x] > 0)continue;
		board[y][x] += addNum;
	}
}
void FillOrEraseSpace(int x, int y, int directionType, int addNum)
{
	if (directionType == 0)
	{
		AddVertical(x, y, -1, addNum);
	}
	else if (directionType == 1)
	{
		AddHorizontal(x, y, 1, addNum);
	}
	else if (directionType == 2)
	{
		AddVertical(x, y, 1, addNum);
	}
	else if (directionType == 3)
	{
		AddHorizontal(x, y, -1, addNum);
	}
}
int CheckSpace()
{
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0)
			{
				ret++;
			}
		}
	}
	return ret;
}
void PrintSpace()
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << board[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}
void BackTracking(int index)
{
	if (index == camera.size())
	{
			answer = min(answer, CheckSpace());
		if (answer > CheckSpace())
		{
			//PrintSpace();
			//cout << CheckSpace() << "\n\n";
		}
		return;
	}
	int y = camera[index].first;
	int x = camera[index].second;
	int cctvType = board[y][x];
	if (cctvType == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			FillOrEraseSpace(x, y, i, -1);
			BackTracking(index + 1);
			FillOrEraseSpace(x, y, i, 1);
		}
	}
	else if (cctvType == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			FillOrEraseSpace(x, y, cctv2[i][0], -1);
			FillOrEraseSpace(x, y, cctv2[i][1], -1);
			BackTracking(index + 1);
			FillOrEraseSpace(x, y, cctv2[i][0], 1);
			FillOrEraseSpace(x, y, cctv2[i][1], 1);
		}
	}
	else if (cctvType == 3)
	{
		for (int i = 0; i < 4; i++)
		{
			FillOrEraseSpace(x, y, cctv3[i][0], -1);
			FillOrEraseSpace(x, y, cctv3[i][1], -1);
			BackTracking(index + 1);
			FillOrEraseSpace(x, y, cctv3[i][0], 1);
			FillOrEraseSpace(x, y, cctv3[i][1], 1);
		}
	}
	else if (cctvType == 4)
	{
		for (int i = 0; i < 4; i++)
		{
			FillOrEraseSpace(x, y, cctv4[i][0], -1);
			FillOrEraseSpace(x, y, cctv4[i][1], -1);
			FillOrEraseSpace(x, y, cctv4[i][2], -1);
			BackTracking(index + 1);
			FillOrEraseSpace(x, y, cctv4[i][0], 1);
			FillOrEraseSpace(x, y, cctv4[i][1], 1);
			FillOrEraseSpace(x, y, cctv4[i][2], 1);
		}
	}
	else if (cctvType == 5)
	{
		for (int i = 0; i < 4; i++)FillOrEraseSpace(x, y, i, -1);
		BackTracking(index + 1);
		for (int i = 0; i < 4; i++)FillOrEraseSpace(x, y, i, 1);
	}

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] != 0 && board[i][j] != 6)camera.push_back({ i,j });
		}
	}
	answer = CheckSpace();
	BackTracking(0);
	cout << answer;
}