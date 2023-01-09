#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int> lower;
	priority_queue<int, vector<int>, greater<int>> higher;
	int n;
	cin >> n;
	int element;
	cin >> element;
	cout << element << "\n";
	lower.push(element);
	for (int i = 1; i < n; i++)
	{
		cin >> element;
		if (lower.size() > higher.size())
			higher.push(element);
		else
			lower.push(element);
		if (lower.top() > higher.top())
		{
			int low = lower.top();
			lower.pop();
			int high = higher.top();
			higher.pop();
			lower.push(high);
			higher.push(low);
		}
		cout << lower.top() << "\n";
	}
}