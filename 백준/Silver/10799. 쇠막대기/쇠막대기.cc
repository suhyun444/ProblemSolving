#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int current = 0;
    int result = 0;
    for(int i=0;i<s.length();++i)
    {
        if(s[i] == '(')
        {
            if(i + 1 != s.length() && s[i + 1] == ')')
            {
                result += current;
                i++;
            }
            else
            {
                ++current;
            }
        }
        else
        {
            result += 1;
            --current;
        }
    }
    cout << result;
}