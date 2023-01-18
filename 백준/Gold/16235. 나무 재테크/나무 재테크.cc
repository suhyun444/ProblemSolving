#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int energy[11][11];
int curEnergy[11][11];
vector<int> trees[11][11];
void Sort()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sort(trees[i][j].begin(), trees[i][j].end());
		}
	}
}
void Spring()
{
	Sort();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int treeCount = trees[i][j].size();
			for (int k = 0; k < treeCount; k++)
			{
				if (curEnergy[i][j] >= trees[i][j][k])
				{
					curEnergy[i][j] -= trees[i][j][k];
					trees[i][j][k]++;
				}
				else
				{
					for (; k < treeCount; k++)
					{
						curEnergy[i][j] += (trees[i][j].back() / 2);
						trees[i][j].pop_back();
					}
					break;
				}
			}
		}
	}
}
void Autumn()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int treeCount = trees[i][j].size();
			for (int k = 0; k < treeCount; k++)
			{
				if (trees[i][j][k] % 5 == 0)
				{
					for (int dy = -1; dy <= 1; dy++)
					{
						for (int dx = -1; dx <= 1; dx++)
						{
							int nextY = dy + i;
							int nextX = dx + j;
							if (dy == 0 && dx == 0)continue;
							if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n)
							{
								trees[nextY][nextX].push_back(1);
							}
						}
					}
				}
			}
		}
	}
}
void Winter()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			curEnergy[i][j] += energy[i][j];
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			curEnergy[i][j] = 5;
			cin >> energy[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		int x, y, age;
		cin >> x >> y >> age;
		x--;
		y--;
		trees[x][y].push_back(age);
	}
	for (int i = 0; i < k; i++)
	{
		Spring();
		Autumn();
		Winter();
	}
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result += trees[i][j].size();
		}
	}
	cout << result;
}