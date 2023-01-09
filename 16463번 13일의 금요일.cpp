#include <iostream>

using namespace std;

bool IsLeapYear(int year)
{
	if (year % 400 == 0)return true;
	else if (year % 100 == 0)return false;
	else if (year % 4 == 0)return true;
	return false;
}
int GetLastDayOnThisMonth(int month,int year)
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	else if (month == 2)
	{
		if (IsLeapYear(year))
			return 29;
		else return 28;
	}
	return 30;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int curYear = 2019;
	int curMonth = 1;
	int curDay = 4;
	int result = 0;

	int n;
	cin >> n;
	while (curYear <= n)
	{
		curDay += 7;
		if (curDay == 13)result++;
		if (curDay > GetLastDayOnThisMonth(curMonth, curYear))
		{
			curDay -= GetLastDayOnThisMonth(curMonth, curYear);
			curMonth++;
		}
		if (curMonth > 12)
		{
			curMonth = 1;
			curYear++;
		}
	}
	cout << result;
}