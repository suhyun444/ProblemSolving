#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

int n,m;
int dist[1001];
vector<pair<int,int>> road1;
vector<pair<int,int>> road2;
vector<pair<int,int>> adj[1001];
int dijkstra()
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<=n;++i)dist[i] = 1e9;
    pq.push({0,1});
    dist[1] = 0;
    while(!pq.empty())
    {
        pair<int,int> cur = pq.top();
        pq.pop();
        if(cur.second == n)break;
        for(pair<int,int> next : adj[cur.second])
        {
            if(cur.first + next.second < dist[next.first])
            {
                dist[next.first] = cur.first + next.second;
                pq.push({dist[next.first], next.first});
            }
        }
    }
    return dist[n];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;++i)
    {
        int a,b,c;
        cin >> a >> b >> c;
        road1.push_back({a,adj[a].size()});
        road2.push_back({b,adj[b].size()});
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    int minTime = dijkstra();
    int ans = 0;
    for(int i=0;i<m;++i)
    {
        int temp1 = adj[road1[i].first][road1[i].second].second;
        int temp2 = adj[road2[i].first][road2[i].second].second;
        adj[road1[i].first][road1[i].second].second = 1e9;
        adj[road2[i].first][road2[i].second].second = 1e9;
        ans = max(ans,dijkstra());
        adj[road1[i].first][road1[i].second].second = temp1;
        adj[road2[i].first][road2[i].second].second = temp2;
    }
    if(ans == 1e9) cout << "-1";
    else cout << ans - minTime;
}