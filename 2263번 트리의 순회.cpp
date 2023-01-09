#include <iostream>
#include <vector>

using namespace std;

int n;
int numToInOrderIndex[100001];
vector<int> inOrder;
vector<int> postOrder;
void Solve(int inStart,int inEnd,int postStart,int postEnd)
{
	if (inEnd < inStart || postEnd < postStart)
	{
		return;
	}
	int root = postOrder[postEnd];
	int rootInOrderIndex = numToInOrderIndex[root];
	int leftSize = rootInOrderIndex - inStart;
	cout << root << " ";
	Solve(inStart,rootInOrderIndex - 1,postStart, postStart + leftSize - 1);
	Solve(rootInOrderIndex + 1,inEnd,postStart + leftSize, postEnd - 1);

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;
		inOrder.push_back(item);
		numToInOrderIndex[item] = i;
	}
	for (int i = 0; i < n; i++)
	{
		int item;
		cin >> item;
		postOrder.push_back(item);
	}
	Solve(0,n-1,0, n - 1);
}