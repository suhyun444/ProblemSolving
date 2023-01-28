#include <iostream>
#include <cstring>

using namespace std;

int n;
int cache[1001][2][3];
int Solve(int cur,int late,int absent)
{
	if (late == 2 || absent == 3)return 0;
	if (cur == n)return 1;
	int& ret = cache[cur][late][absent];
	if (ret != -1)return ret;
	ret = 0;
	ret += Solve(cur + 1, late, 0);
	ret += Solve(cur + 1, late + 1, 0);
	ret += Solve(cur + 1, late, absent + 1);
	return ret % 1000000;
}
int main()
{
	memset(cache, -1, sizeof(cache));
	cin >> n;
	cout << Solve(0,0,0);
}