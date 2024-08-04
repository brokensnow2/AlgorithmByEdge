#include <iostream>

using namespace std;

long long digital_roots(long long num)
{
    long long ans = 0;
    while (num != 0)
    {
        ans += num % 10;
        num = num / 10;
    }
    return ans;
}

int main()
{
    long long num;
    while (cin >> num && num != 0)
    {
        long long result = digital_roots(num);
        while (result >= 10)
        {
            result = digital_roots(result);
        }
        cout << result << endl;
    }
    
}