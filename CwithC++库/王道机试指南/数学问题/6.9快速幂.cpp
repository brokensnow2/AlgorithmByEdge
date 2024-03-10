#include <iostream>  // 引入输入输出流库
#include <cmath>     // 引入数学库，用于计算平方根

using namespace std;  // 使用标准命名空间

// 计算 x 的 y 次方，快速幂
long long power(long long x, long long y) {
    long long result = 1;
    while (y > 0) {
        if (y & 1) { // 如果指数的二进制的那位为1，则乘以次幂
            result *= x;
        }
        y >>= 1; // 右移 等同于除2
        x *= x; // 不断平方 ；指数乘以2相当于底不断平方，有可能超出范围
    }
    return result;
}

// 计算 n 的 k 进制表示的各位数字之和
long long digit_sum(long long n, long long k) {
    long long sum = 0;
    while (n > 0) {
        sum += n % k;
        n /= k;
    }
    return sum;
}

// 计算 root(n, k)
long long root(long long n, long long k) {
    if (n < k) {
        return n;
    } else {
        return root(digit_sum(n, k), k);
    }
}

// 主函数
int main() {
    long long x, y, k;
    cin >> x >> y >> k;  // 读取输入
    cout << root(power(x, y), k);  // 计算并输出结果
    return 0;
}
