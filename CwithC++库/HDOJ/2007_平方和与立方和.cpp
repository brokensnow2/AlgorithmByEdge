#include <iostream>
#include <cmath>

int main()
{
    int m, n;
    long long EvenPow2 = 0, OddPow3 = 0;
    while(std::cin >> m >> n)
    {
        if(m > n)
        {
            std::swap(m, n);
        }

        for(int i = m; i <= n; i++)
        {
            if(i % 2 == 0)
            {
                EvenPow2 += std::pow(i, 2);
            }
            else
            {
                OddPow3 += std::pow(i, 3);
            }
        }

        std::cout << EvenPow2 << " " << OddPow3 << std::endl;
        EvenPow2 = 0;
        OddPow3 = 0;
    }

    return 0;
}
