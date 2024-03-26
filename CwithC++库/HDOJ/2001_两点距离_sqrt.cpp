#include <cmath>
#include <cstdio>
#include <iostream> // 引入C++标准输入输出库：cin，cout，getline
#include <iomanip>

using namespace std;

int main()
{
    // 定义两点坐标
    double x[2],y[2]; // x[2]: x[0]:x的横坐标，x[1]:x的纵坐标
	while(scanf("%lf %lf %lf %lf",&x[0],&x[1],&y[0],&y[1]) != EOF)
    {
        double ans = (y[1]-x[1])*(y[1]-x[1]) + (y[0]-x[0])*(y[0]-x[0]);
        cout << fixed << setprecision(2) << sqrt(ans) << endl;
    }

}

/**
如果你不能使用sqrt函数，或者你想自己实现一个求平方根的函数，有几种常见的方法：

二分查找法：首先确定一个范围，然后每次取范围的中间值，
看这个中间值的平方与目标值的大小关系，然后根据比较结果调整范围，
直到找到满足精度要求的平方根。

double sqrt_binarysearch(int x) {

    double low = 0, high = x, mid;
    while (high - low > 1e-6) {
        mid = low + (high - low) / 2;
        if (mid * mid > x) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return low;
}

牛顿迭代法：这是一种更快的方法，它的基本思想是用一个初始值开始，
然后不断地用这个值和目标值除以这个值的平均值来更新这个值，直到满足精度要求。
double sqrt_newton(int x) {
    double res = x;
    while (fabs(res * res - x) > 1e-6) {
        //核心：这个值  目标值除以这个值  平均值
        res = (res  + x / res)      / 2;
    }
    return res;
}

神奇的算法：这是一个出自《雷神之锤3》的游戏引擎的算法，它使用了一些神奇的位操作和魔法数字来快速计算平方根的倒数。
float InvSqrt(float x) {
    float xhalf = 0.5f * x;
    int i = *(int*)&x;
    i = 0x5f375a86 - (i >> 1);
    x = *(float*)&i;
    x = x * (1.5f - xhalf * x * x);
    return 1 / x;
}

*/