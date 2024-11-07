/**
 * @file 55. 跳跃游戏.cpp
 * @author han yi (brokensnow2@gmail.com)
 * @brief 
 * 给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。
 * 示例 1：
    输入：nums = [2,3,1,1,4]
    输出：true
    解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。

 * 解题思路1：除非到了值为0的下标，否则就能一直往前走，可以从下标0开始DFS： 
    选取能跳跃到的最远的下标，判断到最后一跳能有多远和数组的下标做比较，如果大于数组的下标，则返回true，否则返回上一个节点选择其他节点
    时间复杂度为O(n*n),空间复杂度是调用栈的长度，O(n)
 * 思路2：见代码，相当于一步步后退
 * 时间复杂度：O(n), 空间复杂度：O(1)
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
    bool canJump(vector<int> &nums)
    {
        int target = nums.size() - 1; // 初始目标设为最后一个下标，表示我们想要到达的位置
        for (int i = target - 1; i >= 0; i--)   // 从倒数第二个下标开始往前遍历
        {
            if (i + nums[i] >= target) // 如果当前下标 i 加上能跳跃的最大步数 >= 目标位置
            {
                target = i; // 更新目标位置为当前下标，表示从该位置可以到达之前的目标
            }
        }
        return target == 0; // 如果最终目标位置更新到 0，说明可以从第一个下标跳到最后一个下标
    }
};
