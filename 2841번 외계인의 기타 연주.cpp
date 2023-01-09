#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int result = 0;
	int n, p;
	priority_queue<int> curStatus[6];
	cin >> n >> p;
	for (int i = 0; i < n; i++)
	{
		int lineNumber, platNumber;
		cin >> lineNumber >> platNumber;
		lineNumber--;
		if (curStatus[lineNumber].empty())
		{
			curStatus[lineNumber].push(platNumber);
			result++;
		}
		else
		{
			while (!curStatus[lineNumber].empty() && curStatus[lineNumber].top() > platNumber)
			{
				curStatus[lineNumber].pop();
				result++;
			}
			if (curStatus[lineNumber].empty() || curStatus[lineNumber].top() < platNumber)
			{
				curStatus[lineNumber].push(platNumber);
				result++;
			}
		}
	}
	cout << result;
}