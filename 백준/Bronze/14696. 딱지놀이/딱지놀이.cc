#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int arr[4] = { 0 };
		int a,b;
		cin >> a;
		for (int i = 0; i < a; ++i)
		{
			cin >> b;
			arr[b - 1]++;
		}
		cin >> a;
		for (int i = 0; i < a; ++i)
		{
			cin >> b;
			arr[b - 1]--;
		}
		bool isDraw = true;
		for (int i = 3; i >= 0; --i)
		{
			if (arr[i] != 0)
			{
				isDraw = false;
				cout << ((arr[i] > 0) ? "A" : "B") << "\n";
				break;
			}
		}
		if (isDraw)cout << "D\n";
	}
}
