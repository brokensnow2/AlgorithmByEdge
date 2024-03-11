#include <iostream>
#include <vector>
/**
 * 有M个新郎找错了新娘。
 * 这就相当于在N个新郎中选出M个新郎进行错排，M个新郎进行错排即D(M)个.
 * 而N个新郎中选出M个新郎这是一个组合问题。组合的计算公式为：
 * C(n, m) = n! / [(n-m)! * m!]，
 * 其中 C(n, m) 表示从n个不同的元素中选出m个元素的组合数，
 * n! 表示n的阶乘。
 * 
 * 因此，题目要求的是所有可能的情况数，即 C(N, M) * D(M)。
 * 
 * PS：排列和组合：
 * 排列的数目用符号 A(n, m) 表示：n*(n-1)*(n-2)*...*(n-m+1)
 * 组合的数目用符号 C(n, m) 表示： A(n, m) / m!
*/

using namespace std;

long long factorial(int n) { // 计算阶乘
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

long long derangement(int n) { // 计算错排数
    if (n == 1) return 0;
    if (n == 2) return 1;
    return (n - 1) * (derangement(n - 1) + derangement(n - 2));
}

long long combination(int n, int m) { // 计算组合数
    return factorial(n) / (factorial(m) * factorial(n - m));
}

int main() {
    int C;
    cin >> C;
    while (C--) {
        int N, M;
        cin >> N >> M;
        cout << combination(N, M) * derangement(M) << endl;
    }
    return 0;
}
