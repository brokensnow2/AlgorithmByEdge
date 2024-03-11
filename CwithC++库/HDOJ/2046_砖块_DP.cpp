#include <iostream>
#include <vector>

/**
 * 这是一个经典的动态规划问题，也被称为骨牌覆盖问题。
 * 我们可以定义一个一维的 DP 数组，
 * 其中 dp[i] 表示 2×i 的长方形方格的铺放方案总数。
 * 由于骨牌的大小是 1×2，所以对于 2×i 的长方形方格，我们有两种铺放方式：
 * 在 2×(i-1) 的长方形方格的基础上，横向放置一个骨牌，
 * 此时的方案总数为 dp[i-1]；
 * 
 * 在 2×(i-2) 的长方形方格的基础上，纵向放置两个骨牌，
 * 此时的方案总数为 dp[i-2]。
 * 
 * 因此，我们可以得到以下的状态转移方程：
 * dp[i] = dp[i-1] + dp[i-2]
 * 初始条件为 dp[1] = 1，dp[2] = 2。
 * 
 * 
*/
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<long long> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        cout << dp[n] << endl;
    }
    return 0;
}
