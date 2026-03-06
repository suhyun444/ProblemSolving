#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <stack>

using namespace std;

int cnt[100001];
int idx[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0;i<n;++i)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    stack<int> s;
    for(int i=0;i<n;++i)
    {
        while(!s.empty() && arr[s.top()] <= arr[i])
        {
            s.pop();
        }
        cnt[i] += s.size();
        if(!s.empty()) idx[i] = s.top();
        s.push(i);
    }
    while(!s.empty())s.pop();
    for(int i=n-1;i>=0;--i)
    {
        while(!s.empty() && arr[s.top()] <= arr[i])
        {
            s.pop();
        }
        if(!s.empty() && (cnt[i] == 0 || i - idx[i] > s.top() - i))
        {
            idx[i] = s.top();
        }
        cnt[i] += s.size();
        s.push(i);
    }
    for(int i=0;i<n;++i)
    {
        cout << cnt[i] << " ";
        if(cnt[i] != 0)cout << idx[i] + 1;
        cout << "\n";
    }
}
