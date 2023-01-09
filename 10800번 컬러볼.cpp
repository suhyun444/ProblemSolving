#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int result[200001];
int colorWeight[200001];
int weights[2001];
vector<pair<int,pair<int,int>>> balls;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		balls.push_back({ b,{a,i} });
	}
	sort(balls.begin(), balls.end());
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		colorWeight[balls[i].second.first] += balls[i].first;
		weights[balls[i].first] += balls[i].first;
		sum += balls[i].first;
		result[balls[i].second.second] = sum - colorWeight[balls[i].second.first] - weights[balls[i].first] + balls[i].first;
		if (i != 0 && (balls[i - 1].second.first == balls[i].second.first) && (balls[i - 1].first== balls[i].first))    
			result[balls[i].second.second] = result[balls[i - 1].second.second];
	}
	for (int i = 0; i < n; i++)
	{
		cout << result[i] << "\n";
	}
}0