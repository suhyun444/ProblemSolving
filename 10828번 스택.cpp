#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	queue<int> q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		if (input == "push")
		{
			int item;
			cin >> item;
			q.push(item);
		}
		if (input == "pop")
		{
			if (q.empty())cout << "-1\n";
			else
			{
				int item = q.front();
				cout << item << "\n";
				q.pop();
			}
		}
		if (input == "size")
		{
			cout << q.size() << "\n";
		}
		if (input == "empty")
		{
			cout << q.empty() << "\n";
		}
		if (input == "front")
		{
			if (q.empty())cout << "-1\n";
			else
			{
				int item = q.front();
				cout << item << "\n";
			}
		}
		if (input == "back")
		{
			if (q.empty())cout << "-1\n";
			else
			{
				int item = q.back();
				cout << item << "\n";
			}
		}
	}
}