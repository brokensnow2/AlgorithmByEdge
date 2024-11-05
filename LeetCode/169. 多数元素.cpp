/**
 * @brief "Boyser-Moore 投票算法"：维护一个候选元素和一个计数器。
 * 遍历数组时，如果计数器为 0，则将当前元素作为新的候选元素，并重置计数器。
 * 如果当前元素与候选元素相同，则增加计数器；否则，减少计数器。最终，候选元素即为多数元素。
 * 这个算法的时间复杂度为 O(n)，空间复杂度为 O(1)
 * 
 */
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * Given an array of size n, find the majority element. The majority element is the element that appears more than n/2 times.
     * You may assume that the array is non-empty and the majority element always exist in the array.
     *
     * @param nums an array of integers
     * @return the majority element
     */
    int majorityElement(vector<int>& nums) {
        int res = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (cnt == 0) {
                res = nums[i];
                cnt = 1;
            } else if (nums[i] == res) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return res;
    }
};