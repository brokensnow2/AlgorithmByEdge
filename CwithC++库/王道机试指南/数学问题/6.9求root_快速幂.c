#include<stdio.h>
long long quickpow(long long x,long long y,int k) // 快速幂
{
    long long res = 1;
    while(y)
    {
        if(y%2)
            res = res *x % (k-1);
        x = x*x %(k-1);
        y /=2;
    }
    return res;
}
 
void root(long long x,long long y,int k)
{
    long long res;
    res = quickpow(x,y,k);
    printf("%d",res?res:k-1);
}
int main()
{
    long long x,y;
    int k;
    scanf("%lld%lld%d",&x,&y,&k);
    root(x,y,k);
    return 0;
}