#include <iostream>
#include <deque>

using namespace std;

struct note
{
	int priority;
	int index;
	note(int priority, int index) : priority(priority), index(index) {}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		deque<note> arr;
		for (int i = 0; i < n; i++)
		{
			int item;
			cin >> item;
			arr.push_back({ item,i });
		}
		int ans = 0;
		while (true)
		{
			note cur = arr.front();
			bool isFind = false;
			for (int i = 0; i < arr.size(); i++)
			{
				if (arr[i].priority > cur.priority)
				{
					isFind = true;
					break;
				}
			}
			if (isFind)
			{
				arr.pop_front();
				arr.push_back(cur);
			}
			else
			{
				arr.pop_front();
				ans++;
				if (cur.index == m)
				{
					break;
				}
			}
		}
		cout << ans << "\n";
	}
}