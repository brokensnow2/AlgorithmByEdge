/**
 * @file 42. 接雨水.cpp
 * @author han yi (brokensnow2@gmail.com)
 * @brief
 *给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 示例 1：
    输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
    输出：6
    解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。

 * 解题思路：
 * 可以在一次遍历中记录每个柱子的左边和右边最大高度，然后在第二次遍历中计算每个位置的储水量。
 * 此方法时间复杂度为 𝑂(𝑛)，空间复杂度为 𝑂(𝑛)（使用两个辅助数组）。
    构建左边最大值数组：从左到右遍历数组，记录每个位置左边最高的柱子高度。
    构建右边最大值数组：从右到左遍历数组，记录每个位置右边最高的柱子高度。
    计算水量：对每个位置 i，能存的水量是 min(left_max[i], right_max[i]) - height[i]。
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
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;

        vector<int> left_max(n), right_max(n);
        left_max[0] = height[0];
        for (int i = 1; i < n; ++i)
        {
            left_max[i] = max(left_max[i - 1], height[i]);
        }

        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        int rainwater = 0;
        for (int i = 0; i < n; ++i)
        {
            rainwater += min(left_max[i], right_max[i]) - height[i];
        }

        return rainwater;
    }
};

/*
思路2：
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> left_max(n), right_max(n);
        left_max[0] = height[0];
        for (int i = 1; i < n; ++i) {
            left_max[i] = max(left_max[i - 1], height[i]);
        }

        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right_max[i] = max(right_max[i + 1], height[i]);
        }

        int rainwater = 0;
        for (int i = 0; i < n; ++i) {
            rainwater += min(left_max[i], right_max[i]) - height[i];
        }

        return rainwater;
    }
};




*/
