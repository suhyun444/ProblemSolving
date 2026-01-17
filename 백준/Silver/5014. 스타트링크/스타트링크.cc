#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[1000001];
int f,s,g,u,d;

int bfs()
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    int level = 0;
    while(!q.empty())
    {
        int size = q.size();
        for(int i=0;i<size;++i)
        {
            int cur = q.front();
            q.pop();
            int up = cur + u;
            if(up <= f && !visited[up])
            {
                if(up == g) return level + 1;
                q.push(up);
                visited[up] = true;
            }
            int down = cur - d;
            if(down > 0 && !visited[down])
            {
                if(down == g) return level + 1;
                q.push(down);
                visited[down] = true;
            }
        }
        level++;
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> f >> s >> g >> u >> d;
    if(s == g)
    {
        cout << "0";
        return 0;
    }
    int result = bfs();
    if(result == -1)
        cout << "use the stairs";
    else
        cout << result;
}