#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int n, w, l;
	cin >> n >> w >> l;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	int time = 0, result = 0, index = 0,weight = 0;
	queue<pair<int,int>> q;
	while (result < n)
	{
		if (!q.empty() && time - q.front().first >= w)
		{
			pair<int,int> t = q.front();
			q.pop();
			weight -= t.second;
			++result;
		}
		if (index < n && weight + arr[index] <= l)
		{
			weight += arr[index];
			pair<int, int>t = { time,arr[index] };
			q.push(t);
			++index;
		}
		++time;
	}
	cout << time;
}