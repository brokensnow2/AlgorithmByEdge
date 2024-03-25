#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int count, n;
    cin >> count;
    while(count--)
    {
        cin >> n;
        printf("%lld\n", (long long)pow(3, n-1)+1);
    }
    return 0;
}