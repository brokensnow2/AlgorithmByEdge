/**
 * @file 45. 跳跃游戏2.cpp
 * @author han yi (brokensnow2@gmail.com)
 * @brief
 * 给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
 * 每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
 * 0 <= j <= nums[i]
 * i + j < n
 * 返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。
示例 1:
    输入: nums = [2,3,1,1,4]
    输出: 2
    解释: 跳到最后一个位置的最小跳跃数是 2。
        从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 * 解题思路: 见代码
 * @version 0.1
 * @date 2024-11-07
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    /**
     * @brief DP, 时间复杂度 O(n^2), 空间复杂度 O(n)
     *
     * @param nums
     * @return int
     */
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, INT_MAX); // 初始化 dp 数组为最大值
        dp[0] = 0;                  // 起点不需要跳跃

        for (int i = 1; i < n; i++)
        { // 遍历每个位置
            for (int j = 0; j < i; j++)
            { // 检查位置 j 是否可以跳到 i
                if (j + nums[j] >= i)
                {                                  // 若能跳到位置 i
                    dp[i] = min(dp[i], dp[j] + 1); // 更新最小跳跃次数
                }
            }
        }
        return dp[n - 1];
    }
};

//==========================================================================
//==========================================================================
#include <queue>
class Soultion2
{
public:
    /**
     * @brief BFS
     *
     * @param nums
     * @return int
     */
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return 0; // 起点就是终点，不需要跳跃

        queue<int> q;
        q.push(0);     // 从位置 0 开始
        int jumps = 0; // 跳跃次数

        while (!q.empty())
        {
            int levelSize = q.size(); // 当前层的节点数
            jumps++;                  // 每次处理一层就增加一次跳跃次数

            // 遍历当前层的每个位置
            for (int i = 0; i < levelSize; i++)
            {
                int index = q.front();
                q.pop();

                // 从当前下标 index 能跳到的最远范围
                int furthest = index + nums[index];
                for (int j = index + 1; j <= furthest && j < n; j++)
                {
                    if (j == n - 1)
                        return jumps; // 到达最后一个位置

                    q.push(j); // 将下一个可以跳到的节点加入队列
                }
            }
        }

        return -1; // 理论上不会到这里，因为题目保证能够到达终点
    }
};

//==========================================================================
//==========================================================================

class Soultion3
{
public:
    /**
     * @brief 贪心, 时间复杂度 O(n), 空间复杂度 O(1)
     *
     * @param nums
     * @return int
     */
    int jump(vector<int> &nums)
    {
        int jumps = 0;    // 记录跳跃次数
        int farthest = 0; // 当前跳跃可达的最远位置
        int end = 0;      // 当前跳跃范围的终点

        for (int i = 0; i < nums.size() - 1; i++)
        {                                          // 遍历数组，但不包含最后一个元素
            farthest = max(farthest, i + nums[i]); // 更新当前跳跃的最远位置

            if (i == end)
            {                   // 到达当前跳跃范围的终点
                jumps++;        // 增加跳跃次数
                end = farthest; // 更新新的跳跃范围的终点
            }
        }
        return jumps;
    }
};