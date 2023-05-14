#include <iostream>
#include <cstring>
#include <vector>

using namespace std;


int adjust[100001];
bool visited[100001];
bool finished[100001];

int dfs(int cur) {
	visited[cur] = true;
	int next = adjust[cur];
	if (visited[next] == true && finished[next] == false) {
		int count = 1;
		for (int tmp = next; tmp != cur; tmp = adjust[tmp]) {
			count++;
		}
		finished[cur] = true;
		return count;
	}
	int ret = 0;
	if (visited[next] == false) {
		ret = dfs(next);
	}
	finished[cur] = true;
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(visited, false, sizeof(visited));
		memset(finished, false, sizeof(finished));
		int n,sum = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> adjust[i];
		}
		for (int i = 1; i <= n; i++) {
			if (visited[i] == false) sum += dfs(i);
		}
		cout << n - sum << "\n";
	}
}