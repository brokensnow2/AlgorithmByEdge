/**
 * todo 具体内容见算法基础的动态规划
 * 
*/
#include <iostream>  // 引入输入输出流库
#include <vector>    // 引入向量库，用于创建动态数组
#include <algorithm> // 引入算法库，用于使用max_element函数

using namespace std; // 使用标准命名空间

int main() // 主函数
{
    int n, h, temp; // 定义整型变量n（测试用例数量），h（三角形高度），temp（临时存储输入的数字）
    cin >> n; // 读取测试用例数量
    while (n--) // 对每个测试用例进行操作
    {
		cin >> h; // 读取三角形的高度
        vector<int> dp(h + 1, 0); // 创建一个大小为h+1的动态数组dp，初始值为0，用于存储结果
        vector<int> dp1(h + 1, 0); // 创建一个大小为h+1的动态数组dp1作为副本，初始值为0，用于存储当前行的结果
        for (int i = 1; i <= h; i++) // 对三角形的每一行进行操作
        {
            for (int j = 1; j <= i; j++) // 对当前行的每一个数字进行操作
            {
                cin >> temp; // 读取当前的数字
				dp1[j] = max(dp[j], dp[j-1]) + temp; // 计算到达当前位置的最大和
            }
            dp = dp1; // 将当前行的结果复制给dp，以便在下一行中使用
        }
		int max = *max_element(dp.begin(), dp.end()); // 找到最大和
        cout << max << endl; // 输出最大和       
    }
}
