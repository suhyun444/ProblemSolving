#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> s;
vector<bool> visited;

void dfs(int index, int weight)
{
	if (index == s.size())
	{
		if (weight >= 0)
		{
			visited[weight] = true;
		}
		return;
	}
	dfs(index + 1, weight);
	dfs(index + 1, weight + s[index]);
	dfs(index + 1, weight - s[index]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;
		sum += item;
		s.push_back(item);
	}
	visited.resize(sum + 1, false);
	dfs(0, 0);
	int res = 0;
	for (int i = 1; i < visited.size(); i++)
	{
		if (!visited[i])
			res++;
	}
	cout << res;
}