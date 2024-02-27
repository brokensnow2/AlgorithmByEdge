# include <stdio.h>

int main()
{
    int num;
    int array[20];
    int i = 0;
    while (scanf("%d",&num) != EOF)
    {
        array[i] = num;
        i++;
    }
    for(int j = 0; j < i; j++)
    {
        printf("%d ",array[j]);
    }
    return 0;
}
