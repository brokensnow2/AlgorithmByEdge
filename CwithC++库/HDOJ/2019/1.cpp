/**
 * todo 解题思路：
 * 奇偶判断
 * 
*/
#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

int main()
{
    // number of people
    int n;
    cin >> n;
    int adults = 0, kids = 0;
    int temp;
    for (int i = 0; i < n; ++i)
    {
		cin >> temp;
        if (temp % 2 == 0) // even is kids
        	++kids;
        else
        	++adults;
    }
    cout << kids  << " "; 
    cout << fixed << setprecision(2) << (double)kids/n << endl;

}