/**
 * 从左往右三根杠，依次命名为A，B，C。
 * 想要把n个圆盘从A移到C，我们需要：
 * 把n-1个圆盘从A->B->C;
 * 把n号圆盘从A->B;
 * 把C上的n-1个圆盘从C->B->A;
 * 把B上的n号圆盘移到C。
 * 
 * 再把A上n-1个圆盘重复上面操作.
 * 
 * 这题求移动次数，所以规定F(n)为把n个圆盘从A移到C的移动次数
 * 所以：把n-1个圆盘从A->B->C ：F(n-1)
 * 		把n号圆盘从A->B : 1
 * 		把C上的n-1个圆盘从C->B->A ：F(n-1)
 * 		把B上的n号圆盘移到C : 1
 * 		再把A上n-1个圆盘重复上面操作: F(n-1)
 * 
 * 边界条件：F(1) = 2
*/

#include <iostream>
#include <cstdio>

using namespace std;

long long move(int n)
{
    if (n == 1)
    {
        return 2;
    }
    return 3 * move(n - 1) + 2;
}

int main()
{
	int n;
    while(cin >> n)
    {
        printf("%lld\n", move(n));
    }
    return 0;
}