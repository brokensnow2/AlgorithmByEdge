extern "C" {
#include <stdio.h> // 引入标准输入输出库
#include <string.h> // 引入字符串处理库
}
#include <iostream> //Cpp的标准输入输出库
#include <algorithm> // 引入C++的算法库
#include <vector> // 引入C++的向量库

using namespace std; // 使用标准命名空间

/**
* @Brief: 判断数有没有7
* 
* @Return ：bool
*/
bool isHave7(int n)
{
    while (n != 0)
    {
        if (n%10 == 7) // 最低位有7
        	return true;
        else
        	n /= 10; // 去掉最低位
    }
    return false;
}

int main()
{
    int sum = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i%7 == 0 || isHave7(i))
        	sum += i*i;
    }
    cout << sum;
}