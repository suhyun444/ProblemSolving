#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

int n,k;
long long m;
long long maxLevel = 0;
vector<pair<long long,long long>> beer;
bool compare(pair<int,int> a,pair<int,int> b)
{
    return a.first > b.first;
}
bool func(int curLevel)
{
    int curCount = 0;
    long long curSatis = 0;
    for(int i=0;i<k;++i)
    {
        if(beer[i].second <= curLevel)
        {
            curCount++;
            curSatis += beer[i].first;
            if(curCount == n)
                break;
        }
    }
    return curSatis >= m && curCount == n;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i=0;i<k;++i)
    {
        long long a,b;
        cin >> a >> b;
        maxLevel = max(maxLevel,b);
        beer.push_back({a,b});
    }
    sort(beer.begin(),beer.end(),compare);
    long long lo = 0;
    long long hi = maxLevel + 1;
    while(lo + 1 < hi)
    {
        long long mid = (lo + hi) / 2;
        if(func(mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }
    if(hi == maxLevel + 1)cout << "-1";
    else cout << hi;
}
