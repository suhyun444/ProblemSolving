#include <iostream>
#include <vector>

using namespace std;

int N;
bool cache[31][15001];
int l, r;
vector<int> weight;
void solve(int n, int w)
{
	if (cache[n][w])return;
	cache[n][w] = true;
	if (n == N)return;
	solve(n + 1,w);
	solve(n + 1,w + weight[n]);
	solve(n + 1, abs(w - weight[n]));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		weight.push_back(a);
	}
	weight.push_back(0);
	solve(0,0);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		if (a > 15000)cout << "N ";
		else
		{
			bool isFind = false;
			for (int j = 1;j <= N; j++)
			{
				if (cache[j][a])
				{
					isFind = true;
					cout << "Y ";
					break;
				}
			}
			if (!isFind)
				cout << "N ";
		}
	}
}