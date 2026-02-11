#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <map>

using namespace std;

int cache[31];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    memset(cache,-1,sizeof(cache));
    cache[1] = 1;
    cache[2] = 3;
    for(int i=3;i<=n;++i)
        cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 2];
    int result = cache[n];
    cache[1] = 1;
    cache[2] = 3;
    cache[3] = 1;
    cache[4] = 5;
    for(int i=5;i<=n;++i)
        cache[i] = cache[i - 2] + cache[i - 4] + cache[i - 4];
    cout << result - (result - cache[n]) / 2;
}