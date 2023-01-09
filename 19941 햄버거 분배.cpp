#include <iostream>

using namespace std;

bool visited[20000] = { false };
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'P')
        {
            for (int j = max(i - k, 0); j < min(i + k + 1, n); j++)
            {
                if (s[j] == 'H' && !visited[j])
                {
                    visited[j] = true;
                    result++;
                    break;
                }
            }
        }
    }
    cout << result;
}