#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

int c[52][52];
int f[52][52];
vector<int> adj[52];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;++i)
    {
        char a,b;
        int ia,ib,cost;
        cin >> a >> b >> cost;
        if('a' <= a && a <= 'z')
            ia = a - 'a';
        else
            ia = a - 'A' + 26;
        if('a' <= b && b <= 'z')
            ib = b - 'a';
        else
            ib = b - 'A' + 26;
        c[ia][ib] = c[ib][ia] += cost;
        adj[ia].push_back(ib);
        adj[ib].push_back(ia);
    }
    int total = 0,s = 26,e = 51;
    while(1)
    {
        int prev[52];
        fill(prev,prev + 52,-1);
        queue<int> q;
        q.push(s);
        while(!q.empty() && prev[e] == -1)
        {
            int cur = q.front();
            q.pop();
            for(int next: adj[cur]){
                if(c[cur][next]-f[cur][next] > 0 && prev[next] == -1){
                    q.push(next);
                    prev[next] = cur;
                    if(next == e) break;
                }
            }
        }
        if(prev[e] == -1) break;
 
        int flow = 2e9;
        for(int i=e; i!=s; i=prev[i])
        {
            flow = min(flow, c[prev[i]][i]-f[prev[i]][i]);
        }
        for(int i=e; i!=s; i=prev[i]){
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
        total += flow;
    }
    cout << total;
}