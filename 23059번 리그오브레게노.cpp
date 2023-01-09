#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

unordered_map<string, int> nameToIndex;
unordered_map<int, string> indexToName;
vector<int> adj[400001];
int indegree[400001];

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)return indexToName[a.second] < indexToName[b.second];
	return a.first < b.first;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	int count = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string a, b;
		cin >> a >> b;
		if (nameToIndex.find(a) == nameToIndex.end())
		{
			nameToIndex.insert({ a,count });
			indexToName.insert({ count++,a });
		}
		if (nameToIndex.find(b) == nameToIndex.end())
		{
			nameToIndex.insert({ b,count });
			indexToName.insert({ count++,b });
		}
		adj[nameToIndex[a]].push_back(nameToIndex[b]);
		indegree[nameToIndex[b]]++;
	}

	queue<pair<int,int>> q;
	vector<pair<int,int>> result;
	for (int i = 0; i < count; i++)
		if (indegree[i] == 0)
			q.push({ 0,i });
	for (int i = 0; i < count; i++)
	{
		if (q.empty())
		{
			cout << "-1";
			return 0;
		}
		pair<int,int> cur = q.front();
		q.pop();
		result.push_back({ cur.first,cur.second});
		for (int next : adj[cur.second])
			if (--indegree[next] == 0)q.push({ cur.first + 1,next });
	}
	sort(result.begin(), result.end(), compare);
	for (int i = 0; i < result.size(); i++)
	{
		cout << indexToName[result[i].second] << "\n";
	}
}