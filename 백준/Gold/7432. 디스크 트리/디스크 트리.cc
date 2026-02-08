#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <map>

using namespace std;

class Tree
{
    public:
    Tree(){};
    Tree(string name){this->name = name;}
    string name;
    map<string,Tree*> childs;
    void print(int depth)
    {
        for(int i=0;i<depth;++i)cout << " ";
        cout << name << "\n";
        for(auto& cur : childs)
        {
            cur.second->print(depth + 1);
        }
    }
    void addChild(string s)
    {
        int index = s.find('\\');
        if(index == -1)
        {
            childs[s] = new Tree(s);
        }
        else
        {
            string childName = s.substr(0,index);
            if(childs.find(childName) == childs.end())
            {
                Tree* cur = new Tree(childName);
                cur->addChild(s.substr(index + 1));
                childs.insert({childName,cur});
            }
            else
            {
                Tree* cur = childs[childName];
                cur->addChild(s.substr(index + 1));
            }
        }
    }
};

vector<string> arr;
map<string,Tree*> roots;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;++i)
    {
        string s;
        cin >> s;
        arr.push_back(s);
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;++i)
    {
        int index = arr[i].find('\\');
        if(index == -1)
        {
            if(roots.find(arr[i]) == roots.end())
                roots.insert({arr[i],new Tree(arr[i])});
        }
        else
        {
            string name = arr[i].substr(0,index);
            if(roots.find(name) == roots.end())
            {
                Tree* cur = new Tree(name);
                cur->addChild(arr[i].substr(index + 1));
                roots.insert({name,cur});
            }
            else
            {
                Tree* cur = roots[name];
                cur->addChild(arr[i].substr(index + 1));
            }
        }
    }
    for(auto& cur : roots)
    {
        cur.second->print(0);
    }
}