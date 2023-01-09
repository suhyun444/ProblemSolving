#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, n, m, k, d;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k >> d;
        int localMatchCount = n * ((m * (m - 1)) / 2);
        int unLocalMatchCount = ((n * (n - 1)) / 2) * m * m;
        int b = 1;
        int a = k;
        int previousD = 0;
        while (true)
        {
            int curD = a * localMatchCount + b * unLocalMatchCount;
            if (curD > d)break;
            previousD = curD;
            a += k;
            b++;
        }
        if (previousD == 0)cout << "-1\n";
        else cout << previousD << "\n";
    }
}