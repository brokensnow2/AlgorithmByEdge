/**
 * @file 135. 分发糖果.cpp
 * @author han yi (brokensnow2@gmail.com)
 * @brief
 *
 * n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
 * 你需要按照以下要求，给这些孩子分发糖果：
    每个孩子至少分配到 1 个糖果。
    相邻两个孩子评分更高的孩子会获得更多的糖果。
    请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。

 * 解题思路：有些类似于238.
 解题步骤：
 通过升序和降序的子序列来分配糖果，确保每个孩子的糖果分配满足条件
 原始思路：
 无非4种情况:全升， 全降， 升降升降...， 降升降升...
    //Q: 1 4 3 2 5 7 4 5
    //A: 1 2
    //   1 2 1
    //   1 3 2 1 
    //   1 3 2 1 2 3
    //   1 3 2 1 2 3 1 2

    // 4 3 2连续降序 --相当于从右到左升序
    // 遇到升序比前面加一
    // 1 4，2 5 7，4 5 升序
    // 4 3 2，7 4，降序
    // 总结为 升2，降3，升3，降2，升2
    // 1 3 2 1 2 3 1 2

    //Q: 3 2 1 4 5 2 1 3
    //A: 3 2 1
    //   3 2 1 2
    //   3 2 1 2 3 2 1 2

    // 总结为 降3，升3，降3，升2
    // 3 2 1 2 3 2 1 2
 从左到右扫描：初始化每个孩子至少分配 1 个糖果。
 然后，从左到右遍历数组，如果当前孩子的评分高于前一个孩子，那么将当前孩子的糖果数设为 前一个孩子的糖果数 + 1。
 这样处理完，能够保证从左至右方向的要求。
 从右到左扫描：再从右到左遍历，如果当前孩子的评分高于后一个孩子，则当前孩子的糖果数应为 后一个孩子的糖果数 + 1。
 此步骤可以确保满足从右到左的相邻评分关系。
 最终计算总和：在这两次遍历后，每个孩子的糖果数将满足要求。将每个孩子的糖果数加起来，即为最少糖果总数。
 * @version 0.1
 * @date 2024-11-09
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> candies(n, 1); // 每个孩子初始分配 1 个糖果

        // 从左到右遍历，如果右边孩子评分更高，糖果数就加 1
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // 从右到左遍历，如果左边孩子评分更高，调整左边孩子的糖果数
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // 求糖果总数
        int totalCandies = 0;
        for (int candy : candies)
        {
            totalCandies += candy;
        }
        return totalCandies;
    }
};
