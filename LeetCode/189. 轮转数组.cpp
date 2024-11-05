/**
 * @file 189. 轮转数组.cpp
 * @author han yi (brokensnow2@gmail.com)
 * @brief 给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
 * 输入: nums = [1,2,3,4,5,6,7], k = 3
 * 输出: [5,6,7,1,2,3,4]
 * 解释:
 * 向右轮转 1 步: [7,1,2,3,4,5,6]
 * 向右轮转 2 步: [6,7,1,2,3,4,5]
 * 向右轮转 3 步: [5,6,7,1,2,3,4]
 * 
 * 解题思路：
 * 类似于王道数据结构的一题：
 * 先转置前n-k个，再转置后k个，最后转置整个数组。
 * [1, 2, 3, 4, 5, 6, 7] -> [4, 3, 2, 1, 5, 6, 7] -> [4, 3, 2, 1, 7, 6, 5] -> [5, 6, 7, 1, 2, 3, 4]
 * 
 * 或者另一种等价的： --见代码
 * 时间复杂度：O(n) 空间复杂度：O(1)
 * @version 0.1
 * @date 2024-11-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

/* 解法2:


#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // 防止 k 大于数组长度
        vector<int> nums1(n);

        // 将每个元素放置到旋转后的位置
        for (int i = 0; i < n; i++) {
            nums1[(i + k) % n] = nums[i];
        }

        // 将辅助数组的结果复制回原数组
        nums = nums1;
    }
};

*/