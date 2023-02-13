#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a, b, c, d;
vector<int> sum1, sum2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y, z, w;
		cin >> x >> y >> z >> w;
		a.push_back(x);
		b.push_back(y);
		c.push_back(z);
		d.push_back(w);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			sum1.push_back(a[i] + b[j]);
			sum2.push_back(c[i] + d[j]);
		}
	}
	sort(sum1.begin(), sum1.end());
	sort(sum2.begin(), sum2.end());
	long long result = 0;
	for (int i = 0; i < sum1.size(); i++)
	{
		int key = -sum1[i];
		int pre = lower_bound(sum2.begin(), sum2.end(), key) - sum2.begin();
		int post = upper_bound(sum2.begin(), sum2.end(), key) - sum2.begin();
		if (key == sum2[pre])
			result += 1LL * post -  1LL * pre;
	}
	cout << result;
}