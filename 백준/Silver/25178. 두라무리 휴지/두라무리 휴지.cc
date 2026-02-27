#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s1,s2;
    cin >> s1 >> s2;
    if (s1[0] != s2[0] || s1[n-1] != s2[n-1]) {
        cout << "NO";
        return 0;
    }
    string sorted1 = s1;
    string sorted2 = s2;
    sort(sorted1.begin(), sorted1.end());
    sort(sorted2.begin(), sorted2.end());
    if (sorted1 != sorted2) {
        cout << "NO";
        return 0;
    }
    string ans1 = "", ans2 = "";
    for (int i=0;i<n;++i) {
        if (!isVowel(s1[i])) ans1 += s1[i];
    }
    for (int i=0;i<n;++i) {
        if (!isVowel(s2[i])) ans2 += s2[i];
    }
    if (ans1 != ans2) {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}
