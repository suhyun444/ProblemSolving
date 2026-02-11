#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

int n,m;
vector<int> adj[1001];
int indegree[1001];
int ans[1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;++i)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<int> q;
    for(int i=1;i<=n;++i)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
        
    int count = 1;
    while(!q.empty())
    {
        int size = q.size();
        for(int i=0;i<size;++i)
        {
            int cur = q.front();
            q.pop();
            ans[cur] = count;
            for(int next : adj[cur])
                if(--indegree[next] == 0)
                    q.push(next);
        }
        count++;
    }
    for(int i=1;i<=n;++i)
    {
        cout << ans[i] << " ";
    }
}
