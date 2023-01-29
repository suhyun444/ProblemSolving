#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n;
int m;
vector<int> costs;
string cache[51];
bool CompareString(string a, string b)
{
	if (a.size() == b.size())
	{
		for (int i = 0; i <= a.size(); i++)
			if (a[i] != b[i])return a[i] > b[i];
	}
	return a.size() > b.size();
}
string Solve(int cur)
{
	string& ret = cache[cur];
	if (ret != "a")return ret;
	ret = "";
	for (int i = 0; i < n; i++)
	{
		if (cur == m && i == 0)continue; 
		if (cur >= costs[i])
		{
			string next = Solve(cur - costs[i]);
			char add = i + '0';
			next.insert(next.begin(), add);
			if (CompareString(next, ret))
				ret = next;
		}
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 51; i++)cache[i] = "a";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;
		costs.push_back(item);
	}
	cin >> m;
	string ans = Solve(m);
	if (ans == "")cout << "0";
	else cout << ans;
}