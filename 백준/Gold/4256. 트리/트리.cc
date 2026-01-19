#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int n;
int cur = 0;
struct Tree
{
    Tree()
    {
        left = nullptr;
        right = nullptr;
        item = 0;
    }
    Tree* left;
    Tree* right;
    int item;
};

Tree* t;
vector<int> pre;
vector<int> in;
Tree* initTree(int l,int r)
{
    if(l == r) return nullptr;
    Tree* tree = new Tree();
    tree->item = pre[cur++];
    for(int i=l;i<r;++i)
    {
        if(in[i] == tree->item)
        {
            tree->left = initTree(l,i);
            tree->right = initTree(i + 1,r);
        }
    }
    return tree;
}
void postorder(Tree* tree)
{
    if(tree->left != nullptr)
        postorder(tree->left);
    if(tree->right != nullptr)
        postorder(tree->right);
    cout << tree->item << " ";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int item = 0;
        for(int i=0;i<n;++i)
        {
            cin >> item;
            pre.push_back(item);
        }
        for(int i=0;i<n;++i)
        {
            cin >> item;
            in.push_back(item);
        }
        Tree* root = initTree(0,n);
        postorder(root);
        cout << "\n";
        cur = 0;
        pre.clear();
        in.clear();
    }
}