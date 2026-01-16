#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    while(true)
    {
        cin >> s;
        if(s == "#")break;
        bool isBeautiful = true;
        for(int i=1;i<s.length();++i)
        {
            int diff1 = s[i] - s[i-1]; 
            int diff2 = s[i] + 7 - s[i-1]; 
            if(!(diff1 == 2 || diff1 == 4 || diff1 == 6 || diff2 == 2 || diff2 == 4 || diff2 == 6))
            {   
                isBeautiful = false;
                break;
            }
        }
        if(isBeautiful)
            cout << "That music is beautiful.\n";
        else
            cout << "Ouch! That hurts my ears.\n";
    }
}