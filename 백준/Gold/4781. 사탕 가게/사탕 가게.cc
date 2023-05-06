#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int cache[10001];
vector<pair<int, int>> candy;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (true)
	{
		int n, m;
		float temp;
		cin >> n >> temp;
		if (n == 0)return 0;
		temp *= 100;
		temp += 0.5f;
		m = temp;
		memset(cache, 0, sizeof(cache));
		candy.clear();
		for (int i = 0; i < n; i++)
		{
			int a;
			float b;
			cin >> a >> b;
			b *= 100;
			b += 0.5f;
			candy.push_back({ a,(int)b });
		}
		for (int i = 0; i < n; i++)
			for (int j = 1; j <= m; j++)
				if (j - candy[i].second >= 0)
					cache[j] = max(cache[j], cache[j - candy[i].second] + candy[i].first);
		cout << cache[m] << "\n";
	}
}