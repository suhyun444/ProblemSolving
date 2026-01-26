#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;


vector<int> grade[21];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;++i)
    {
        string s;
        cin >> s;
        grade[s.length()].push_back(i);
    }
    queue<int> q;
    long long result = 0;
    for(int i=2;i<21;++i)
    {
        if(grade[i].empty())
            continue;
        q.push(grade[i][0]);
        int index = 1;
        while(index < grade[i].size())
        {
            if(q.empty() || grade[i][index] - q.front() <= k)
            {
                result += q.size();
                q.push(grade[i][index]);
                index++;
            }
            else
            {
                q.pop();
                continue;
            }
        }
        while(!q.empty())q.pop();
    }
    cout << result;
}