#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> meeting;
int N;

int solve(int n, int weight) {
	if (n > N - 1) 
		return weight;
	return max(	solve(n + 1, weight),solve(n + 2, weight + meeting[n]));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		meeting.push_back(c);
	}
	cout << solve(0, 0);
}