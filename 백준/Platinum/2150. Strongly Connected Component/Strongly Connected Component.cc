#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int cnt = 0;
vector<int> adj[10001];
int dfsn[10001];
bool finished[10001];
stack<int> s;
vector<vector<int>> ans;
int dfs(int cur)
{
	dfsn[cur] = ++cnt;
	s.push(cur);
	int result = dfsn[cur];
	for (int next : adj[cur])
	{
		if (dfsn[next] == 0)result = min(result, dfs(next));
		else if (!finished[next])result = min(result, dfsn[next]);
	}
	if (result == dfsn[cur])
	{
		vector<int> scc;
		while (1)
		{
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == cur)break;
		}
		sort(scc.begin(), scc.end());
		ans.push_back(scc);
	}
	return result;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; ++i)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	for (int i = 1; i <= v; ++i)
	{
		if(dfsn[i] == 0)
			dfs(i);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i)
	{
		for (int j = 0; j < ans[i].size(); ++j)
		{
			cout << ans[i][j] << " ";
		}
		cout << "-1\n";
	}

}