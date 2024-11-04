/**
 * @file 26. 移除重复元素.cpp
 * @author hanyi (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-11-04
 *
 * 给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
 * 考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：
 * 更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
 * 返回 k 。
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int last = __INT32_MAX__; // 初始化为最大值
        int k = 0;                // k 代表新数组的长度
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != last)
            {                      // 如果当前元素和上一个元素不同
                nums[k] = nums[i]; // 将该元素移到位置 k
                last = nums[i];    // 更新 last
                k++;               // 新数组长度 +1
            }
        }
        return k; // 返回去重后的数组长度
    }
};
