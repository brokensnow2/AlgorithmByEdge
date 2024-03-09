/**
 * 解法：DP
 * dp2[n] : 第n个格子和第一个格子不同的所有情况 dp2[1] = 0
 * dp1[n] : 第n个格子和第一个格子相同的所有情况; dp1[1] = 3
 * 而第n个格子和第一个格子相同的所有情况就是第n-1个格子和第一个格子不同的情况
 * 即dp1[n] = dp2[n-1]; dp1[2] = dp2[1] = 0
 * 
 * 又因为dp2[n] = 2*dp1[n-1] + dp2[n-1]
 * 
 * 
*/
#include<iostream>

using namespace std;

int main(){

    int n;
    while(cin >> n){
        long long dp1 = 3, dp2 = 0; // 初始化
        for(int i = 2; i <= n; i++){
            long long temp = dp1;
            dp1 = dp2; // 第i个格子和第1个格子颜色相同
            dp2 = 2*temp + dp2; // 第i个格子和第1个格子颜色不同
        }
        if (n != 1)
        	cout << dp2 << endl; // 输出结果
        else
        	cout << dp1 << endl;
    }
    return 0;
}

