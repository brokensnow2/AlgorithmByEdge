#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目中说，每头母牛从第四个年头开始，每年年初都会生一头小母牛。
 * 也就是说，今年新出生的小母牛，是三年前刚开始能生小母牛的母牛所生的。

所以，今年的母牛数量，就等于去年的母牛数量（因为母牛都没有死）
加上今年新出生的小母牛数量。而今年新出生的小母牛数量，就是三年前的母牛数量。

因此，我们可以得到这样一个公式：
今年的母牛数量 = 去年的母牛数量 + 三年前的母牛数量。
1 2 3 4 6 9 13 19 28 41 60 88
 * 
 * 
*/
int main() {
    vector<int> dp(56);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    for (int i = 5; i <= 55; ++i) {
        dp[i] = dp[i - 1] + dp[i - 3];  // 当前的牛的数量等于上一年的牛的数量加上三年前的牛的数量
    }

    int n;
    while (cin >> n && n) {
        cout << dp[n] << endl;
    }

    return 0;
}
