#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Truck
{
	int time, weight;
};
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
	queue<Truck> q;
	while (result < n)
	{
		if (!q.empty() && time - q.front().time >= w)
		{
			Truck t = q.front();
			q.pop();
			weight -= t.weight;
			++result;
		}
		if (index < n && weight + arr[index] <= l)
		{
			weight += arr[index];
			Truck t;
			t.weight = arr[index];
			t.time = time;
			q.push(t);
			++index;
		}
		++time;
	}
	cout << time;
}