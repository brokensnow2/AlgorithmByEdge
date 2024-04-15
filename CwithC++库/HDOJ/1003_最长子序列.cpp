/**
 * way1:遍历求和法
 * 思路：边遍历边累加,sum+=a[i],更新最大的sum值，
 * 当sum的值小于0 ，sum+a[i+1]<=a[i+1],则没有必要再曾长该子序列则重新开始新的子序列
 * 
 * way2:dp动态规划（强推）
 * 状态转移方程dp[i]=max(dp[i-1]+a[i],a[i]),和遍历求和思想相同
*/
#include <iostream>

using namespace std;

int main()
{
    int count, n;
    cin >> count;
    for (int i = 1; i <= count; i++)
    {
        int a, start, end, j;
        int sum = 0, temp = 1, max = -99999;
        cin >> n;
        for (j = 1; j <= n; j++)
        {
            cin >> a;
            sum += a;
            if (sum > max)
            {
                start = temp;
                end = j;
                max = sum;
            }
            if (sum < 0)
            {
                sum = 0;
                temp = j + 1;
            }
        }
        cout << "Case " << i << ":" << endl;
        cout << max << " " << start << " " << end << endl;
        if (i != count)
        {
            cout << endl;
        }
        
    }
    
}