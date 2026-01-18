#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int s, n[2];
vector<int> arr[2];
map<int,int> m[2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    cin >> n[0] >> n[1];
    int item;
    for(int i=0;i<n[0];++i)
    {
        cin >> item;
        arr[0].push_back(item);
    }
    for(int i=0;i<n[1];++i)
    {
        cin >> item;
        arr[1].push_back(item);
    }
    m[0].insert({0,1});
    m[1].insert({0,1});
    for(int k=0;k<2;++k)
    {
        for(int i=0;i<n[k];++i)
        {
            int sum = 0;
            for(int j=i;j - i < n[k];++j)
            {
                if(i != 0 && j %n[k] == i-1)continue;
                sum += arr[k][j % n[k]];
                if(sum > s)break;
                if(m[k].find(sum) == m[k].end())
                m[k].insert({sum,1});
                else
                m[k][sum] += 1;
            }
        }
    }
    int result = 0;
    for(int i=0;i<=s;++i)
    {
        result += m[0][i] * m[1][s-i];
    }
    cout << result;
}