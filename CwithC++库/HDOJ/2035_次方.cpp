#include <iostream> // 引入输入输出流库
#include <cmath>    // 引入数学库，用于计算幂

int main() { // 主函数
    while (true) { // 无限循环
        int n, m; // 定义两个整数变量n和m
        std::cin >> n >> m; // 从标准输入读取n和m的值

        if (n == 0 && m == 0) { // 如果n和m都为0
            break; // 跳出循环
        } else { // 否则
            long long ans = pow(n, m); // 计算n的m次方，结果存储在ans中
            std::cout << ans % 1000 << std::endl; // 输出ans的最后三位
        }
    }
    return 0; // 程序正常结束
}
