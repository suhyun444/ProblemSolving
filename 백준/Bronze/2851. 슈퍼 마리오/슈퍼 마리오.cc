#include <iostream>

using namespace std;

int main()
{
	int cur = 0;
	int result = 0;
	for (int i = 0; i < 10; ++i)
	{
		int item;
		cin >> item;
		if (cur + item >= 100)
		{
			result = (100 - cur < cur + item - 100) ? cur : cur + item;
			break;
		}
		cur += item;
		if (i == 9)result = cur;
	}
	std::cout << result;
}