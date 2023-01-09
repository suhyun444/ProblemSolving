#include <iostream>

using namespace std;

int main()
{
	int a, b, v;
	cin >> a >> b >> v;
	int canClimePerDay = a - b;
	int ans = 0;
	ans += v / canClimePerDay;
	v %= canClimePerDay;
	while (v < a)
	{
		ans--;
		v += canClimePerDay;
	}
	while (true)
	{
		ans++;
		v -= a;
		if (v <= 0)
		{
			break;
		}
		v += b;
	}
	cout << ans;
}