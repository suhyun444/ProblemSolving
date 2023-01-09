#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n;
int people[11];
vector<int> adj[11];
bool visited[11];
int result = 2e9;

int GetAnotherWeight()
{
	int startIndex = -1;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			startIndex = i;
			break;
		}
	}
	if (startIndex == -1)return -1;
	queue<int> q;
	bool anotherVisited[11];
	memset(anotherVisited, false, sizeof(anotherVisited));
	q.push(startIndex);
	anotherVisited[startIndex] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int next : adj[cur])
		{
			if (!visited[next] && !anotherVisited[next])
			{
				anotherVisited[next] = true;
				q.push(next);
			}
		}
	}
	int anotherWeight = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i] && !anotherVisited[i])return -1;
		if (!visited[i]) anotherWeight += people[i];
	}
	return anotherWeight;
}
int GetWeight()
{
	int startIndex = -1;
	for (int i = 1; i <= n; i++)
	{
		if (visited[i])
		{
			startIndex = i;
			break;
		}
	}
	if (startIndex == -1)return -1;
	queue<int> q;
	bool anotherVisited[11];
	memset(anotherVisited, false, sizeof(anotherVisited));
	q.push(startIndex);
	anotherVisited[startIndex] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int next : adj[cur])
		{
			if (visited[next] && !anotherVisited[next])
			{
				anotherVisited[next] = true;
				q.push(next);
			}
		}
	}
	int anotherWeight = 0;
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] && !anotherVisited[i])return -1;
		if (visited[i]) anotherWeight += people[i];
	}
	return anotherWeight;
}

void solve()
{
	int curWeight = GetWeight();
	if (curWeight == -1)return;
	int anotherWeight = GetAnotherWeight();
	if (anotherWeight == -1)return;
	result = min(result, abs(curWeight - anotherWeight));
}
void FindCombination(int startIndex,int length,int maxLength)
{
	if (length == maxLength)
	{
		solve();
		return;
	}
	for (int i = startIndex; i <= n; i++)
	{
		visited[i] = true;
		FindCombination(startIndex + 1,length + 1,maxLength);
		visited[i] = false;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> people[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		for (int j = 0; j < a; j++)
		{
			int next;
			cin >> next;
			adj[i].push_back(next);
		}
	}
	int maxSize = n / 2;
	for (int i = 1; i <= maxSize + 1; i++)
	{
		FindCombination(1,0,i);
	}
	if (result == 2e9)cout << "-1";
	else cout << result;
}