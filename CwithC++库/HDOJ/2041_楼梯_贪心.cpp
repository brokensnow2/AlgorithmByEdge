#include <iostream>

using namespace std;

int getStair(int n)
{
    if (n == 1)
    	return 1;
    else if (n == 2)
        return 2;
    else
    	return getStair(n-1) + getStair(n-2);
}

int main()
{
	int n,stair;
    cin >> n;
    while (n--)
    {
		cin >> stair;
        cout << getStair(stair-1) << endl;
    }
}