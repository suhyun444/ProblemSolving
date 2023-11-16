#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
	Student(int nation, int number, int score)
	{
		this->nation = nation;
		this->number = number;
		this->score = score;
	}
	int nation;
	int number;
	int score;
};
vector <Student> arr;
bool Compare(const Student& a, const Student& b)
{
	return a.score > b.score;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		arr.push_back(Student(a,b,c));
	}
	sort(arr.begin(), arr.end(),Compare);
	int nationCount[101] = { 0 };
	int count = 0;
	for (int i = 0; count < 3; ++i)
	{
		if (nationCount[arr[i].nation] < 2)
		{
			nationCount[arr[i].nation]++;
			cout << arr[i].nation << " " << arr[i].number << "\n";
			count++;
		}
	}
}
