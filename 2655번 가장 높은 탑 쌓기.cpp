#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int cache[100];
int choice[101];
struct Brick
{
	int area;
	int index;
	int height;
	int weight;
	Brick(int area, int index, int height, int weight)
	{
		this->area = area;
		this->index = index;
		this->height = height;
		this->weight = weight;
	}
};
vector<Brick> brick;
bool compare(Brick a, Brick b)
{
	return a.area > b.area;
}
int solve(int n)
{
	int& ret = cache[n];
	if (ret != -1)return ret;
	ret = 0;
	for (int i = n + 1; i < brick.size();i++)
	{
		if (brick[n].weight > brick[i].weight && ret < solve(i) + brick[i].height)
		{
			ret = solve(i) + brick[i].height;
			choice[n] = i;
		}
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(cache, -1, sizeof(cache));
	memset(choice, -1, sizeof(cache));
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		brick.push_back(Brick(a,i+ 1,b,c));
	}
	brick.push_back(Brick(2e9, -1, 0, 2e9));
	sort(brick.begin(), brick.end(), compare);
	solve(0);
	vector<int> result;
	int cur = 0;
	while (choice[cur] != -1)
	{
		cur = choice[cur];
		result.push_back(brick[cur].index);
	}
	cout << result.size() << "\n";
	for (int i = result.size() - 1; i >= 0; i--)
	{
		cout << result[i] << "\n";
	}
}