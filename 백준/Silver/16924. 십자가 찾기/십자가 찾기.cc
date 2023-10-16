#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool visited[101][101];
char board[101][101];
int dirY[4] = { 0,1,0,-1 };
int dirX[4] = { 1,0,-1,0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	vector<pair<pair<int, int>, int>> result;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == '*')
			{
				int size = 1;
				while (true)
				{
					bool canMake = true;
					for (int k = 0; k < 4; ++k)
					{
						int nextY = i + dirY[k] * size;
						int nextX = j + dirX[k] * size;
						if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m || board[nextY][nextX] == '.')
						{
							canMake = false;
							break;
						}
					}
					if (!canMake)
					{
						break;
					}
					for (int k = 0; k < 4; ++k)
					{
						int nextY = i + dirY[k] * size;
						int nextX = j + dirX[k] * size;
						visited[nextY][nextX] = true;
					}
					++size;
				}
				if (size != 1)
				{
					visited[i][j] = true;
					result.push_back({ {i + 1,j + 1},size-1 });
				}
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == '*' && !visited[i][j])
			{
				cout << "-1";
				return 0;
			}
		}
	}
	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i].first.first << " " << result[i].first.second << " " << result[i].second << "\n";
	}
}