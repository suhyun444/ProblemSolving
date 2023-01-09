#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;
		if (item == 0)
		{
			if (q.empty())cout << "0\n";
			else
			{
				cout << q.top().first * q.top().second<< "\n";
				q.pop();
			}
		}
		else
		{
			int flag = (item < 0) ? -1 : 1;
			q.push({ item * flag,flag});
		}
	}
}