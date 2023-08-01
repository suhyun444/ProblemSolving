#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
vector<pair<int, int>> adj[1001][1001];
map<string, int> nameToIndex;
bool visited[1001];
long long cost[1001];
bool calculated[1001];
void AddAdjustment(int from, string toString)
{
	int adjIndex = 0;
	while (!adj[from][adjIndex].empty())
		++adjIndex;
	int index = 0;
	while (index < toString.size())
	{
		int num = toString[index] - '0';
		++index;
		int nameIndex = index;
		while (nameIndex < toString.size() && toString[nameIndex] != '+')
			++nameIndex;
		string name = toString.substr(index, nameIndex - index);
		index = nameIndex + 1;
		if (nameToIndex.find(name) == nameToIndex.end())
			adj[from][adjIndex].push_back({ num,-1 });
		else
			adj[from][adjIndex].push_back({ num,nameToIndex[name] });
	}
}
long long Dfs(int cur)
{
	if (visited[cur])return -1;
	if (calculated[cur])return cost[cur];
	visited[cur] = true;
	long long result = 9e18;
	int index = 0;
	while (!adj[cur][index].empty())
	{
		long long curCost = 0;
		for (pair<int, int> next : adj[cur][index])
		{
			if (next.second == -1)
			{
				curCost = 0;
				break;
			}
			long long value = Dfs(next.second);
			if (value == -1 && cost[next.second] == 0)
			{
				curCost = 0;
				break;
			}
			else if (value == -1 && cost[next.second] != 0)
				value = cost[next.second];
			else if (value != -1 && cost[next.second] != 0)
				value = min(value, cost[next.second]);
			curCost += next.first * value;
			curCost = min(curCost, (long long)1e9 + 1);
		}
		if (curCost > 0)
		{
			result = min(curCost, result);
		}
		++index;
	}
	visited[cur] = false;
	if (result == 9e18)return -1;
	calculated[cur] = true;
	if (cost[cur] != 0)
		cost[cur] = min(result, cost[cur]);
	else
		cost[cur] = result;
	return result;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 1001; ++i)cost[i] = 2e10;
	int index = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		string s;
		long long c;
		cin >> s >> c;
		if (nameToIndex.find(s) == nameToIndex.end())
		{
			cost[index] = c;
			nameToIndex.insert({ s,index++ });
		}
	}
	vector<pair<int, string>> receipt;
	for (int i = 0; i < m; ++i)
	{
		string s;
		cin >> s;
		int stringIndex = 0;
		int nameIndex = 0;
		while (s[stringIndex] != '=')
			++stringIndex;
		string name = s.substr(0, stringIndex);
		if (nameToIndex.find(name) == nameToIndex.end())
		{
			nameIndex = index;
			nameToIndex.insert({ name, index });
			index++;
		}
		else
		{
			nameIndex = nameToIndex[name];
		}
		receipt.push_back({ nameIndex,s.substr(stringIndex + 1) });
	}
	if (nameToIndex.find("LOVE") == nameToIndex.end())
	{
		cout << "-1";
		return 0;
	}
	for (int i = 0; i < m; ++i)
	{
		AddAdjustment(receipt[i].first, receipt[i].second);
	}
	//long long ans = Dfs(nameToIndex["LOVE"]);
	//if (ans == -1 && cost[nameToIndex["LOVE"]] != 0)
	//	ans = cost[nameToIndex["LOVE"]];
	//else if (cost[nameToIndex["LOVE"]] != 0)
	//	ans = min(ans, cost[nameToIndex["LOVE"]]);
	//if (ans < 0)
	//	cout << "-1";
	//else
	//{
	//	ans = min(ans, (long long)1e9 + 1);
	//	cout << ans;
	//}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			for (int k = 0; k < index; k++)
			{
				int reciptIndex = 0;
				while (!adj[k][reciptIndex].empty())
				{
					bool canMake = true;
					long long value = 0;
					for (pair<int, int> next : adj[k][reciptIndex])
					{
						if (next.second == -1 || cost[next.second] == 2e10)
						{
							canMake = false;
							break;
						}
						else
						{
							value += next.first * cost[next.second];
							value = min(value, (long long)1e9 + 1);
						}
					}
					if(canMake)
						cost[k] = min(cost[k], value);
					++reciptIndex;
				}
			}
		}
	}
	int loveIndex = nameToIndex["LOVE"];
	if (cost[loveIndex] == 2e10)
	{
		cout << "-1";
	}
	else
	{
		cout << cost[loveIndex];
	}
}