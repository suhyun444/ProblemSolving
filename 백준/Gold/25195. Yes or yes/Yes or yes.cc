#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

int n,m;
vector<int> adj[100001];
bool gomgom[100001];
bool dfs(int cur)
{
    if(gomgom[cur])return true;
    if(adj[cur].empty())return false;
    bool flag = true;
    for(int next : adj[cur])
    {
        flag = (dfs(next) && flag);
    }
    return flag;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;++i)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int s;
    cin >> s;
    for(int i=0;i<s;++i)
    {
        int a;
        cin >> a;
        gomgom[a] = true;
    }
    bool result = true;
    if(adj[1].empty())result = false;
    for(int next : adj[1])
    {
        result = (dfs(next) && result);
    }
    if(gomgom[1])result = true;
    cout << ((result) ? "Yes":"yes");
}