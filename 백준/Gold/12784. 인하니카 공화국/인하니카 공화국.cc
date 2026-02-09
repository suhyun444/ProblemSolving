#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <map>

using namespace std;

vector<pair<int,int>> adj[1001];
bool visited[1001];
int dfs(int cur)
{
    visited[cur] = true;
    if(cur != 1 && adj[cur].size() == 1)
    {
        return 2e9;
    }
    int ret = 0;
    for(pair<int,int> next : adj[cur])
    {
        if(visited[next.first]) continue;
        ret += min(next.second,dfs(next.first));
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        for(int i=0;i<m;++i)
        {
            int a,b,c;
            cin >> a >> b >> c;
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        cout << dfs(1) << "\n";
        for(int i=1;i<=n;++i)
        {
            adj[i].clear();
            visited[i] = false;
        }
    }
}