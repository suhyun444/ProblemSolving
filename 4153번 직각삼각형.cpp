#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (true)
	{
		int l[3];
		cin >> l[0] >> l[1] >> l[2];
		if (l[0] == 0 && l[1] == 0 && l[2] == 0)
		{
			break;
		}
		sort(l, l + 3);
		if (l[0] * l[0] + l[1] * l[1] == l[2] * l[2])
			cout << "right\n";
		else
			cout << "wrong\n";
	}

}