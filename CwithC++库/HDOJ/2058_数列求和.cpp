#include <iostream>
#include <cstdio>

using namespace std;

bool isFactor(int m, int factor)
{
	if (m % factor == 0)
        return true;
    else
    	return false;
}

int main()
{
    int n,m;
    while (cin >> n >> m && (n || m))
    {
        if (n >= m)
        {
            // find factors
            for (int i = 1; i <= m; i++)
            {
                if (isFactor(m, i))
                {
                    int quotient = m / i;
                    // if quotient is even
                    if (quotient % 2 == 0)
                    {
                        int left_index = i / quotient - (quotient - 1);
                        int right_index = i / quotient + quotient;
                        // illegal judge
						if (left_index > 0)
                            printf("[%d,%d]\n", left_index, right_index);
                    }
                    else // if quotient is odd
                    {
						int left_index = i - (quotient / 2);
                        int right_index = i + (quotient /2);
                        if (left_index > 0)
                            printf("[%d,%d]\n", left_index, right_index);
                    }
                }
                
            }
            
        }
        printf("\n");
        
    }
    
}