/**
 * todo 解题思路
 * 两层for循环
 * 
*/
#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int yi[100]; // yi's height, xi is index :0, 1, ...

int main()
{
    // number of lines
	int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    	cin >> yi[i];
    // max
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
			int ans = (i - j) * min(yi[i], yi[j]);
            if (ans > max)
            	max = ans;
        }
    }
    cout << max << endl;
}