#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

int numAlpha[26];
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(numAlpha, 0, sizeof(numAlpha));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            numAlpha[s[j] - 'A'] += pow(10, s.size() - j - 1);
        }
    }
    int result = 0;
    int value = 9;
    while (true) {
        int maxIndex = -1;
        for (int i = 0; i < 26; i++) {
            if (maxIndex == -1 || numAlpha[maxIndex] < numAlpha[i]) {
                maxIndex = i;
            }
        }
        if (numAlpha[maxIndex] == 0)break;
        else{
            result += numAlpha[maxIndex] * value;
            numAlpha[maxIndex] = 0;
            value--;
        }
    }
    cout << result;
    
}
