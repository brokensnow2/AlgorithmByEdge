#include <iostream>
#include <stdio.h>

using namespace std;
/**
 * 假如n=10；
 * 
 * 老牛：10
 * 
 * 
 * 
*/

void cow(int &sum,int age)
{
    sum += age;
    //终止条件
    if (age <= 3)
    	return;
    else
    {
        for (int i = 0; i < age - 3; i++)
        {
            cow(sum, age - 3 - i);
        }
    }
}

int main()
{
    int n;
    int num = 0;
    while (cin >> n)
    {
        cow(num,n-1);
        cout << num+1 << endl;
        num = 0;
    }
    
    return 0;
}