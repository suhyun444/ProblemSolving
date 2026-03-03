#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

//답은 long long
//dp?[n][state][first_state] or [n][state]
//n이 커서 백트레킹 불가능
//그리디 or dp
int n;
long long cache[250000][2][2];
vector<long long> arr;
long long solve(int cur,int state,int first_state)
{
    if(cur == n)
    {
        return 0;
    }
    long long& ret = cache[cur][state][first_state];
    if(ret != -1) return ret;
    if(cur == n-1)
    {
        ret = solve(cur + 1,0,first_state) + arr[cur];
        if(first_state == 0 && state == 0)
            ret = max(ret, solve(cur + 1,1,first_state) + 1);
    }
    else
    {
        ret = solve(cur + 1,0,first_state) + arr[cur];
        if(state == 0)
            ret = max(ret,solve(cur + 1,1,first_state) + 1);
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cache,-1,sizeof(cache));
    cin >> n;
    for(int i=0;i<n;++i)
    {
        long long a;
        cin >> a;
        arr.push_back(a);
    }
    cout << max(solve(1,0,0) + arr[0],solve(1,1,1) + 1);
}
