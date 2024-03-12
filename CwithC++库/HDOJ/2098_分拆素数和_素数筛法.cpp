#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10005;
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

int main() {
    sieve();
    int n;
    while (cin >> n && n != 0) {
        int count = 0;
        for (int i = 2; i <= n / 2; ++i) {
            if (is_prime[i] && is_prime[n - i] && i != n - i) 
            {
                ++count;
            }
        }
        cout << count << endl;
    }
    return 0;
}
