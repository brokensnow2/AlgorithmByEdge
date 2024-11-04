/**
 * @file 80. 删除重复元素2.cpp
 * @author hanyi (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-11-04
 *
 * 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。
 * 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
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
        int k = 0, count = 0;                // k 代表新数组的长度
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != last)
            {                      // 如果当前元素和上一个元素不同
                nums[k] = nums[i]; // 将该元素移到位置 k
                last = nums[i];    // 更新 last
                count = 1;
                k++;               // 新数组长度 +1
            }
            else if (count < 2)
            {
                count++;
                nums[k] = nums[i];
                k++;
            }
        }
        return k; // 返回去重后的数组长度
    }
};
