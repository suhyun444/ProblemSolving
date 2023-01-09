#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
int cache[1001];
vector<int> cards;
int solve(int n)
{
    if (n == N)return 0;
    int& ret = cache[n];
    if (ret != -1)return ret;
    ret = 1e9;
    for (int i = 0; i < N; i++)
        if (n + i + 1 <= N)
            ret = min(ret, solve(n + i + 1) + cards[i]);
    
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cache, -1, sizeof(cache));
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        cards.push_back(a);
    }
    cout << solve(0);
}
