#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int board[21][21];
int sharkWeight = 2;
int sharkFoodFill = 0;
bool visited[21][21];
int dirY[4] = { -1,0,0,1 };
int dirX[4] = { 0,-1,1,0 };

bool compare(pair<int, int> a, pair<int, int>b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}
pair<int,pair<int,int>> bfs(int y, int x)
{
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = true;
	int level = 0;
	bool isEnd = false;
	vector<pair<int, int>> v;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			pair<int, int> cur = q.front();
			q.pop();
			if (board[cur.first][cur.second] < sharkWeight && board[cur.first][cur.second] != 0)
			{
				v.push_back({ cur.first,cur.second });
				isEnd = true;
			}
			for (int j = 0; j < 4; j++)
			{
				int nextY = cur.first + dirY[j];
				int nextX = cur.second + dirX[j];
				if (0 <= nextX && nextX < n && 0 <= nextY && nextY < n)
				{
					if (!visited[nextY][nextX] && board[nextY][nextX] <= sharkWeight)
					{
						visited[nextY][nextX] = true;
						q.push({ nextY,nextX });
					}
				}
			}
		}
		if (isEnd)break;
		level++;
	}
	if (!isEnd)return{ -1,{-1,-1} };
	sort(v.begin(), v.end(), compare);
	board[v[0].first][v[0].second] = 0;
	return { v[0].first,{v[0].second,level} };
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int ans = 0;
	bool isEnd = true;
	pair<int, int> sharkPosition;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)isEnd = false;
			if (board[i][j] == 9)
			{
				sharkPosition = { i,j };
				board[i][j] = 0;
			}
		}
	}
	if (isEnd)
	{
		cout << "0";
		return 0;
	}
	while (true)
	{
		bool isEnd = true;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] < sharkWeight && board[i][j] != 0)isEnd = false;
			}
		}
		if (isEnd)
		{
			break;
		}
		pair<int, pair<int, int>> cur = bfs(sharkPosition.first, sharkPosition.second);
		if (cur.first == -1)break;
		sharkPosition.first = cur.first;
		sharkPosition.second = cur.second.first;
		ans += cur.second.second;
		sharkFoodFill++;
		if (sharkFoodFill >= sharkWeight)
		{
			sharkFoodFill -= sharkWeight;
			sharkWeight++;
		}
	}
	cout << ans;
}