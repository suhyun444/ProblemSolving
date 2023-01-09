#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[10];
bool BinarySearch(int key) //존재하면 true 존재하지않으면 false 리턴
{
	int lo = 0;
	int hi = n - 1;
	while (lo <= hi) //
	{
		int mid = (lo + hi) / 2;
		if (arr[mid] == key)
		{
			return true;
		}
		if (arr[mid] > key)
		{
			hi = mid - 1; //
		}
		else if (arr[mid] < key)
		{
			lo = mid + 1; //
		}
	}
	//이분탐색검색하면 stl binary_search 이거 쓰지말고 풀어봐
	return false;
}