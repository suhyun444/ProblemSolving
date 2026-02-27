#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

vector<int> wordToIndex[26];
int needAlphabet[10001];
int lengthWord[10001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;++i)
    {
        string s;
        cin >> s;
        bool check[26] = {false,};
        for(int j=0;j<s.size();j++)
        {
            if(!check[s[j] - 'a'])
            {
                wordToIndex[s[j] - 'a'].push_back(i);
                check[s[j] - 'a'] = true;
            }
        }
    }
    int cur = n;
    for(int i=0;i<m;++i)
    {
        int a;
        char c;
        cin >> a >> c;
        if(a == 1)
        {
            for(int j=0;j<wordToIndex[c-'a'].size();++j)
            {
                if(needAlphabet[wordToIndex[c-'a'][j]] == 0)
                {
                    cur -= 1;
                }
                needAlphabet[wordToIndex[c-'a'][j]]++;
            }
        }
        else
        {
            for(int j=0;j<wordToIndex[c-'a'].size();++j)
            {
                needAlphabet[wordToIndex[c-'a'][j]]--;
                if(needAlphabet[wordToIndex[c-'a'][j]] == 0)
                {
                    cur += 1;
                }
            }
        }
        cout << cur<<"\n";
    }
}
