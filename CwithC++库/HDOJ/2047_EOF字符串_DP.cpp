#include <iostream>
#include <vector>
/**
 * 这是一个动态规划问题。我们可以定义一个二维的 DP 数组，
 * 其中 dp[i][j] 表示长度为 i 的字符串中，最后一个字符为 j 的字符串的数量。这里 j 可以是 'E'、'O' 或 'F'。
 * 由于 'O' 不能连续出现，所以当最后一个字符为 'O' 时，倒数第二个字符只能是 'E' 或 'F'。因此，我们可以得到以下的状态转移方程：
 * dp[i]['E'] = dp[i-1]['E'] + dp[i-1]['O'] + dp[i-1]['F']
 * dp[i]['O'] = dp[i-1]['E'] + dp[i-1]['F']
 * dp[i]['F'] = dp[i-1]['E'] + dp[i-1]['O'] + dp[i-1]['F']
 * 初始条件为 dp[1]['E'] = dp[1]['O'] = dp[1]['F'] = 1。
 * 
 * dp Matrix:
 * 
 * 	  E  O  F
 * 1  1  1  1
 * 2  3  2  3
 * 3
*/
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<vector<long long>> dp(n+1, vector<long long>(3));
        //    E          O          F
        dp[1][0] = dp[1][1] = dp[1][2] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i][0] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
            dp[i][1] = dp[i-1][0] + dp[i-1][2];
            dp[i][2] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
        }
        cout << dp[n][0] + dp[n][1] + dp[n][2] << endl;
    }
    return 0;
}
