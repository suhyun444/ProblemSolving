#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100001];
int numOfBuilding[100001];
int canBuildBuilding[100001];
int indegree[100001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		indegree[y]++;
	}
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		if (x == 1)
		{
			if (canBuildBuilding[y] != indegree[y])
			{
				cout << "Lier!";
				return 0;
			}
			if (numOfBuilding[y] == 0)
			{
				for (int i = 0; i < adj[y].size(); i++)
					canBuildBuilding[adj[y][i]]++;
			}
			numOfBuilding[y]++;
		}
		else
		{
			if (numOfBuilding[y] == 0)
			{
				cout << "Lier!";
				return 0;
			}
			if (numOfBuilding[y] == 1)
			{
				for (int i = 0; i < adj[y].size(); i++)
					canBuildBuilding[adj[y][i]]--;
			}
			numOfBuilding[y]--;
		}
	}
	cout << "King-God-Emperor";
}