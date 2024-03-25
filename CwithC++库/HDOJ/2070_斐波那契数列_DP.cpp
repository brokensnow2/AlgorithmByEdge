#include <iostream>

using namespace std;

int main() {
    __int64_t fib[51]; // 存储斐波那契数列的值 PS:编译器不同 提交时用__int64
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= 50; ++i) {
        fib[i] = fib[i-1] + fib[i-2]; // 计算斐波那契数列的值
    }

    int n;
    while(cin >> n ) { // 读取输入
    	if (n == -1)
        {
            break;
        }
        cout << fib[n] << endl; // 输出结果
    }

    return 0;
}
