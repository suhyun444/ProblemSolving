#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int cache[1001][1001];
int adj[1001];
vector<int> noDirectionAdjust[1001];
bool visited[1001];
bool noDirectionVisited[1001];
bool finished[1001];
vector<pair<int, int>> values;
int dfs(int cur) {
	visited[cur] = true;
	int next = adj[cur];
	if (visited[next] == true && finished[next] == false) {
		int count = 1;
		for (int tmp = next; tmp != cur; tmp = adj[tmp])count++;
		finished[cur] = true;
		return count;
	}
	int ret = 0;
	if (visited[next] == false)ret = dfs(next);
	finished[cur] = true;
	return ret;
}
int NoDirectionDfs(int cur) {
	int sum = 1;
	noDirectionVisited[cur] = true;
	for (int next : noDirectionAdjust[cur]) {
		if (noDirectionVisited[next] == false) {
			sum += NoDirectionDfs(next);
		}
	}
	return sum;
}
int solve(int n,int k) {
	if (n == values.size()) {
		return k;
	}
	int& ret = cache[n][k];
	if (ret != -1) {
		return ret;
	}
	int minCount = values[n].first;
	int maxCount = values[n].second;
	ret = solve(n + 1, k);
	for (int i = minCount; i <= maxCount; i++) {
		if (k + i > K) break;
		ret = max(ret, solve(n + 1, k + i));
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(cache, -1, sizeof(cache));
	memset(visited, false, sizeof(visited));
	memset(noDirectionVisited, false, sizeof(noDirectionVisited));
	memset(finished, false, sizeof(finished));
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> adj[i];
		noDirectionAdjust[i].push_back(adj[i]);
		noDirectionAdjust[adj[i]].push_back(i);
	}
	for (int i = 1; i <= N; i++) {
		if (noDirectionVisited[i] == false) {
			int min = dfs(i);
			int max = NoDirectionDfs(i);
			values.push_back({ min,max });
		}
	}
	cout << solve(0, 0);
}