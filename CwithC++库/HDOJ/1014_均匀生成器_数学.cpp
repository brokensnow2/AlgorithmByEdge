/**
 * @file 1014_均匀生成器_数学.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-08-01
 * 
 * @copyright Copyright (c) 2024
 * 
 * Problem Description
Computer simulations often require random numbers. One way to generate pseudo-random numbers is via a function of the form

seed(x+1) = [seed(x) + STEP] % MOD

where '%' is the modulus operator.

Such a function will generate pseudo-random numbers (seed) between 0 and MOD-1. One problem with functions of this form is that they will always generate the same pattern over and over. In order to minimize this effect, selecting the STEP and MOD values carefully can result in a uniform distribution of all values between (and including) 0 and MOD-1.

For example, if STEP = 3 and MOD = 5, the function will generate the series of pseudo-random numbers 0, 3, 1, 4, 2 in a repeating cycle. In this example, all of the numbers between and including 0 and MOD-1 will be generated every MOD iterations of the function. Note that by the nature of the function to generate the same seed(x+1) every time seed(x) occurs means that if a function will generate all the numbers between 0 and MOD-1, it will generate pseudo-random numbers uniformly with every MOD iterations.

If STEP = 15 and MOD = 20, the function generates the series 0, 15, 10, 5 (or any other repeating series if the initial seed is other than 0). This is a poor selection of STEP and MOD because no initial seed will generate all of the numbers from 0 and MOD-1.

Your program will determine if choices of STEP and MOD will generate a uniform distribution of pseudo-random numbers.
 

Input
Each line of input will contain a pair of integers for STEP and MOD in that order (1 <= STEP, MOD <= 100000).
 

Output
For each line of input, your program should print the STEP value right- justified in columns 1 through 10, the MOD value right-justified in columns 11 through 20 and either "Good Choice" or "Bad Choice" left-justified starting in column 25. The "Good Choice" message should be printed when the selection of STEP and MOD will generate all the numbers between and including 0 and MOD-1 when MOD numbers are generated. Otherwise, your program should print the message "Bad Choice". After each output test set, your program should print exactly one blank line.
 

Sample Input
3 5
15 20
63923 99999
 

Sample Output
         3         5    Good Choice

        15        20    Bad Choice

     63923     99999    Good Choice
 */

/*
解法：
线性同余方程是数论中的一个重要概念，特别是在生成伪随机数时。一个典型的线性同余方程形式如下：
Xn+1 = (a*Xn+c) % m 或者 seed(x+1) = (a⋅seed(x)+c) % m


其中：
- `a` 是乘数
- `c` 是增量
- `m` 是模数
- `seed(x)` 是当前的种子值
- `seed(x+1)` 是下一个种子值

在我们的问题中，特定的形式如下：
seed(x+1) = [seed(x) + STEP] % MOD

其中：
- `STEP` 是增量（相当于 `c`）
- `MOD` 是模数（相当于 `m`）

为了确保生成的伪随机数能够遍历所有可能的值（即从 `0` 到 `MOD-1`），有几个必要的条件，主要是与互质性相关的条件：

### 互质性条件

对于线性同余方程：

要确保该序列遍历所有可能的值（即从 `0` 到 `MOD-1`），必须满足以下条件：
- `STEP` 和 `MOD` 互质，即 `gcd(STEP, MOD) = 1`。
### 为什么互质性重要

当 `STEP` 和 `MOD` 互质时，表示 `STEP` 和 `MOD` 没有除了 `1` 以外的公约数。这确保了生成的序列能够遍历整个模数空间。这是因为：
- 如果 `STEP` 和 `MOD` 互质，根据数论中的一个重要结果，线性同余方程生成的序列的周期性等于 `MOD`，这意味着序列会遍历所有的 `0` 到 `MOD-1`。

### 总结

- 线性同余方程是生成伪随机数的一种常用方法。
- 通过检查 `STEP` 和 `MOD` 的最大公约数是否为 1，可以判断生成的序列是否能够覆盖整个模数空间。
- `gcd(STEP, MOD) = 1` 是确保序列遍历所有 `0` 到 `MOD-1` 值的必要条件。
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

// 函数来计算两个数的最大公约数
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int step, mod;
    vector<pair<int, int>> inputs;

    // 读取输入，直到EOF
    while (cin >> step >> mod) {
        inputs.push_back({step, mod});
    }

    // 处理每一对输入
    for (const auto& input : inputs) {
        step = input.first;
        mod = input.second;
        
        // 判断是否为Good Choice
        bool goodChoice = (gcd(step, mod) == 1);
        
        // 输出结果
        cout << setw(10) << step << setw(10) << mod << "    ";
        if (goodChoice) {
            cout << "Good Choice" << endl;
        } else {
            cout << "Bad Choice" << endl;
        }
        cout << endl;
    }

    return 0;
}
