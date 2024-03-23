// 递归会超时，因为有大量重复计算
// 使用DP。3 -> 6 其实等同于 1 -> 4
// 所以我们可以把他们全部平移到从1开始，
// 创建一个DP数组来存储
// 所以使用递归型DP
#include <iostream>
#include <vector>

using namespace std;

int getStep(int b, vector<int> &dp)
{
    if (dp[b] != -1)
    {
        return dp[b];
    }
    else
        return dp[b] = getStep(b-1, dp) + getStep(b-2, dp); // 更新 dp 数组并返回结果
}

int main()
{
    int n, a, b;
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        // -1 表示没有填充
        // dp[n] 表示从 1 到 n 的路径数；
        // 规定 dp[1]、dp[2] 为 0。
        // dp[n] = dp[n-1] + dp[n-2]
        if (a < b)
        {
			cout << 0 << endl;
            break;
        }
        vector<int> dp(b-a+2, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        cout << getStep(b-a+1, dp) << endl;
    }
    return 0;
}



/**
 * 超时了
#include <iostream>

using namespace std;

int getStep(int a, int b)
{
    if (b < a)
    	return 0;
    else if (b == a+1)
    	return 1;
    else if (b == a+2)
    	return 2;
    else
    	return getStep(a, b-1) + getStep(a, b-2);
}

int main()
{
    int n,a,b;
    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        cout << getStep(a,b) << endl;
    }
}
 * 
 * 
*/