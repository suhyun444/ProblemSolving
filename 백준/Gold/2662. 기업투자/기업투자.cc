#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
int cache[301][21];
vector<int> costs[21];
int choices[301][21];
int ans;
int solve(int n, int m)
{
	if (m == M)return 0;
	int& ret = cache[n][m];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = 0; i+n<= N; i++)
	{
		int result = solve(n + i, m + 1)+ costs[m][i];
		if (ret < result)
		{
			ret = result;
			choices[n][m] = i;
		}
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(cache, -1, sizeof(cache));
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		costs[i].push_back(0);
	}
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		for (int j = 0; j < M; j++)
		{
			cin >> a;
			costs[j].push_back(a);
		}
	}
	cout << solve(0, 0) << "\n";
	vector<int> answer;
	int cur = 0;
	for (int i = 0; i < M; i++)
	{
		cout << choices[cur][i] << " ";
		cur += choices[cur][i];
	}
}