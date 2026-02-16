#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

int n,m;
bool vip[42];
int cache[42];
int solve(int cur)
{
    if(cur > n + 1)return 0;
    if(cur == n + 1)
    {
        return 1;
    }
    int& ret = cache[cur];
    if(ret != -1)
        return ret;

    if(vip[cur])
        ret = solve(cur + 1);
    else if(!vip[cur + 1])
        ret = solve(cur + 1) + solve(cur + 2);
    else
        ret = solve(cur + 1);
        
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cache,-1,sizeof(cache));
    cin >> n;
    cin >> m;
    for(int i=0;i<m;++i)
    {
        int a;
        cin >> a;
        vip[a] = true;
    }
    cout << solve(1);
}
