#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

int n;
vector<pair<int,int>> arr;
int cache[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cache,-1,sizeof(cache));
    cin >> n;
    for(int i=0;i<n;++i)
    {
        int x,y;
        cin >> x >> y;
        arr.push_back({x,y});
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;++i)
    {
        int minCost = abs(arr[i].second) * 2;
        cache[i] = 2e9;
        for(int j=i;j>=0;--j)
        {
            minCost = max(minCost,abs(arr[j].second) * 2);
            cache[i] = min(cache[i],cache[j-1] + max(arr[i].first - arr[j].first,minCost));
        }
    }
    cout << cache[n-1];
}