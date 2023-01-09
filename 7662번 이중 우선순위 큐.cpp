#include <iostream>
#include<queue>
#include <cstring>

using namespace std;

bool visited[1000001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		priority_queue<pair<int,int>> max_q;
		priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > min_q;
		int n;
		cin >> n;
		int index = 0;
			memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; i++)
		{
			char a;
			int b;
			cin >> a >> b;
			if (a == 'I')
			{
				max_q.push({ b ,index });
				min_q.push({ b,index });
				index++;
			}
			else if (a == 'D')
			{
				if (b == 1)
				{
					while (!max_q.empty() && visited[max_q.top().second])
						max_q.pop();
					if (!max_q.empty())
					{
						visited[max_q.top().second] = true;
						max_q.pop();
					}
				}
				else
				{
					while (!min_q.empty() && visited[min_q.top().second])
						min_q.pop();
					if (!min_q.empty())
					{
						visited[min_q.top().second] = true;
						min_q.pop();
					}
				}
			}
		}
		while (!max_q.empty() && visited[max_q.top().second])
			max_q.pop();
		while (!min_q.empty() && visited[min_q.top().second])
			min_q.pop();
		if (min_q.empty()||max_q.empty())cout << "EMPTY\n";
		else
		{
			int min = min_q.top().first;
			int max = max_q.top().first;
			cout << max << " " << min << "\n";
		}
	}
}
