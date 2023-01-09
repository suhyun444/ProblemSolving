#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
int cache[101][10001];
vector<int> use;
vector<int> cost;
int solve(int n, int c)
{
    if (n == N)return 0;
    int& ret = cache[n][c];
    if (ret != -1)return ret;
    ret = solve(n + 1, c);
    if (c - cost[n] >= 0)
    {
        ret = max(ret, solve(n + 1, c - cost[n]) + use[n]);
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        use.push_back(a);
    }
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        cost.push_back(a);
    }
    int c = 0;
    while (true)
    {
        if (solve(0, c) >= M)
        {
            cout << c;
            return 0;
        }
        c++;
    }
}
