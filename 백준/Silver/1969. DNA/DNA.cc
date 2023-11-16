#include <iostream>
#include <vector>

using namespace std;

int DNAToIndex(char dna)
{
	if (dna == 'A')return 0;
	else if (dna == 'C')return 1;
	else if (dna == 'G')return 2;
	else return 3;
}
char indexToDNA[4] = { 'A','C','G','T' };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> dnas(n);
	string resultDNA = "";
	int result = 0;
	for (int i = 0; i < n; ++i)cin >> dnas[i];
	for (int i = 0; i < m; ++i)
	{
		int arr[4] = { 0 };
		for (int j = 0; j < n; ++j)
		{
			arr[DNAToIndex(dnas[j][i])]++;
		}
		int maxNumIndex = 0;
		for (int j = 1; j < 4; ++j)if (arr[j] > arr[maxNumIndex])maxNumIndex = j;
		result += n - arr[maxNumIndex];
		resultDNA += indexToDNA[maxNumIndex];
	}
	cout << resultDNA << "\n";
	cout << result;
}