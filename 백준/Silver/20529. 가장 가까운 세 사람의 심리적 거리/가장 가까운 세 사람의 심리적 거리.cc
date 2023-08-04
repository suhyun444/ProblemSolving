#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<string> arr;
map<string,int> mbti;
int CalcDistance(string a, string b, string c)
{
	int dist = 0;
	for (int i = 0; i < 4; i++)
	{
		if (a[i] != b[i])dist++;
		if (b[i] != c[i])dist++;
		if (c[i] != a[i])dist++;
	}
	return dist;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		arr.clear();
		mbti.clear();
		int n;
		cin >> n;
		string s;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			if (mbti.find(s) == mbti.end())
			{
				mbti.insert({ s,1 });
				arr.push_back(s);
			}
			else if (mbti[s] < 3)
			{
				mbti[s]++;
				arr.push_back(s);
			}
		}
		int result = 2e9;
		if (arr.size() == 1)
		{
			cout << "0\n";
		}
		else if (arr.size() == 2)
		{
			cout << CalcDistance(arr[0], arr[0], arr[1]) << "\n";
		}
		else
		{
			for (int i = 0; i < arr.size() - 2; i++)
			{
				for (int j = i + 1; j < arr.size() - 1; j++)
				{
					for (int k = j + 1; k < arr.size(); k++)
					{
						result = min(result, CalcDistance(arr[i], arr[j], arr[k]));
					}
				}
			}
			cout << result << "\n";
		}
	}
}