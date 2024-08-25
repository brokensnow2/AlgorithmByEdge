/*
问题描述
还有另一种斐波那契数列：F（0） = 7， F（1） = 11， F（n） = F（n-1） + F（n-2） （n>=2）。
输入由一系列行组成，每行包含一个整数 n. （n < 1,000,000）

输出：
如果F（n）可以被3整除，则打印单词 “yes”；如果不是，请打印单词 “no”。

*/
#include <iostream>
using namespace std;

int main() {
    // 初始化斐波那契数列的起始值
    int F0 = 7 % 3; // 只保留余数，避免溢出
    int F1 = 11 % 3;
    
    // 用于存储用户输入的n
    int n;
    
    // 读取输入直到文件末尾
    while (cin >> n) {
        // 对于 n = 0 和 n = 1 的情况，直接输出结果
        if (n == 0) {
            cout << (F0 == 0 ? "yes" : "no") << endl;
        } else if (n == 1) {
            cout << (F1 == 0 ? "yes" : "no") << endl;
        } else {
            // 从 F2 开始计算斐波那契数列的模3值
            int Fn_minus_2 = F0;
            int Fn_minus_1 = F1;
            int Fn;
            
            // 计算第 n 个斐波那契数的模3值
            for (int i = 2; i <= n; ++i) {
                Fn = (Fn_minus_1 + Fn_minus_2) % 3;
                
                // 更新前两个数的值
                Fn_minus_2 = Fn_minus_1;
                Fn_minus_1 = Fn;
            }
            
            // 输出结果
            cout << (Fn == 0 ? "yes" : "no") << endl;
        }
    }
    
    return 0;
}
