/**
 * 	3*2:			3*3:
 * 		+---+			+---+
		|   |			|	|
		|   |			|	|
		+---+			|	|
 * 						+---+
*/

#include <cstdio>
#include <iostream>

using namespace std;

void draw(int n, int m)
{
    for (int i = 0; i < m + 2; i++)
    {
        for (int j = 0; j < n + 2; j++)
        {
            if (j == 0 || j == n + 1)
            {
				if (i == 0 || i == m + 1)
                	printf("+");
                else
                    printf("|");
            }
            else
            {
                if (i == 0 || i == m + 1)
                	printf("-");
                else
                    printf(" ");
            }

        }
        printf("\n");
    }
}

int main()
{	// width, height
    int n,m;
	while (scanf("%d%d", &n, &m) != EOF)
    {
		draw(n,m);
        printf("\n");
    }
}