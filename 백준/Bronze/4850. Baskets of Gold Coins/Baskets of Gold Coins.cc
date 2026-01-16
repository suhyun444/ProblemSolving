#include <iostream>

using namespace std;

int sum(int n)
{
    if(n == 1)return n;
    return n + sum(n-1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,w,d,s;
    while(cin >> n >> w >> d >> s)
    {
        int result = sum(n - 1) * w;
        result -= s;
        if(result == 0)cout << n << "\n";
        else cout << (result / d) << "\n";
    }
}