#include <iostream>
#include <map>
#include <queue>

using namespace std;

map<pair<int, int>, int> visited;
queue<pair<int, int>> q;
void CheckAndPush(int first,int second)
{
	if (visited.find({ first,second }) == visited.end())
	{
		visited.insert({ {first,second},1 });
		q.push({ first,second });
	}
}
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	visited.insert({ {0,0},1 });
	q.push({ 0,0 });
	
	int level = 0;
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			pair<int, int> cur = q.front();
			q.pop();
			if (cur.first == c && cur.second == d)
			{
				cout << level;
				return 0;
			}
			CheckAndPush(a, cur.second);
			CheckAndPush(cur.first, b);
			CheckAndPush(0, cur.second);
			CheckAndPush(cur.first, 0);
			int left = cur.first, right = cur.second;
			right += left;
			left = max(right - b, 0);
			right = min(right, b);
			CheckAndPush(left, right);
			left = cur.first;
			right = cur.second;
			left += right;
			right = max(left - a, 0);
			left = min(left, a);
			CheckAndPush(left, right);
		}
		level++;
	}
	cout << "-1";
}