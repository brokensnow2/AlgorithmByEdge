#include <iostream>
#include <iomanip>

int main()
{
    int m;
    std::cin >> m;
    while(m--)
    {
        int n;
        std::cin >> n;
        double sum = 0.0;
        for(int i = 1; i <= n; i++)
        {
            if(i % 2 == 0)
            {
                sum -= 1.0 / i;
            }
            else
            {
                sum += 1.0 / i;
            }
        }
        std::cout << std::fixed << std::setprecision(2) << sum << std::endl;
    }
    return 0;
}
