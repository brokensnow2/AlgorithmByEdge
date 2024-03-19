#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

long long move(int n)
{
    if (n == 1)
        return 2;
    else if (n == 2)
    	return 4;
    return move(n-2) + pow(2, n-1) + pow(2, n-2) + 1;
}

int main()
{
	int n;
    while(cin >> n)
    {
        printf("%lld\n", move(n));
    }
    return 0;
}