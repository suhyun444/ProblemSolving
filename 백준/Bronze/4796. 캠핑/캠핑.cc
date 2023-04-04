#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int l, p, v;
	int count = 1;
	while (true)
	{
		cin >> l >> p >> v;
		if (l == 0)return 0;
		int result = (v / p) * l;
		v = v % p;
		result += min(v, l);
		cout <<"Case " << count << ": " << result << "\n";
		count++;
	}
}