#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> arr;
int t,w;
int cache[2][31][1001];
int dp(int state,int coin,int time)
{
    if(time == t)
        return 0;
    int& ret = cache[state][coin][time];
    if(ret != -1)return ret;
    ret = 0;
    if(arr[time] == state)
    {
        ret = dp(state,coin,time + 1) + 1;
    }
    else
    {
        if(coin < w)
            ret = dp(!state,coin + 1,time + 1) + 1;
        ret = max(ret, dp(state,coin,time + 1));
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cache,-1,sizeof(cache));
    cin >> t >> w;
    int item;
    for(int i=0;i<t;++i)
    {
        cin >> item;
        arr.push_back(item - 1);
    }
    cout << dp(0,0,0);
}