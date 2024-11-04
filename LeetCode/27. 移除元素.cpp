/**
 * @file 27. 移除元素.cpp
 * @author hanyi (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-11-04
 * 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。
 * 假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：
 * 更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
 * 返回 k。
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
     * @brief 原地移除数组中等于指定值的所有元素，并返回新数组的长度。
     *
     * 该函数通过遍历输入的 `nums` 数组，将不等于 `val` 的元素移动到数组的前部。
     * 元素的顺序可能会发生变化。移除后的数组长度返回为 `k`。
     *
     * @param nums 引用整数向量 `nums`，从中移除值为 `val` 的元素。
     * @param val 要移除的整数值 `val`。
     * @return 移除 `val` 后数组中剩余的元素数量。
     */
    int removeElement(vector<int> &nums, int val)
    {
        int k = 0;  // 记录新数组的长度
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[k] = nums[i]; // 将不等于 val 的元素移到数组前部
                k++;
            }
        }
        return k;
    }
};
