extern "C" {
#include <stdio.h> // 引入标准输入输出库
#include <string.h> // 引入字符串处理库
}

#include <algorithm> // 引入C++的算法库
#include <vector> // 引入C++的向量库
#include <iostream>
using namespace std; // 使用标准命名空间

int Reverse(int a)
{
	int rev  = 0;
    while(a != 0)
    {
        rev *= 10;
        rev += a % 10;
        a /= 10;
    }
    return rev;
}

int main()
{
    int a;
    scanf("%d",&a);
    printf("%d\n",Reverse(a));
}