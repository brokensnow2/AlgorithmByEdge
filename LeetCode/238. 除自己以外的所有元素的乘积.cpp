/**
 * @file 238. 除自己以外的所有元素的乘积.cpp
 * @author han yi (brokensnow2@gmail.com)
 * @brief
 * 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
 * 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
 * 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
 * 
 * 解题思路: 前缀积和后缀积
 * 时间复杂度 O(n), 空间复杂度 O(n)
 * @version 0.1
 * @date 2024-11-08
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, 1); // 初始化结果数组，每个元素初始为 1

        // 左边累乘：res[i] 存储 nums[i] 左边所有元素的乘积
        for (int i = 1; i < n; i++)
        {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int right = 1; // 用于存储右边所有元素的乘积
        // 右边累乘：将右边的乘积逐步累乘到 res 中
        for (int i = n - 1; i >= 0; i--)
        {
            res[i] *= right;  // 当前元素乘以右边的乘积
            right *= nums[i]; // 更新右边的乘积
        }

        return res;
    }
};
