#include<iostream>
using namespace std;
int a = 0;
unsigned long long b = 1;

unsigned long long c = 0;
int arr[1000];
int arr1[1000];

int main() {
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> arr[i];
        cin >> arr1[i];
    }
    for (int l = 0; l < a; l++) {
        for (int y = 1; y <= arr1[l]; y++)
        {

            b = (b % 10) * arr[l];

        }
        c = b % 10;
        if (c == 0)
            cout << "10\n";
        else
            cout << c << "\n";
        b = 1;
        c = 0;
    }
}