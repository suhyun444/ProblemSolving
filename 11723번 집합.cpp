#include <iostream>

using namespace std;

int main()
{
	bool arr[21];
	for (int i = 0; i < 21; i++)arr[i] = false;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		if (input == "add")
		{
			int x;
			cin >> x;
			arr[x] = true;
		}
		else if (input == "remove")
		{
			int x;
			cin >> x;
			arr[x] = false;
		}
		else if (input == "check")
		{
			int x;
			cin >> x;
			cout << arr[x] << "\n";
		}
		else if (input == "toggle")
		{
			int x;
			cin >> x;
			arr[x] = !arr[x];
		}
		else if (input == "all")
		{
			for (int i = 0; i <= 20; i++)arr[i] = true;
		}
		else if (input == "empty")
		{
			for (int i = 0; i <= 20; i++)arr[i] = false;
		}
	}
}