#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int pig[6];
        int next[6];
        int sum = 0;
        for (int i = 0; i < 6; ++i)
        {
            cin >> pig[i];
            sum += pig[i];
        }
        if (n < sum)
        {
            cout << 1 << "\n";
            continue;
        }
        int count = 1;
        while (true)
        {
            count++;
            int result = 0;
            for (int i = 0; i < 6; ++i)
            {
                next[i] = pig[i] + pig[(i - 1 < 0) ? 5 : i - 1] + pig[(i + 1) % 6] + pig[(i + 3) % 6];
                result += next[i];
            }
            if (n < result)
            {
                break;
            }
            for (int i = 0; i < 6; ++i)pig[i] = next[i];
        }
        cout << count << "\n";
    }
}