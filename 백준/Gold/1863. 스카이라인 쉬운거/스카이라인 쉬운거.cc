#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    stack<int> s;
    int result = 0;
    for(int i=0;i<n;++i)
    {
        int x,y;
        cin >> x >> y;
        if((s.empty() || s.top() < y) && y != 0)
        {
            s.push(y);
        }
        else 
        {
            while(!s.empty() && s.top() > y)
            {
                result++;
                s.pop();
            }
            if((s.empty() || s.top() != y) && y != 0)
                s.push(y);
        }
    }
    if(result += s.size());
    cout << result;
}