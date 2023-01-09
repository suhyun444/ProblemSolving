#include <iostream>
#include <vector>

using namespace std;

vector<int> path[11];
bool visited[101][101];
pair<int, int> GetDirection(int type)
{
	//x,y;
	if (type == 0)
		return { 1,0 };
	if (type == 1)
		return { 0,-1 };
	if (type == 2)
		return { -1,0 };
	if (type == 3)
		return { 0,1 };
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	path[0].push_back(0);
	for (int i = 1; i < 11; i++)
	{
		for (int j = 0; j < path[i - 1].size(); j++)
			path[i].push_back(path[i - 1][j]);
		for (int j = path[i - 1].size() - 1; j >= 0; j--)
			path[i].push_back((path[i - 1][j] + 1) % 4);
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		visited[y][x] = true;
		for (int j = 0; j < path[g].size(); j++)
		{
			pair<int,int> direction = GetDirection((path[g][j] + d) % 4);
			x += direction.first;
			y += direction.second;
			visited[y][x] = true;
		}
	}

	int count = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (visited[i][j] && visited[i + 1][j] && visited[i][j + 1] && visited[i + 1][j + 1])
				count++;
		}
	}
	cout << count;
}