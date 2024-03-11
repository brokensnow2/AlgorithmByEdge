#include <iostream>
#include <iomanip>
#include <vector>

/**
 * 对于 n 个人，他们的名字有 n! 种排列方式，
 * 其中每个人都不抽到自己的名字的排列方式数量是 D(n)，
 * 这是一个著名的数列，被称为错排数列。
 * 错排数列的递推公式是 D(n) = (n-1) * [D(n-1) + D(n-2)]，
 * 初始条件是 D(1) = 0，D(2) = 1。
 * 因此，n 个人都不中奖的概率就是 D(n) / n!。
 * 
 * 
*/
using namespace std;

int main() {
    int C; // 测试实例的个数
    cin >> C;
    vector<float> factorial(21, 1), derangement(21); // 初始化阶乘数列和错排数列
    derangement[1] = 0; // 错排数列的初始条件
    derangement[2] = 1; // 错排数列的初始条件
    factorial[2] = 2;
    for (int i = 3; i <= 20; ++i) { // 计算阶乘数列和错排数列
        factorial[i] = i * factorial[i-1]; // 阶乘数列的递推公式
        derangement[i] = (i-1) * (derangement[i-1] + derangement[i-2]); // 错排数列的递推公式
    }
    while (C--) { // 对每个测试实例进行处理
        int n; // 参加抽奖的人数
        cin >> n;
        float probability = (float)derangement[n] / (float)factorial[n]; // 计算所有人都不中奖的概率
        cout << fixed << setprecision(2) << probability * 100 << "%" << endl;// 输出结果，保留两位小数
    }
    return 0;
}
