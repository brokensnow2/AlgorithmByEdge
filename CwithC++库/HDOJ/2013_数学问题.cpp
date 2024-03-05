#include <iostream>
#include <stdio.h>
/**
 *  X-(X/2 - 1) = 1
 * 	=> X=4
 *  X-(X/2 - 1) = 4
 * 
*/
int main()
{
    int n,num = 1;
    while (scanf("%d",&n) != EOF)
    {
    	for (int i = 1; i < n; i++)
        {
            num = (num + 1) * 2;
        }
        printf("%d\n", num);
        num = 1;
    }
    
}