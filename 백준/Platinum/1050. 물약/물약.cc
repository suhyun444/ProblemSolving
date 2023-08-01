#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
vector<pair<int, int>> adj[101][101];
map<string, int> nameToIndex;
long long cost[101];
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 101; ++i)cost[i] = 2e10;
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
	for (int i = 0; i < 101; ++i)
	{
		for (int j = 0; j < index; ++j)
		{
			int reciptIndex = 0;
			while (!adj[j][reciptIndex].empty())
			{
				bool canMake = true;
				long long value = 0;
				for (pair<int, int> next : adj[j][reciptIndex])
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
				if (canMake)
					cost[j] = min(cost[j], value);
				++reciptIndex;
			}
		}
	}
	int loveIndex = nameToIndex["LOVE"];
	if (cost[loveIndex] == 2e10)
		cout << "-1";
	else
		cout << cost[loveIndex];
}