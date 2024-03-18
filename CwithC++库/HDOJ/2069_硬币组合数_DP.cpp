#include <iostream>
#include <cstring>
using namespace std;
/**
 * dp[n] : n块钱的组合数
 * dp[n] = n-1块钱+1块钱的硬币,即dp[n-1]; 
 * 和n-5块钱+5块钱的硬币,即dp[n-5];...
 * 所以dp[n] = dp[n-1] + dp[n-5] + dp[n-10] + ...
*/
int main() {
    int coins[5] = {1, 5, 10, 25, 50}; // 硬币的面值
    long long dp[300]; // dp[i] 表示总金额为 i 时的组合数
    memset(dp, 0, sizeof(dp)); // 初始化 dp 数组
    dp[0] = 1; // 金额为 0 时只有一种组合

    for(int i = 0; i < 5; ++i) { // 对于每一种硬币
        for(int j = coins[i]; j <= 250; ++j) { // 更新 dp 数组
            dp[j] += dp[j - coins[i]];
        }
    }

    int n;
    while(cin >> n) { // 读取输入
        cout << dp[n] << endl; // 输出结果
    }

    return 0;
}
