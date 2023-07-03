#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int score[1000001];
bool hasNumber[1000001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
		hasNumber[a] = true;
	}
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 2; arr[i] * j < 1000001; j++)
		{
			if (hasNumber[arr[i] * j])
			{
				score[arr[i] * j]--;
				score[arr[i]]++;
			}
		}
	}
	for (int i = 0; i < arr.size(); i++)
	{
		cout << score[arr[i]] << " ";
	}
}