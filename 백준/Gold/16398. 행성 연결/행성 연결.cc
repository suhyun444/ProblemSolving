#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

int n;

vector<pair<pair<int,int>,int>> edges;
int p[1001];
bool compare(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b)
{
    return a.second < b.second;
}
int find(int cur)
{
    if(p[cur] == -1)return cur;
    return p[cur] = find(p[cur]);
}
bool merge(int a,int b)
{
    a = find(a);
    b = find(b);
    if(a != b)
    {
        p[b] = a;
        return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(p,-1,sizeof(p));
    cin >> n;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            int cost;
            cin >> cost;
            edges.push_back({{i,j},cost});
        }
    }
    int count = 0;
    long long ans = 0;
    sort(edges.begin(),edges.end(),compare);
    for(int i=0;i<edges.size();++i)
    {
        if(merge(edges[i].first.first,edges[i].first.second))
        {
            ans += edges[i].second * 1LL;
            count++;
        }
        if(count == n-1)
        {
            cout << ans;
            return 0;
        }
    }
}