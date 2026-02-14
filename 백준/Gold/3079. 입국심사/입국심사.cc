#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

long long n,m;
vector<long long> arr;
bool func(long long curLevel)
{
    long long curCount = 0;
    for(int i=0;i<n;++i)
    {
        curCount += curLevel / arr[i];
        if(curCount >= m)break;
    }
    return curCount >= m;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;++i)
    {
        long long a;
        cin >> a;
        arr.push_back(a);
    }
    long long lo = 0;
    long long hi = 8e18;
    while(lo + 1< hi)
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
    cout << hi;
}
