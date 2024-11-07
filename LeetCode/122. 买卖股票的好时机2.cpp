/**
 * @file 122. 买卖股票的好时机2.cpp
 * @author han yi (brokensnow2@gmail.com)
 * @brief
 * 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
 * 在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
 * 返回 你能获得的 最大 利润 。
 * 示例 1：
    输入：prices = [7,1,5,3,6,4]
    输出：7
    解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4。
    随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3。
    最大总利润为 4 + 3 = 7 。


 * 解题思路: DP 或者 贪心
 * @details 
 * @version 0.1
 * @date 2024-11-07
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <vector>
#include <iostream>
using namespace std;
#include <vector>
#include <iostream>
using namespace std;

// 动态规划解法
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size(); // 获取价格数组的长度
        vector<vector<int>> dp(n, vector<int>(2, 0)); // 创建二维数组 dp，dp[i][0] 表示持有股票的最大利润，dp[i][1] 表示不持有股票的最大利润
        dp[0][0] = -prices[0]; // 第一天持有股票的利润，等于买入的负价格
        dp[0][1] = 0; // 第一天不持有股票的利润为 0
        for (int i = 1; i < n; i++) // 从第二天开始遍历
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]); // 更新当天持有股票的最大利润
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]); // 更新当天不持有股票的最大利润
        }
        return dp[n - 1][1]; // 返回最后一天不持有股票的最大利润
    }
};

// 贪心算法解法
class Solution2
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0; // 初始化最大利润为 0
        int length = prices.size(); // 获取价格数组的长度
        for (int i = 0; i < length - 1; i++) // 遍历价格数组
        {
            if (prices[i] < prices[i + 1]) // 如果当天价格低于次日价格
            {
                profit += prices[i + 1] - prices[i]; // 将当天和次日价格差累加到利润
            }
        }
        return profit; // 返回最终计算的最大利润
    }
};
