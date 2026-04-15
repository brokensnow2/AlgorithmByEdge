/**
题目描述
设有 N×N 的方格图 (N≤9)，我们将其中的某些方格中填入正整数，而其他的方格中则放入数字 0。

某人从图的左上角的 A 点出发，可以向下行走，也可以向右走，直到到达右下角的 B 点。
在走过的路上，他可以取走方格中的数（取走后的方格中将变为数字 0）。
此人从 A 点到 B 点共走两次，试找出 2 条这样的路径，使得取得的数之和为最大。

输入格式
输入的第一行为一个整数 N（表示 N×N 的方格图），接下来的每行有三个整数，
前两个表示位置，第三个数为该位置上所放的数。一行单独的 0 表示输入结束。

输出格式
只需输出一个整数，表示 2 条路径上取得的最大的和。

输入输出样例
输入
8
2 3 13
2 6  6
3 5  7
4 4 14
5 2 21
5 6  4
6 3 15
7 2 14
0 0  0
输出
67

说明/提示
数据范围：1≤N≤9，方格中的数不超过 30。

*/
#include <bits/stdc++.h>
using namespace std;

int grid[10][10];
int dp[20][10][10];

int main() {
    int N;
    cin >> N;

    // 初始化
    memset(grid, 0, sizeof(grid));

    while (true) {
        int x, y, v;
        cin >> x >> y >> v;
        if (x == 0 && y == 0 && v == 0) break;
        grid[x-1][y-1] = v;
    }

    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = grid[0][0];

    for (int k = 1; k <= 2*N-2; k++) {
        for (int i1 = 0; i1 < N; i1++) {
            for (int i2 = 0; i2 < N; i2++) {
                int j1 = k - i1;
                int j2 = k - i2;

                if (j1 < 0 || j1 >= N || j2 < 0 || j2 >= N)
                    continue;

                int best = -1;

                for (int di1 = 0; di1 <= 1; di1++) {
                    for (int di2 = 0; di2 <= 1; di2++) {
                        int pi1 = i1 - di1;
                        int pi2 = i2 - di2;
                        int pj1 = j1 - (1 - di1);
                        int pj2 = j2 - (1 - di2);

                        if (pi1 < 0 || pi2 < 0 || pj1 < 0 || pj2 < 0)
                            continue;

                        if (dp[k-1][pi1][pi2] == -1)
                            continue;

                        best = max(best, dp[k-1][pi1][pi2]);
                    }
                }

                if (best == -1) continue;

                int val = grid[i1][j1];
                if (i1 != i2) val += grid[i2][j2];

                dp[k][i1][i2] = best + val;
            }
        }
    }

    cout << dp[2*N-2][N-1][N-1] << endl;
    return 0;
}