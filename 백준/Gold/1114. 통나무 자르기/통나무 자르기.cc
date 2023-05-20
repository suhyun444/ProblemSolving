#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, k, c;
int first = 0;
vector<int> pos;
vector<int> dist;
bool func(int mid)
{
	int curLen = 0;
	int count = 0;
	for (int i = dist.size() - 1; i >= 0; i--)
	{
		if (dist[i] > mid)return false;
		curLen += dist[i];
		if (curLen > mid)
		{
			curLen = dist[i];
			count++;
			if (count == c) {
				if (pos[i + 1] > mid)return false;
				first = pos[i + 1];
			}
		}
	}
	if (count < c)first = pos[1];
	return true;
}
int main()
{
	cin >> l >> k >> c;
	for (int i = 0; i < k; i++)
	{
		int a;
		cin >> a;
		pos.push_back(a);
	}
	pos.push_back(0);
	pos.push_back(l);
	sort(pos.begin(), pos.end());
	for (int i = 0; i < pos.size() - 1; i++)
	{
		dist.push_back(pos[i + 1] - pos[i]);
	}

	int lo = 0;
	int hi = l;
	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		if (!func(mid))
		{
			lo = mid;
		}
		else
		{
			hi = mid;
		}
	}
	cout << hi << " " << first << "\n";
}