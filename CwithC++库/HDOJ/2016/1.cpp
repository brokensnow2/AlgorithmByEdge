/**
 * todo 解题思路
 * 素数筛法，但MAX太大会爆
*/
#include <cstdio>
#include <iostream>
#include <vector>
#define MAX 10000
using namespace std;

vector<bool> is_prime(MAX, true);

void seive()
{
	is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i < MAX; i++)
    {
        if (is_prime[i])
        {
            for (int j = i*i; j < MAX; j += i)
            {
				is_prime[j] = false;
            }
        }
    }
}

int main()
{
    seive();
	int n;
    while (cin >> n)
    {
		if (is_prime[n])
        	cout << "YES" << endl;
        else
        	cout << "NO" << endl;
    }
}