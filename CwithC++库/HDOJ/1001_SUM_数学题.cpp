/**
 * 1+2+3+...+n = (n+1)*n/2
 * 
*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
       long long sum = (n + 1) * (double)(n / 2.00);
       cout << sum << endl << endl;
    }
    
}