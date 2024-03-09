#include <iostream>

using namespace std;

int solve(int n)
{
    int sum = 3;
    for (int i = 0; i < n; i++)
    {
        sum = (sum-1) * 2;
    }
    return sum;
}

int main()
{
    int n,line;
    cin >> n;
    while (n--)
    {
		cin >> line;
        cout << solve(line);
        if (n != 0)
        	cout << endl;
    }
}