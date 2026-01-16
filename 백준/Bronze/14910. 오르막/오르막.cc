#include <iostream>
#include <string>

using namespace std;

int main()
{
    int prev = -2e9;
    int n;
    while(scanf("%d",&n) != EOF)
    {
        if(n == EOF)break;
        if(n < prev)
        {
            printf("Bad");
            return 0;
        }
        prev = n;
    }
    printf("Good");
}