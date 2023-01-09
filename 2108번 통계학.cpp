#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	map<int, int> s;
	vector<int> arr;
	double n;
	cin >> n;
	double sum = 0;
	int maxNum = -2e9;
	int minNum = 2e9;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;
		arr.push_back(item);
		sum += item;
		if (s.find(item) != s.end())
		{
			s[item]++;
		}
		else
		{
			s.insert({ item,1 });
		}
		maxNum = max(maxNum, item);
		minNum = min(minNum, item);
	}
	vector<int> copy_arr = arr;
	sort(copy_arr.begin(), copy_arr.end());
	int center = copy_arr[n / 2];
	int maxCount = 0;
	int maxCountValue = 0;
	bool isFind = false;
	for (pair<int, int> p : s)
	{
		if (maxCount < p.second)
		{
			maxCountValue = p.first;
			maxCount = p.second;
		}
	}
	vector<int> mostFinded;
	for (pair<int, int> p : s)
	{
		if (maxCount == p.second)
		{
			mostFinded.push_back(p.first);
		}
	}
	sort(mostFinded.begin(), mostFinded.end());
	double average = sum / n;
	if(average < 0)
		average -= 0.5f;
	else
		average += 0.5f;
	int intAverage = average;
	cout << intAverage<< "\n";
	cout << center << "\n";
	if (mostFinded.size() >= 2)
		cout << mostFinded[1] << "\n";
	else
		cout << mostFinded[0] << "\n";
	cout << maxNum - minNum << "\n";

}