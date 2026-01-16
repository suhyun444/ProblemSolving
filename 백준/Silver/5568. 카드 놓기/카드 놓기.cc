#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;
vector<int> arr;
vector<int> back;
vector<int> result;
bool visited[11];
void dfs(int index,int current)
{
    if(current == k)
    {
        int sum= 0;
        for(int i=0;i<back.size();++i)
        {
            sum *= 10;
            if(back[i] / 10 > 0)sum *= 10;
            sum += back[i];
        }
        result.push_back(sum);
        return;
    }
    for(int i=0;i<n;++i)
    {
        if(visited[i]) continue;
        visited[i] = true;
        back.push_back(arr[i]);
        dfs(i + 1,current + 1);
        back.pop_back();
        visited[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> k;
    int item;
    for(int i=0;i<n;++i)
    {
        cin >> item;
        arr.push_back(item);
    }
    dfs(0,0);
    sort(result.begin(),result.end());
    result.erase(unique(result.begin(),result.end()),result.end());
    cout << result.size();
}