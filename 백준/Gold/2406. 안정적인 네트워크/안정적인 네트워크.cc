#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

int p[1001];
vector<pair<int,pair<int,int>>> adj;
int find(int cur)
{
    if(p[cur] == -1)return cur;
    return p[cur] = find(p[cur]);
}
bool merge(int a,int b)
{
    a = find(a);
    b = find(b);
    if(a!=b)
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
    int n,m;
    cin >> n >> m;
    int ans =0,count =0;
    int tmp = 0;
    for(int i=0;i<m;++i)
    {
        int a,b;
        cin >> a >> b;
        if(a == 1 || b == 1)continue;
        if(merge(a,b))
        {
            tmp++;
            count++;
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            int a;
            cin >> a;
            if(a == 0 || i == 0 || j == 0)continue;
            adj.push_back({a,{i + 1,j + 1}});
        }
    }
    sort(adj.begin(),adj.end());
    vector<pair<int,int>> result;
    for(int i=0;i<adj.size();++i)
    {
        if(count == n-2)
            break;
        if(merge(adj[i].second.first,adj[i].second.second))
        {
            ans += adj[i].first;
            count++;
            result.push_back({adj[i].second.first,adj[i].second.second});
        }
    }
    cout << ans << " " << count - tmp << "\n";
    for(int i=0;i<result.size();++i)
    {
        cout << result[i].first << " " << result[i].second << "\n";
    }
}
