#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 3000;
vector<bool> is_prime(MAXN, true);

// 素数筛法
void sieve() 
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < MAXN; ++i) 
    {
        if (is_prime[i]) 
        {
            for (int j = i * i; j < MAXN; j += i) 
            {
                is_prime[j] = false;
            }
        }
    }
}

int main()
{
	int n;
    int x;
    int y[3];
    cin >> n;
    sieve();
    while (n--)
    {
        cin >> x;
        while (x >= 50 && x <= 0)
			cin >> x;
        for (int i = 0; i < 3; ++i)
        {
            cin >> y[i];
            while (y[i] <= 0 || y[i] >= 50)
        	cin >> y[i];
        }
		int count = 0;
        for (int i = 0; i < 3; i++)
        {
            if (is_prime[((x-y[i]) * (x-y[i]) + (x-y[i]) + 41)])
            	count++;
        }
        if (count == 3)
        	cout << "WIN" << endl;
        else
        	cout << count << endl;
        
		
    }
}