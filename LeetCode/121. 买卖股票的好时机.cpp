/**
 * @file 121. 买卖股票的好时机.cpp
 * @author han yi (brokensnow2@gmail.com)
 * @brief 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
 * 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
 * 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
 * 示例 1：
    输入：[7,1,5,3,6,4]
    输出：5
    解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
        注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
 *示例 2：
    输入：prices = [7,6,4,3,1]
    输出：0
    解释：在这种情况下, 没有交易完成, 所以最大利润为 0。

 * 解题思路：两层for循环
 * 时间复杂度：O(n^2), 空间复杂度：O(1) --超时
 * 
 * 思路2：
 * 
 * @version 0.1
 * @date 2024-11-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int minPrice = INT_MAX; // 初始化为无穷大，表示最低买入价格
        int maxProfit = 0;      // 初始化最大利润

        for (int price : prices) {
            minPrice = min(minPrice, price);       // 更新最低价格
            maxProfit = max(maxProfit, price - minPrice); // 计算当前利润并更新最大利润
        }

        return maxProfit;
    }
};

/*
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0; // 最大利润
        int length = prices.size(); // 数组长度
        for (int i = 0; i < length; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                res = max(res, prices[j] - prices[i]);
            }
        }
        return res;
    }
};
*/